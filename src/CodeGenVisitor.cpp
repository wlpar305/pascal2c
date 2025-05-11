#include "CodeGenVisitor.h"
#include "Exception/SemanticException.h"
#include "PascalSParser.h"
#include "StandardProcedure.h"
#include "llvm/IR/DerivedTypes.h"
#include <cstdarg>
#include <filesystem>

CodeGenVisitor::CodeGenVisitor()
    : builder(context) {
    global_scope = new Scope();
    current_scope = new Scope(global_scope);
    for (const auto& [name, prototype] : StandardProcedure::prototypeMap) {
        current_scope->put(name, nullptr);
    }
}

CodeGenVisitor::CodeGenVisitor(const std::string& filename)
    : builder(context)
    , filename(filename) {
    global_scope = new Scope();
    current_scope = new Scope(global_scope);
    for (const auto& [name, prototype] : StandardProcedure::prototypeMap) {
        current_scope->put(name, nullptr);
    }
}

CodeGenVisitor::~CodeGenVisitor() {
    delete global_scope;
    delete current_scope;
}

antlrcpp::Any CodeGenVisitor::visitProgramHead(PascalSParser::ProgramHeadContext* ctx) {
    std::filesystem::path filePath(filename);
    std::string program_file_name = filePath.stem().string();
    module = std::make_unique<Module>(program_file_name, context);

    llvm::FunctionType* main_func_type = llvm::FunctionType::get(Type::getInt32Ty(context), false);
    llvm::Function* main_func = llvm::Function::Create(main_func_type, llvm::Function::ExternalLinkage, "main", module.get());
    llvm::BasicBlock* main_entry = llvm::BasicBlock::Create(context, "mainEntry", main_func);

    builder.SetInsertPoint(main_entry);

    if (ctx->identifierList()) {
        auto identifier_list_any = visit(ctx->identifierList());
        if (identifier_list_any.has_value()) {
             try {
                auto identifiers = std::any_cast<std::vector<std::string>>(identifier_list_any);
                for (const auto& identifier : identifiers) {
                    global_scope->put(identifier, nullptr);
                }
            } catch (const std::bad_any_cast& e) {

            }
        }
    } else {
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitProgramBody(PascalSParser::ProgramBodyContext* ctx) {
    auto res = visitChildren(ctx);
    
    // 检查当前函数的返回类型
    Function* currentFunction = builder.GetInsertBlock()->getParent();
    Type* returnType = currentFunction->getReturnType();
    
    // 如果函数返回类型是 void，使用 CreateRetVoid
    if (returnType->isVoidTy()) {
        builder.CreateRetVoid();
    } else {
        // 处理非 void 返回类型
        if (current_return_value != nullptr) {
            if (isa<AllocaInst>(current_return_value)) {
                auto return_type = ((AllocaInst*)current_return_value)->getAllocatedType();
                current_return_value = builder.CreateLoad(return_type, current_return_value);
                
                // 确保返回值是正确类型
                if (current_return_value->getType()->isIntegerTy() && 
                    !current_return_value->getType()->isIntegerTy(32) && 
                    returnType->isIntegerTy(32)) {
                    current_return_value = builder.CreateIntCast(
                        current_return_value, builder.getInt32Ty(), true, "return_to_i32");
                }
                // 处理浮点类型返回值
                else if (current_return_value->getType()->isIntegerTy() && returnType->isFloatTy()) {
                    current_return_value = builder.CreateSIToFP(
                        current_return_value, returnType, "int_to_float_return");
                }
                // 反之也要处理
                else if (current_return_value->getType()->isFloatTy() && returnType->isIntegerTy()) {
                    current_return_value = builder.CreateFPToSI(
                        current_return_value, returnType, "float_to_int_return");
                }
            } else {
                // 对于非局部变量的返回值处理
                if (current_return_value->getType()->isIntegerTy() && 
                    !current_return_value->getType()->isIntegerTy(32) && 
                    returnType->isIntegerTy(32)) {
                    current_return_value = builder.CreateIntCast(
                        current_return_value, builder.getInt32Ty(), true, "return_to_i32");
                }
                // 处理浮点类型返回值
                else if (current_return_value->getType()->isIntegerTy() && returnType->isFloatTy()) {
                    current_return_value = builder.CreateSIToFP(
                        current_return_value, returnType, "int_to_float_return");
                }
                // 反之也要处理
                else if (current_return_value->getType()->isFloatTy() && returnType->isIntegerTy()) {
                    current_return_value = builder.CreateFPToSI(
                        current_return_value, returnType, "float_to_int_return");
                }
            }
        } else {
            // 如果没有设置返回值，默认返回0
            if (returnType->isIntegerTy()) {
                current_return_value = ConstantInt::get(context, APInt(returnType->getIntegerBitWidth(), 0));
            } else if (returnType->isFloatTy()) {
                current_return_value = ConstantFP::get(context, APFloat(0.0f));
            } else {
                current_return_value = ConstantInt::get(context, APInt(32, 0));
            }
        }
        
        builder.CreateRet(current_return_value);
    }
    
    return res;
}

antlrcpp::Any CodeGenVisitor::visitConstDeclaration(PascalSParser::ConstDeclarationContext* ctx) {
    if (ctx->constDeclaration() != nullptr) {
        visit(ctx->constDeclaration());
    }

    std::string identifier = ctx->ID()->getText();
    llvm::Value* value = std::any_cast<llvm::Value*>(visit(ctx->constVariable()));
    
    // 确保value是一个常量
    if (!isa<Constant>(value)) {
        // 如果不是常量，尝试转换为常量
        if (value->getType()->isFloatTy()) {
            // 尝试从浮点数值创建常量
            if (auto *constExpr = dyn_cast<ConstantExpr>(value)) {
                value = constExpr;
            } else {
                // 无法获取常量值，使用0.0作为默认值
                value = ConstantFP::get(Type::getFloatTy(context), APFloat(0.0));
            }
        } else if (value->getType()->isIntegerTy()) {
            // 尝试从整数值创建常量
            if (auto *constExpr = dyn_cast<ConstantExpr>(value)) {
                value = constExpr;
            } else {
                // 无法获取常量值，使用0作为默认值
                value = ConstantInt::get(value->getType(), 0);
            }
        }
    }

    module->getOrInsertGlobal(identifier, value->getType());
    llvm::GlobalVariable* global = module->getNamedGlobal(identifier);
    global->setInitializer(dyn_cast<Constant>(value));
    global->setConstant(true);

    global_scope->put(identifier, global);

    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitConstVariable(PascalSParser::ConstVariableContext* ctx) {
    llvm::Value* value = nullptr;

    if (ctx->ID() != nullptr) {
        std::string identifier = ctx->ID()->getText();
        auto global = module->getNamedGlobal(identifier);

        if (global == nullptr) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "identifier(96) " + identifier + "' was not declared in this scope");
        } else {
            value = (llvm::ConstantInt*)global->getInitializer();
        }
    }

    if (ctx->NUM() != nullptr) {
        bool negative = ctx->MINUS() != nullptr;

        std::string num_str = ctx->NUM()->getText();
        if (num_str.find('.') != std::string::npos || num_str.find('E') != std::string::npos || num_str.find('e') != std::string::npos) {
            // 处理浮点数
            double num = std::stod(num_str);
            if (negative) {
                num = -num; // 直接在数值上应用负号
            }
            // 统一使用double类型
            value = ConstantFP::get(Type::getDoubleTy(context), num);
        } else {
            // 处理整数
            int num = std::stoi(num_str);
            if (negative) {
                num = -num; // 直接在数值上应用负号
            }
            value = ConstantInt::get(context, APInt(32, static_cast<uint64_t>(num), true));
        }
    }

    if (ctx->CHARLITERAL() != nullptr) {
        char letter = ctx->CHARLITERAL()->getText()[1];
        value = ConstantInt::get(context, APInt(8, letter));
    }

    return value;
}

antlrcpp::Any CodeGenVisitor::visitTypeDeclaration(PascalSParser::TypeDeclarationContext* ctx) {
    if (ctx->typeDeclaration() != nullptr) {
        visit(ctx->typeDeclaration());
    }

    std::string identifier = ctx->ID()->getText();
    llvm::Type* type = std::any_cast<llvm::Type*>(visit(ctx->type()));

    llvm::StructType* type_struct = llvm::StructType::create(context, "type_" + identifier);
    type_struct->setBody(type);
    auto addr = builder.CreateAlloca(type_struct, nullptr, identifier);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitVarDeclarations(PascalSParser::VarDeclarationsContext* ctx) {
    if (ctx->varDeclaration() != nullptr) {
        auto var_declarations = std::any_cast<std::map<std::string, llvm::Type*>>(visit(ctx->varDeclaration()));

        for (const auto& var_declaration : var_declarations) {
            if (current_scope->declared(var_declaration.first) && function_name_stack.empty()) {
                throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                    "identifier '" + var_declaration.first + "' was already declared in this scope");
            }

            std::string identifier = var_declaration.first;
            llvm::Type* type = var_declaration.second;
            
            // 确保整数类型变量使用int32类型
            if (type->isIntegerTy() && !type->isIntegerTy(32) && !type->isIntegerTy(1)) {
                type = Type::getInt32Ty(context);
            }

            if (function_name_stack.empty()) {
                llvm::GlobalVariable* gv = new llvm::GlobalVariable(
                    *module,
                    type,
                    false,
                    llvm::GlobalValue::CommonLinkage,
                    llvm::Constant::getNullValue(type),
                    identifier
                );
                global_scope->put(identifier, gv);
            } else {
                auto alloca = builder.CreateAlloca(type, nullptr, identifier);
                current_scope->put(identifier, alloca);
            }
        }
    }

    return nullptr;
}


antlrcpp::Any CodeGenVisitor::visitVarDeclaration(PascalSParser::VarDeclarationContext* ctx) {
    std::map<std::string, llvm::Type*> var_declarations;
    if (ctx->varDeclaration() != nullptr) {
        auto prev_var_declarations = std::any_cast<std::map<std::string, llvm::Type*>>(visit(ctx->varDeclaration()));
        var_declarations.insert(prev_var_declarations.begin(), prev_var_declarations.end());
    }

    auto identifiers = std::any_cast<std::vector<std::string>>(visit(ctx->identifierList()));
    auto type = std::any_cast<llvm::Type*>(visit(ctx->type()));

    for (const auto& identifier : identifiers) {
        if (var_declarations.find(identifier) != var_declarations.end()) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "identifier '" + identifier + "' was already declared in this scope");
        }

        var_declarations[identifier] = type;
    }

    return var_declarations;
}


antlrcpp::Any CodeGenVisitor::visitIdentifierList(PascalSParser::IdentifierListContext* ctx) {
    std::vector<std::string> identifiers;
    std::string identifier = ctx->ID()->getText();
    identifiers.push_back(identifier);

    if (ctx->identifierList() != nullptr) {
        auto next_identifiers = std::any_cast<std::vector<std::string>>(visit(ctx->identifierList()));
        identifiers.insert(identifiers.begin(), next_identifiers.begin(), next_identifiers.end());
    }

    return identifiers;
}


antlrcpp::Any CodeGenVisitor::visitType(PascalSParser::TypeContext* ctx) {
    llvm::Type* type = nullptr;
    if (ctx->standardType() != nullptr) {
        type = std::any_cast<llvm::Type*>(visit(ctx->standardType()));
    } else if (ctx->recordBody() != nullptr) {
        auto record_body = std::any_cast<std::map<std::string, llvm::Type*>>(visit(ctx->recordBody()));

        std::map<std::string, int> record_names;
        std::vector<llvm::Type*> record_types;
        int idx = 0;
        for (const auto& record : record_body) {
            record_names.insert({ record.first, idx++ });
            record_types.push_back(record.second);
        }

        type = llvm::StructType::get(context, record_types);

        current_scope->putRecord(type, record_names);
    } else if (ctx->ARRAY() != nullptr) {
        auto array_type_content = std::any_cast<llvm::Type*>(visit(ctx->type()));
        auto array_period = std::any_cast<std::vector<std::pair<int, int>>>(visit(ctx->periods()));

        // 从最内层维度开始创建数组类型
        llvm::Type* final_array_type = array_type_content;
        for (auto period = array_period.rbegin(); period != array_period.rend(); ++period) {
            int start = period->first;
            int end = period->second;
            int size = end - start + 1;
            
            final_array_type = ArrayType::get(final_array_type, size);
        }

        type = final_array_type;

        // 在全局作用域下声明的数组，同时在全局作用域和当前作用域中保存数组信息
        if (function_name_stack.empty()) {
            global_scope->putArray(type, array_period);
        }
        
        current_scope->putArray(type, array_period);
    }

    return type;
}


antlrcpp::Any CodeGenVisitor::visitPeriods(PascalSParser::PeriodsContext* ctx) {
    std::vector<std::pair<int, int>> periods;
    if (ctx->periods() != nullptr) {
        auto next_periods = std::any_cast<std::vector<std::pair<int, int>>>(visit(ctx->periods()));
        periods.insert(periods.begin(), next_periods.begin(), next_periods.end());
    }

    auto period = std::any_cast<std::pair<int, int>>(visit(ctx->period()));
    periods.push_back(period);
    
    return periods;
}


antlrcpp::Any CodeGenVisitor::visitPeriod(PascalSParser::PeriodContext* ctx) {
    auto start_const = (llvm::Constant*)std::any_cast<llvm::Value*>(visit(ctx->constVariable(0)));
    auto end_const = (llvm::Constant*)std::any_cast<llvm::Value*>(visit(ctx->constVariable(1)));
    int start = start_const->getUniqueInteger().getLimitedValue();
    int end = end_const->getUniqueInteger().getLimitedValue();
    
    return std::make_pair(start, end);
}

// @return llvm::Type*
antlrcpp::Any CodeGenVisitor::visitStandardType(PascalSParser::StandardTypeContext* ctx) {
    llvm::Type* type = nullptr;
    if (ctx->INTEGER() != nullptr) {
        type = Type::getInt32Ty(context);
    } else if (ctx->BOOLEAN() != nullptr) {
        type = Type::getInt1Ty(context);
    } else if (ctx->REAL() != nullptr) {
        type = Type::getFloatTy(context);
    } else if (ctx->CHAR() != nullptr) {
        type = Type::getInt8Ty(context);
    } else {
        type = Type::getVoidTy(context);
    }

    return type;
}

antlrcpp::Any CodeGenVisitor::visitIfStatement(PascalSParser::IfStatementContext* ctx) {
    llvm::Value* condition = std::any_cast<llvm::Value*>(visit(ctx->expression()));
    condition = loadIfPointer(condition);

    if (!condition->getType()->isIntegerTy(1)) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "if statement condition must be of type boolean");
    }


    llvm::Function* parentFunction = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "then", parentFunction);
    llvm::BasicBlock* elseBB;


    if (ctx->elsePart()->ELSE() != nullptr) {
        elseBB = llvm::BasicBlock::Create(context, "bb_else", parentFunction);
    }

    llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "endif", parentFunction);

    if (ctx->elsePart()->ELSE() != nullptr) {
        builder.CreateCondBr(condition, thenBB, elseBB);
    } else {
        builder.CreateCondBr(condition, thenBB, mergeBB);
    }


    builder.SetInsertPoint(thenBB);
    visit(ctx->statement());

    builder.CreateBr(mergeBB);


    if (ctx->elsePart()->ELSE() != nullptr) {

        builder.SetInsertPoint(elseBB);
        visit(ctx->elsePart()->statement()); 
        builder.CreateBr(mergeBB);
        elseBB = builder.GetInsertBlock(); 
    }

    builder.SetInsertPoint(mergeBB);

    return nullptr; 
}

antlrcpp::Any CodeGenVisitor::visitForStatement(PascalSParser::ForStatementContext* ctx) {
    std::string loopVar = ctx->ID()->getText();

    Value* initValue = std::any_cast<llvm::Value*>(visit(ctx->expression(0)));
    initValue = loadIfPointer(initValue);

    Value* finalValue = std::any_cast<llvm::Value*>(visit(ctx->expression(1)));
    finalValue = loadIfPointer(finalValue);

    // 如果初始值不是整数类型，尝试转换
    if (!initValue->getType()->isIntegerTy(32)) {
        if (initValue->getType()->isIntegerTy()) {
            // 其他整数类型（如int1, int8等）转换为int32
            initValue = builder.CreateIntCast(initValue, builder.getInt32Ty(), true, "to.i32");
        } else {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "for loop initial value must be of type integer");
        }
    }
    
    // 如果结束值不是整数类型，尝试转换
    if (!finalValue->getType()->isIntegerTy(32)) {
        if (finalValue->getType()->isIntegerTy()) {
            // 其他整数类型转换为int32
            finalValue = builder.CreateIntCast(finalValue, builder.getInt32Ty(), true, "to.i32");
        } else {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "for loop final value must be of type integer");
        }
    }

    bool countUp = ctx->updown()->DOWNTO() == nullptr;

    Function* function = builder.GetInsertBlock()->getParent();
    BasicBlock* preheaderBB = builder.GetInsertBlock();
    BasicBlock* loopBB = BasicBlock::Create(context, "loop", function);
    BasicBlock* afterBB = BasicBlock::Create(context, "afterloop", function);

    Value* variable = current_scope->get(loopVar);
    if (!variable) {
        // 如果在当前作用域找不到变量，尝试在全局作用域查找
        variable = global_scope->get(loopVar);
        if (!variable) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "variable '" + loopVar + "' was not declared in this scope");
        }
    }

    Type* varType = nullptr;
    
    // 检查变量类型，支持AllocaInst和GlobalVariable
    if (auto *allocaInst = dyn_cast<AllocaInst>(variable)) {
        varType = allocaInst->getAllocatedType();
    } else if (auto *globalVar = dyn_cast<GlobalVariable>(variable)) {
        varType = globalVar->getValueType();
    }

    // 检查循环变量是否为整数类型
    if (!varType || !varType->isIntegerTy()) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "for loop variable must be of type integer");
    }

    // 存储初始值到循环变量
    builder.CreateStore(initValue, variable);

    builder.CreateBr(loopBB);

    builder.SetInsertPoint(loopBB);

    visit(ctx->statement());

    Value* currentVar = builder.CreateLoad(builder.getInt32Ty(), variable, loopVar);
    Value* nextVar = countUp ? builder.CreateAdd(currentVar, ConstantInt::get(context, APInt(32, 1)), "nextvar") : builder.CreateSub(currentVar, ConstantInt::get(context, APInt(32, 1)), "nextvar");
    builder.CreateStore(nextVar, variable);

    Value* endCond = countUp ? builder.CreateICmpSLE(nextVar, finalValue, "loopcond") : builder.CreateICmpSGE(nextVar, finalValue, "loopcond");

    builder.CreateCondBr(endCond, loopBB, afterBB);

    builder.SetInsertPoint(afterBB);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitWhileStatement(PascalSParser::WhileStatementContext* ctx) {
    Function* function = builder.GetInsertBlock()->getParent();

    BasicBlock* conditionBB = BasicBlock::Create(context, "while_cond", function);
    BasicBlock* loopBB = BasicBlock::Create(context, "while_body", function);
    BasicBlock* afterBB = BasicBlock::Create(context, "while_end", function);

    builder.CreateBr(conditionBB);
    builder.SetInsertPoint(conditionBB);

    Value* condition = std::any_cast<llvm::Value*>(visit(ctx->expression()));
    condition = loadIfPointer(condition);

    if (!condition->getType()->isIntegerTy(1)) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "while statement condition must be of type boolean");
    }

    builder.CreateCondBr(condition, loopBB, afterBB);

    builder.SetInsertPoint(loopBB);
    visit(ctx->statement());

    builder.CreateBr(conditionBB);

    builder.SetInsertPoint(afterBB);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitRepeatStatement(PascalSParser::RepeatStatementContext* ctx) {
    llvm::Function* function = builder.GetInsertBlock()->getParent();

    // 生成基本块
    llvm::BasicBlock* loopBB = llvm::BasicBlock::Create(context, "repeat_body", function);
    llvm::BasicBlock* conditionBB = llvm::BasicBlock::Create(context, "repeat_cond", function);
    llvm::BasicBlock* afterBB = llvm::BasicBlock::Create(context, "repeat_end", function);

    builder.CreateBr(loopBB);

    builder.SetInsertPoint(loopBB);

    // 遍历statementList
    visit(ctx->statementList());

    builder.CreateBr(conditionBB);

    builder.SetInsertPoint(conditionBB);

    Value* conditionValue = std::any_cast<llvm::Value*>(visit(ctx->expression()));
    conditionValue = loadIfPointer(conditionValue);

    if (!conditionValue->getType()->isIntegerTy(1)) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "repeat statement condition must be of type boolean");
    }

    builder.CreateCondBr(conditionValue, afterBB, loopBB);

    builder.SetInsertPoint(afterBB);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitStatementList(PascalSParser::StatementListContext* ctx) {
    if (ctx->statementList() != nullptr) {
        visit(ctx->statementList());
        visit(ctx->statement());
    } else {
        visit(ctx->statement());
    }
    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitCaseStatement(PascalSParser::CaseStatementContext* ctx) {
    // 获取当前的函数
    Function* function = builder.GetInsertBlock()->getParent();
    BasicBlock* switchBB = BasicBlock::Create(context, "switchBB", function);

    // 访问 case 的表达式，获取其值
    Value* caseValue = std::any_cast<llvm::Value*>(visit(ctx->expression()));
    caseValue = loadIfPointer(caseValue);

    // 类型检查
    if (caseValue->getType()->isFloatTy()) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "case statement expression can not be of type real");
    }

    // 开始switch语句
    builder.CreateBr(switchBB);
    builder.SetInsertPoint(switchBB);
    SwitchInst* switchInst = builder.CreateSwitch(caseValue, nullptr);

    BasicBlock* afterCaseBB = BasicBlock::Create(context, "case_end", function);

    current_loop_end = afterCaseBB;

    // 访问 case 的分支列表
    auto branches = std::any_cast<std::vector<std::pair<std::vector<llvm::Value*>, llvm::BasicBlock*>>>(visit(ctx->caseBody()->branchList()));

    // 遍历所有的分支
    for (auto branch : branches) {
        // 获取分支的常量值
        std::vector<llvm::Value*> constValues = branch.first;

        // 创建基本块，用于在匹配到合适的分支之后跳转到该分支执行代码
        BasicBlock* caseBB = branch.second;

        // 遍历所有的常量值
        for (auto constValue : constValues) {
            // 添加分支
            switchInst->addCase(cast<ConstantInt>(constValue), caseBB);
        }
    }

    // default跳转afterCaseBB
    switchInst->setDefaultDest(afterCaseBB);

    // 设置 IRBuilder 的插入点到 case 结束块，便于后续的指令生成
    builder.SetInsertPoint(afterCaseBB);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitConstList(PascalSParser::ConstListContext* ctx) {
    // 递归访问 constList，得到所有的常量，加入vector
    std::vector<llvm::Value*> constValues;
    constValues.push_back(std::any_cast<llvm::Value*>(visit(ctx->constVariable())));

    if (ctx->constList() != nullptr) {
        auto nextConstValues = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->constList()));
        constValues.insert(constValues.begin(), nextConstValues.begin(), nextConstValues.end());
    }

    return constValues;
}

antlrcpp::Any CodeGenVisitor::visitBranch(PascalSParser::BranchContext* ctx) {
    // 访问 constList，得到该分支的所有常量
    std::vector<llvm::Value*> constValues = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->constList()));

    // 类型检查
    for (auto value : constValues) {
        if (value->getType()->isFloatTy()) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "case statement expression can not be of type real");
        }
    }

    // 创建基本块，用于在匹配到合适的分支之后跳转到该分支执行代码
    Function* function = builder.GetInsertBlock()->getParent();
    BasicBlock* caseBB = BasicBlock::Create(context, "case_branch", function);
    builder.SetInsertPoint(caseBB);

    visit(ctx->statement());

    builder.CreateBr(current_loop_end);

    // 返回 pair：constValue -> statement
    return std::make_pair(constValues, caseBB);
}

antlrcpp::Any CodeGenVisitor::visitBranchList(PascalSParser::BranchListContext* ctx) {
    // 递归访问 branchList，得到所有的分支，加入vector
    std::vector<std::pair<std::vector<llvm::Value*>, llvm::BasicBlock*>> branches;

    if (ctx->branchList() != nullptr) {

        auto nextBranches = std::any_cast<std::vector<std::pair<std::vector<llvm::Value*>, llvm::BasicBlock*>>>(visit(ctx->branchList()));

        branches.insert(branches.begin(), nextBranches.begin(), nextBranches.end());
    }

    branches.push_back(std::any_cast<std::pair<std::vector<llvm::Value*>, llvm::BasicBlock*>>(visit(ctx->branch())));

    return branches;
}

antlrcpp::Any CodeGenVisitor::visitSubprogramDeclaration(PascalSParser::SubprogramDeclarationContext* ctx) {
    std::string subprogram_name = ctx->subprogramHead()->ID()->getText();
    if (global_scope->declared(subprogram_name) || current_scope->declared(subprogram_name)) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "identifier '" + subprogram_name + "' was already declared in this scope");
    }
    
    auto prev_insert_point = builder.saveIP();
    auto prev_return_value = current_return_value;
    auto prev_current_scope = current_scope;

    // 创建新的作用域，父级是当前作用域 (支持嵌套)
    Scope* new_current_scope = new Scope(current_scope);
    current_scope = new_current_scope;

    auto func = std::any_cast<llvm::Function*>(visit(ctx->subprogramHead()));
    prev_current_scope->put(subprogram_name, func);
    visit(ctx->programBody());

    if (!this->function_name_stack.empty()) {
        this->function_name_stack.pop_back();
    }
    
    current_scope = prev_current_scope;
    current_return_value = prev_return_value;
    builder.restoreIP(prev_insert_point);

    return nullptr;
}

antlrcpp::Any CodeGenVisitor::visitSubprogramHead(PascalSParser::SubprogramHeadContext* ctx) {
    std::string subprogram_name = ctx->ID()->getText();
    this->function_name_stack.push_back(subprogram_name);

    llvm::Type* return_type = nullptr;
    llvm::Value* return_value = nullptr;
    if (ctx->PROCEDURE() != nullptr) {
        return_type = llvm::Type::getVoidTy(context);
    } else if (ctx->FUNCTION() != nullptr) {
        return_type = std::any_cast<llvm::Type*>(visit(ctx->standardType()));
    } else {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "subprogram declaration must be either a function or a procedure");
    }

    std::vector<SubprogramParameter> param_lists;
    std::vector<llvm::Type*> param_types;
    std::set<std::string> param_names;

    if (ctx->formalParameter()->parameterLists() != nullptr) {
        param_lists = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->formalParameter()->parameterLists()));

        for (const auto& param : param_lists) {
            llvm::Type* param_type = param.type;

            if (param.is_var) {
                param_type = param_type->getPointerTo();
            }

            param_types.push_back(param_type);


            if (param_names.find(param.name) != param_names.end()) {
                throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                    "parameter '" + param.name + "' was already declared in this scope");
            }

            param_names.insert(param.name);
        }
    }

    llvm::FunctionType* subprogram_type = llvm::FunctionType::get(return_type, param_types, false);
    llvm::Function* subprogram = llvm::Function::Create(subprogram_type, llvm::Function::ExternalLinkage, subprogram_name, module.get());
    llvm::BasicBlock* subprogram_entry = llvm::BasicBlock::Create(context, subprogram_name + "Entry", subprogram);

    current_return_value = return_value;
    builder.SetInsertPoint(subprogram_entry);

    int idx = 0;
    for (auto& arg : subprogram->args()) {
        arg.setName(param_lists[idx].name);

        if (param_lists[idx].is_var) {
            current_scope->put(param_lists[idx].name, &arg);
        } else {
            auto alloca = builder.CreateAlloca(param_lists[idx].type, nullptr, param_lists[idx].name);
            builder.CreateStore(&arg, alloca);
            current_scope->put(param_lists[idx].name, alloca);
        }

        idx++;
    }

    if (ctx->FUNCTION()) {
        // 函数返回值分配，保证是int32类型
        if (return_type->isIntegerTy() && !return_type->isIntegerTy(32)) {
            return_type = Type::getInt32Ty(context);
        }
        
        // 创建返回值变量
        return_value = builder.CreateAlloca(return_type, nullptr, subprogram_name + "_return_value");
        
        // 将函数名关联到返回值变量
        current_scope->put(subprogram_name, return_value);
        current_return_value = return_value;
    }

    return subprogram;
}

antlrcpp::Any CodeGenVisitor::visitParameterLists(PascalSParser::ParameterListsContext* ctx) {
    std::vector<SubprogramParameter> param_lists;
    if (ctx->parameterLists() != nullptr) {
        auto prev_param_lists = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->parameterLists()));
        param_lists.insert(param_lists.begin(), prev_param_lists.begin(), prev_param_lists.end());
    }

    auto param_list = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->parameterList()));
    param_lists.insert(param_lists.end(), param_list.begin(), param_list.end());

    return param_lists;
}

antlrcpp::Any CodeGenVisitor::visitParameterList(PascalSParser::ParameterListContext* ctx) {
    std::vector<SubprogramParameter> param_list;

    if (ctx->varParameter() != nullptr) {
        param_list = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->varParameter()));
    } else if (ctx->valueParameter() != nullptr) {
        param_list = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->valueParameter()));
    } else {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "parameter list must be either a value or var parameter");
    }

    return param_list;
}

antlrcpp::Any CodeGenVisitor::visitVarParameter(PascalSParser::VarParameterContext* ctx) {
    auto param_list = std::any_cast<std::vector<SubprogramParameter>>(visit(ctx->valueParameter()));

    for (auto& param : param_list) {
        param.is_var = true;
    }

    return param_list;
}

antlrcpp::Any CodeGenVisitor::visitValueParameter(PascalSParser::ValueParameterContext* ctx) {
    std::vector<std::string> identifiers = std::any_cast<std::vector<std::string>>(visit(ctx->identifierList()));
    llvm::Type* type = std::any_cast<llvm::Type*>(visit(ctx->standardType()));

    std::vector<SubprogramParameter> params;
    for (const auto& identifier : identifiers) {
        params.push_back({ identifier, type, false });
    }

    return params;
}

antlrcpp::Any CodeGenVisitor::visitExpression(PascalSParser::ExpressionContext* ctx) {
    llvm::Value* value = nullptr;
    if (ctx->relationalOpreator()) {
        llvm::Value* lhs = std::any_cast<llvm::Value*>(visit(ctx->simpleExpression(0)));
        llvm::Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->simpleExpression(1)));
        auto op = ctx->relationalOpreator();

        lhs = loadIfPointer(lhs);
        rhs = loadIfPointer(rhs);

        std::vector<llvm::Value*> converted_values = castBinary(lhs, rhs);
        lhs = converted_values[0];
        rhs = converted_values[1];

        if (op->EQUAL() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpOEQ(lhs, rhs, "eqtmp");
            } else {
                value = builder.CreateICmpEQ(lhs, rhs, "eqtmp");
            }
        } else if (op->NEQUAL() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpONE(lhs, rhs, "netmp");
            } else {
                value = builder.CreateICmpNE(lhs, rhs, "netmp");
            }
        } else if (op->LT() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpOLT(lhs, rhs, "lttmp");
            } else {
                value = builder.CreateICmpSLT(lhs, rhs, "lttmp");
            }
        } else if (op->LE() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpOLE(lhs, rhs, "letmp");
            } else {
                value = builder.CreateICmpSLE(lhs, rhs, "letmp");
            }
        } else if (op->GT() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpOGT(lhs, rhs, "gttmp");
            } else {
                value = builder.CreateICmpSGT(lhs, rhs, "gttmp");
            }
        } else if (op->GE() != nullptr) {
            if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                value = builder.CreateFCmpOGE(lhs, rhs, "getmp");
            } else {
                value = builder.CreateICmpSGE(lhs, rhs, "getmp");
            }
        }
    } else {
        value = std::any_cast<llvm::Value*>(visit(ctx->simpleExpression(0)));
    }

    return value;
}

antlrcpp::Any CodeGenVisitor::visitUnsignConstLiteral(PascalSParser::UnsignConstLiteralContext* ctx) {
    // return: llvm::Value*
    Value* value = nullptr;
    //
    if (ctx->NUM()) {
        // 处理NUM
        std::string num_str = ctx->NUM()->getText();
        if (num_str.find('.') != std::string::npos || num_str.find('E') != std::string::npos || num_str.find('e') != std::string::npos) {
            // 使用Double类型代替Float类型
            double num = std::stod(num_str);
            value = ConstantFP::get(Type::getDoubleTy(context), num);
        } else {
            int num = std::stoi(num_str);
            value = ConstantInt::get(context, llvm::APInt(32, num));
        }
    } else if (ctx->CHARLITERAL()) {
        // 获取 CHARLITERAL 的文本值
        std::string charLiteral = ctx->CHARLITERAL()->getText();
        // 提取字符值（去掉引号）
        char charValue = charLiteral[1];
        // 创建一个 8 位的常量整数值
        value = llvm::ConstantInt::get(context, llvm::APInt(8, charValue));
    }
    //
    return value;
}

antlrcpp::Any CodeGenVisitor::visitFactor(PascalSParser::FactorContext* ctx) {
    Value* value = nullptr;
    if (ctx->unsignConstLiteral()) {
        value = std::any_cast<llvm::Value*>(visit(ctx->unsignConstLiteral()));
    } else if (ctx->variable()) {
        PascalSParser::VariableContext* varCtx = ctx->variable();
        bool isSimpleID = varCtx->ID() != nullptr && (varCtx->idVarparts() == nullptr || varCtx->idVarparts()->children.empty());
        std::string idName = "";

        if (isSimpleID) {
            idName = varCtx->ID()->getText();
            Value* func_lookup_result = current_scope->get(idName);

            // 检查是否为无参数的函数，如果是，则调用它
            if (func_lookup_result != nullptr && llvm::isa<Function>(func_lookup_result)) {
                Function* func = llvm::cast<Function>(func_lookup_result);
                if (!func->getReturnType()->isVoidTy() && func->getFunctionType()->getNumParams() == 0) {
                    std::vector<Value*> args; 
                    checkFunctionArgs(idName, func, args);
                    value = builder.CreateCall(func, args, idName + "_implicit_call");
                    
                    // 确保返回值是正确类型
                    if (value->getType()->isIntegerTy() && !value->getType()->isIntegerTy(32)) {
                        value = builder.CreateIntCast(value, builder.getInt32Ty(), true, "func_ret_to_i32");
                    }
                } else {
                    // 这是一个函数，但要么是过程，要么需要参数。当作变量处理
                    value = std::any_cast<llvm::Value*>(visit(ctx->variable()));
                }
            } else {
                // 不是作为函数找到的，或者不是函数。当作变量处理
                value = std::any_cast<llvm::Value*>(visit(ctx->variable()));
            }
        } else {
            // 不是简单ID（例如，数组访问或记录字段）。当作变量处理
            value = std::any_cast<llvm::Value*>(visit(ctx->variable()));
        }
    } else if (ctx->ID() && ctx->LPAREN() && ctx->expressionList() && ctx->RPAREN()) {
        std::string func_name = ctx->ID()->getText();
        Value* symbol = current_scope->get(func_name);
        
        // 如果在当前作用域找不到，尝试在全局作用域查找
        if (symbol == nullptr) {
            symbol = global_scope->get(func_name);
        }

        if (symbol == nullptr) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "identifier(859) '" + func_name + "' was not declared in this scope");
        } else {
            // 检查是否是函数本身或函数返回值变量
            if (llvm::isa<Function>(symbol)) {
                // 是函数类型，直接使用
                Function* func = llvm::cast<Function>(symbol);
                
                if (func->getReturnType()->isVoidTy()) {
                    throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                        "procedure '" + func_name + "' cannot be used in an expression");
                }
                
                // 修改点：先获取所有参数并预先计算
                std::vector<Value*> args;
                args = std::any_cast<std::vector<Value*>>(visit(ctx->expressionList()));
                
                // 对于有大量参数的函数，特别是递归调用，先预先计算并存储所有参数值
                if (args.size() > 16) {
                    std::vector<AllocaInst*> tempVars;
                    std::vector<Value*> computedArgs;
                    
                    for (size_t i = 0; i < args.size(); i++) {
                        // 加载并计算参数值
                        Value* argValue = loadIfPointer(args[i]);
                        Type* argType = argValue->getType();
                        
                        // 为参数创建临时变量并存储计算结果
                        AllocaInst* tempVar = builder.CreateAlloca(argType, nullptr, "temp_arg_" + std::to_string(i));
                        builder.CreateStore(argValue, tempVar);
                        tempVars.push_back(tempVar);
                        
                        // 将临时变量加入到计算好的参数列表
                        computedArgs.push_back(builder.CreateLoad(argType, tempVar));
                    }
                    
                    // 用预先计算好的参数值替换原始参数列表
                    args = computedArgs;
                }
                
                checkFunctionArgs(func_name, func, args);

                value = builder.CreateCall(func, args, "calltmp");
                
                // 确保返回值是正确类型
                if (value->getType()->isIntegerTy() && !value->getType()->isIntegerTy(32)) {
                    value = builder.CreateIntCast(value, builder.getInt32Ty(), true, "func_call_ret_to_i32");
                }
            } else if (!function_name_stack.empty() && func_name == function_name_stack.back() && current_return_value != nullptr) {
                // 当前是在函数内部，且使用的是本函数的名称
                // 需要查找实际的函数定义
                Function* currentFunc = builder.GetInsertBlock()->getParent();
                
                // 修改点：先获取所有参数并预先计算
                std::vector<Value*> args;
                args = std::any_cast<std::vector<Value*>>(visit(ctx->expressionList()));
                
                // 对于有大量参数的函数，特别是递归调用，先预先计算并存储所有参数值
                if (args.size() > 16) {
                    std::vector<AllocaInst*> tempVars;
                    std::vector<Value*> computedArgs;
                    
                    for (size_t i = 0; i < args.size(); i++) {
                        // 加载并计算参数值
                        Value* argValue = loadIfPointer(args[i]);
                        Type* argType = argValue->getType();
                        
                        // 为参数创建临时变量并存储计算结果
                        AllocaInst* tempVar = builder.CreateAlloca(argType, nullptr, "temp_arg_" + std::to_string(i));
                        builder.CreateStore(argValue, tempVar);
                        tempVars.push_back(tempVar);
                        
                        // 将临时变量加入到计算好的参数列表
                        computedArgs.push_back(builder.CreateLoad(argType, tempVar));
                    }
                    
                    // 用预先计算好的参数值替换原始参数列表
                    args = computedArgs;
                }
                
                checkFunctionArgs(func_name, currentFunc, args);
                
                value = builder.CreateCall(currentFunc, args, "recursive_call");
                
                // 确保返回值是正确类型
                if (value->getType()->isIntegerTy() && !value->getType()->isIntegerTy(32)) {
                    value = builder.CreateIntCast(value, builder.getInt32Ty(), true, "func_call_ret_to_i32");
                }
            } else {
                throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                    "'" + func_name + "' is not a function");
            }
        }
    } else if (ctx->ID() && ctx->LPAREN() && ctx->RPAREN()) {
        std::string func_name = ctx->ID()->getText();
        Value* symbol = current_scope->get(func_name);
        
        // 如果在当前作用域找不到，尝试在全局作用域查找
        if (symbol == nullptr) {
            symbol = global_scope->get(func_name);
        }

        if (symbol == nullptr) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "identifier(877) '" + func_name + "' was not declared in this scope (function call with no args)");
        } else {
            // 检查是否是函数本身或函数返回值变量
            if (llvm::isa<Function>(symbol)) {
                // 是函数类型，直接使用
                Function* func = llvm::cast<llvm::Function>(symbol);
                
                if (func->getReturnType()->isVoidTy()) {
                    throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                        "procedure '" + func_name + "' cannot be used in an expression (function call with no args)");
                }
                
                std::vector<Value*> args; // 空参数列表
                // 检查函数期望的参数个数是否为0
                checkFunctionArgs(func_name, func, args);
                value = builder.CreateCall(func, args, "calltmp");
                
                // 确保返回值是正确类型
                if (value->getType()->isIntegerTy() && !value->getType()->isIntegerTy(32)) {
                    value = builder.CreateIntCast(value, builder.getInt32Ty(), true, "func_call_no_arg_ret_to_i32");
                }
            } else if (!function_name_stack.empty() && func_name == function_name_stack.back() && current_return_value != nullptr) {
                // 当前是在函数内部，且使用的是本函数的名称
                // 需要查找实际的函数定义
                Function* currentFunc = builder.GetInsertBlock()->getParent();
                
                std::vector<Value*> args; // 空参数列表
                checkFunctionArgs(func_name, currentFunc, args);
                
                value = builder.CreateCall(currentFunc, args, "recursive_call_no_args");
                
                // 确保返回值是正确类型
                if (value->getType()->isIntegerTy() && !value->getType()->isIntegerTy(32)) {
                    value = builder.CreateIntCast(value, builder.getInt32Ty(), true, "func_call_no_arg_ret_to_i32");
                }
            } else {
                throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                    "'" + func_name + "' is not a function (function call with no args)");
            }
        }
    } else if (ctx->LPAREN() && ctx->expression() && ctx->RPAREN()) {
        value = std::any_cast<llvm::Value*>(visit(ctx->expression()));
    } else if (ctx->NOT() && ctx->factor()) {
        llvm::Value* factor_value = std::any_cast<llvm::Value*>(visit(ctx->factor()));
        factor_value = loadIfPointer(factor_value);
        
        // 检查操作数类型是否为布尔型或整型
        llvm::Type* type = factor_value->getType();
        if (type->isIntegerTy(1)) {
            // 布尔型取反
            value = builder.CreateNot(factor_value, "nottmp");
        } else if (type->isIntegerTy(32)) {
            // 整型按位取反
            value = builder.CreateNot(factor_value, "nottmp");
        } else {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "type mismatch in expression after NOT: Logical operators can only be applied to Int or Boolean types");
        }
    } else if (ctx->PLUS() && ctx->factor()) {
        // 处理一元加号
        llvm::Value* factor_value = std::any_cast<llvm::Value*>(visit(ctx->factor()));
        factor_value = loadIfPointer(factor_value);
        
        // 一元加号不改变值
        value = factor_value;
    } else if (ctx->MINUS() && ctx->factor()) {
        // 处理一元减号
        llvm::Value* factor_value = std::any_cast<llvm::Value*>(visit(ctx->factor()));
        factor_value = loadIfPointer(factor_value);
        
        // 根据类型选择合适的取负操作
        if (factor_value->getType()->isFloatTy()) {
            value = builder.CreateFNeg(factor_value, "uminus");
        } else if (factor_value->getType()->isIntegerTy()) {
            value = builder.CreateNeg(factor_value, "uminus");
        } else {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "type mismatch in expression after unary minus: Numeric type expected");
        }
    } else if (ctx->boolean()) {
        value = std::any_cast<llvm::Value*>(visit(ctx->boolean()));
    }
    return value;
}

antlrcpp::Any CodeGenVisitor::visitTerm(PascalSParser::TermContext* ctx) {
    Value* value = nullptr;
    if (ctx->multiplyOperator()) {
        Value* lhs = std::any_cast<llvm::Value*>(visit(ctx->term()));
        auto op = ctx->multiplyOperator();

        lhs = loadIfPointer(lhs);

        if (op->AND() != nullptr) {
            // 短路逻辑处理 - AND运算符
            checkType(lhs, "left-hand side of and expression");
            
            // 获取当前函数
            Function* function = builder.GetInsertBlock()->getParent();
            
            // 记录当前基本块，之后用于PHI节点
            BasicBlock* entryBlock = builder.GetInsertBlock();
            
            // 创建右表达式计算和合并的基本块
            BasicBlock* rhsBlock = BasicBlock::Create(context, "and.rhs", function);
            BasicBlock* mergeBlock = BasicBlock::Create(context, "and.merge", function);
            
            // 创建短路判断: 如果lhs为false(0)，直接跳到合并块，结果为false
            builder.CreateCondBr(lhs, rhsBlock, mergeBlock);
            
            // 右侧表达式块
            builder.SetInsertPoint(rhsBlock);
            Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->factor()));
            rhs = loadIfPointer(rhs);
            checkType(rhs, "right-hand side of and expression");
            
            BasicBlock* rhsEndBlock = builder.GetInsertBlock();
            builder.CreateBr(mergeBlock);
            
            // 合并块
            builder.SetInsertPoint(mergeBlock);
            PHINode* phi = builder.CreatePHI(Type::getInt1Ty(context), 2, "andtmp");
            phi->addIncoming(ConstantInt::getFalse(context), entryBlock); // lhs为false的入口
            phi->addIncoming(rhs, rhsEndBlock); // rhs计算结果
            
            value = phi;
        } else {
            // 其他乘法运算符无需短路逻辑
            Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->factor()));
            rhs = loadIfPointer(rhs);
            
            if (op->MULT() != nullptr) {
                std::vector<llvm::Value*> converted_values = castBinary(lhs, rhs);
                lhs = converted_values[0];
                rhs = converted_values[1];

                if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                    rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                    value = builder.CreateFMul(lhs, rhs, "multmp");
                } else {
                    value = builder.CreateMul(lhs, rhs, "multmp");
                }
            } else if (op->DIVIDE() != nullptr) {
                std::vector<llvm::Value*> converted_values = castBinary(lhs, rhs);
                lhs = converted_values[0];
                rhs = converted_values[1];

                llvm::Type* floatType = Type::getDoubleTy(context);

                // 无条件将两个操作数转换为浮点数
                if(!lhs->getType()->isDoubleTy()){
                    if(lhs->getType()->isIntegerTy()){
                        lhs = builder.CreateSIToFP(lhs, floatType, "lhs_to_double");
                    }
                    else if(lhs->getType()->isFloatTy()){
                        lhs = builder.CreateFPExt(lhs, floatType, "lhs_float_to_double");
                    }
                    else{
                        // 尝试最后的转换方法，如果不能成功转换，则使用0.0作为默认值
                        try {
                            // 对于不是整数的类型，尝试转换为浮点
                            lhs = builder.CreateBitCast(lhs, builder.getInt32Ty(), "lhs_bitcast");
                            lhs = builder.CreateSIToFP(lhs, floatType, "lhs_bitcast_to_double");
                        } catch (...) {
                            // 如果无法转换，使用0.0
                            lhs = ConstantFP::get(floatType, 0.0);
                        }
                    }
                }
                
                if(!rhs->getType()->isDoubleTy()){
                    if(rhs->getType()->isIntegerTy()){
                        rhs = builder.CreateSIToFP(rhs, floatType, "rhs_to_double");
                    }
                    else if(rhs->getType()->isFloatTy()){
                        rhs = builder.CreateFPExt(rhs, floatType, "rhs_float_to_double");
                    }
                    else{
                        // 尝试最后的转换方法，如果不能成功转换，则使用1.0作为默认值（避免除以0）
                        try {
                            // 对于不是整数的类型，尝试转换为浮点
                            rhs = builder.CreateBitCast(rhs, builder.getInt32Ty(), "rhs_bitcast");
                            rhs = builder.CreateSIToFP(rhs, floatType, "rhs_bitcast_to_double");
                        } catch (...) {
                            // 如果无法转换，使用1.0（避免除以0）
                            rhs = ConstantFP::get(floatType, 1.0);
                        }
                    }
                }
                
                value = builder.CreateFDiv(lhs, rhs, "divtmp");
            } else if (op->DIV() != nullptr) {
                value = builder.CreateSDiv(lhs, rhs, "sdivtmp");
            } else if (op->MOD() != nullptr) {
                value = builder.CreateSRem(lhs, rhs, "modtmp");
            }
        }
    } else {
        value = std::any_cast<llvm::Value*>(visit(ctx->factor()));
    }
    return value;
}

antlrcpp::Any CodeGenVisitor::visitBoolean(PascalSParser::BooleanContext* ctx) {
    Value* value = nullptr;
    if (ctx->TRUE()) {
        value = llvm::ConstantInt::get(llvm::Type::getInt1Ty(context), 1);
    } else if (ctx->FALSE()) {
        value = llvm::ConstantInt::get(llvm::Type::getInt1Ty(context), 0);
    }

    return value;
}

antlrcpp::Any CodeGenVisitor::visitSimpleExpression(PascalSParser::SimpleExpressionContext* ctx) {
    Value* value = nullptr;
    if (ctx->PLUS() || ctx->MINUS()) {
        Value* term_value = std::any_cast<llvm::Value*>(visit(ctx->term()));
        term_value = loadIfPointer(term_value);
        if (ctx->PLUS()) {
            value = term_value;
        } else if (ctx->MINUS()) {
            if (term_value->getType()->isFloatTy() || term_value->getType()->isDoubleTy()) {
                value = builder.CreateFNeg(term_value, "negtmp");
            } else {
                value = builder.CreateNeg(term_value, "negtmp");
            }
        }
    } else if (ctx->addOperator()) {
        llvm::Value* lhs = std::any_cast<llvm::Value*>(visit(ctx->simpleExpression()));
        auto op = ctx->addOperator();

        lhs = loadIfPointer(lhs);

        if (op->OR() != nullptr) {
            // 短路逻辑处理 - OR运算符
            checkType(lhs, "left-hand side of or expression");
            
            // 获取当前函数
            Function* function = builder.GetInsertBlock()->getParent();
            
            // 记录当前基本块，之后用于PHI节点
            BasicBlock* entryBlock = builder.GetInsertBlock();
            
            // 创建右表达式计算和合并的基本块
            BasicBlock* rhsBlock = BasicBlock::Create(context, "or.rhs", function);
            BasicBlock* mergeBlock = BasicBlock::Create(context, "or.merge", function);
            
            // 创建短路判断: 如果lhs为true(1)，直接跳到合并块，结果为true
            builder.CreateCondBr(lhs, mergeBlock, rhsBlock);
            
            // 右侧表达式块
            builder.SetInsertPoint(rhsBlock);
            Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->term()));
            rhs = loadIfPointer(rhs);
            checkType(rhs, "right-hand side of or expression");
            
            BasicBlock* rhsEndBlock = builder.GetInsertBlock();
            builder.CreateBr(mergeBlock);
            
            // 合并块
            builder.SetInsertPoint(mergeBlock);
            PHINode* phi = builder.CreatePHI(Type::getInt1Ty(context), 2, "ortmp");
            phi->addIncoming(ConstantInt::getTrue(context), entryBlock); // lhs为true的入口
            phi->addIncoming(rhs, rhsEndBlock); // rhs计算结果
            
            value = phi;
        } else {
            // 其他加法运算符无需短路逻辑
            llvm::Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->term()));
            rhs = loadIfPointer(rhs);

            if (op->PLUS() != nullptr || op->MINUS() != nullptr) {
                std::vector<llvm::Value*> converted_values = castBinary(lhs, rhs);
                lhs = converted_values[0];
                rhs = converted_values[1];
                if (op->PLUS() != nullptr) {
                    if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                        rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                        value = builder.CreateFAdd(lhs, rhs, "addtmp");
                    } else {
                        value = builder.CreateAdd(lhs, rhs, "addtmp");
                    }
                } else if (op->MINUS() != nullptr) {
                    if (lhs->getType()->isFloatTy() || lhs->getType()->isDoubleTy() || 
                        rhs->getType()->isFloatTy() || rhs->getType()->isDoubleTy()) {
                        value = builder.CreateFSub(lhs, rhs, "subtmp");
                    } else {
                        value = builder.CreateSub(lhs, rhs, "subtmp");
                    }
                }
            }
        }
    } else {
        value = std::any_cast<llvm::Value*>(visit(ctx->term()));
    }

    return value;
}

antlrcpp::Any CodeGenVisitor::visitVariable(PascalSParser::VariableContext* ctx) {
    std::string var_name = ctx->ID()->getText();
    llvm::Value* value = current_scope->get(var_name);

    // 检查是否为当前函数名称（用于函数返回值赋值）
    if (value == nullptr && !function_name_stack.empty() && var_name == function_name_stack.back()) {
        if (current_return_value != nullptr) {
            // 函数名作为返回值变量使用
            value = current_return_value;
        }
    }

    // 如果仍然找不到，尝试在全局作用域查找
    if (value == nullptr) {
        value = global_scope->get(var_name);
    }

    if (value == nullptr) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "identifier(1044) '" + var_name + "' was not declared in this scope");
    }
    
    // 检查是否是函数类型，如果是且处于变量上下文，则使用其返回值
    if (llvm::isa<Function>(value) && !function_name_stack.empty() && var_name == function_name_stack.back()) {
        // 当前函数的函数名作为变量使用时，应返回返回值变量
        if (current_return_value != nullptr) {
            value = current_return_value;
        }
    }
    
    PascalSParser::IdVarpartsContext* id_varparts_ctx = ctx->idVarparts();

    for (size_t i = 0; id_varparts_ctx != nullptr && i < id_varparts_ctx->children.size(); ++i) {
        auto id_varpart_ctx = dynamic_cast<PascalSParser::IdVarpartContext*>(id_varparts_ctx->children[i]);
        if (id_varpart_ctx) {
            if (id_varpart_ctx->LBRACKET()) {
                // 获取数组索引
                std::vector<Value*> index = std::any_cast<std::vector<Value*>>(visit(id_varpart_ctx->expressionList()));
                
                try {
                    value = getArrayElement(value, index);
                } catch (const SemanticException& e) {
                    throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                        std::string("Error accessing array: ") + e.what());
                }
            } else if (id_varpart_ctx->DOT()) {
                std::string field_name = id_varpart_ctx->ID()->getText();
                value = getRecordElement(value, field_name);
            }
        }
    }

    return value;
}

Value* CodeGenVisitor::getArrayElement(Value* array, std::vector<Value*> index) {
    Type* array_type = nullptr;
    if (auto *allocaInst = dyn_cast<AllocaInst>(array)) {
        array_type = allocaInst->getAllocatedType();
    } else if (auto *globalVar = dyn_cast<GlobalVariable>(array)) {
        array_type = globalVar->getValueType();
    } else {
        throw SemanticException(filename, 0, 0, "cannot determine array type");
    }
    
    // 打印类型信息
    if (!array_type) {
        throw SemanticException(filename, 0, 0, "cannot determine array type");
    }
    
    // 先尝试直接通过类型查询数组信息
    std::vector<std::pair<int, int>> array_info = current_scope->getArray(array_type);
    
    // 如果当前作用域找不到，尝试从全局作用域查找
    if (array_info.empty()) {
        array_info = global_scope->getArray(array_type);
    }
    
    // 如果仍然找不到，尝试所有已注册的数组类型
    if (array_info.empty()) {
        // 遍历当前作用域中的所有数组类型
        array_info = current_scope->findArrayInfoByElementType(array_type);
        
        // 如果当前作用域找不到，尝试全局作用域
        if (array_info.empty()) {
            array_info = global_scope->findArrayInfoByElementType(array_type);
        }
    }
    
    // 最后兜底方案：直接使用索引维度作为数组维度信息
    if (array_info.empty() && array_type->isArrayTy()) {
        for (size_t i = 0; i < index.size(); i++) {
            array_info.push_back(std::make_pair(0, cast<ArrayType>(array_type)->getNumElements() - 1));
        }
    }
    
    // 如果还是找不到，抛出错误
    if (array_info.empty()) {
        throw SemanticException(filename, 0, 0, "array information not found");
    }
    
    if (array_info.size() != index.size()) {
        throw SemanticException(filename, 0, 0, "array index count mismatch");
    }

    std::vector<Value*> offsetted_indices;
    offsetted_indices.push_back(ConstantInt::get(context, APInt(32, 0)));
    for (int i = 0; i < array_info.size(); i++) {
        Value* start = ConstantInt::get(context, APInt(32, array_info[i].first));
        index[i] = loadIfPointer(index[i]);
        Value* offset = builder.CreateSub(index[i], start);
        offsetted_indices.push_back(offset);
    }

    return builder.CreateGEP(array_type, array, offsetted_indices);
}

Value* CodeGenVisitor::getRecordElement(Value* record, std::string& field) {
    Type* record_type = ((AllocaInst*)record)->getAllocatedType();
    std::map<std::string, int> record_info = current_scope->getRecord(record_type);
    std::transform(field.begin(), field.end(), field.begin(), ::tolower);
    auto index = record_info.find(field);

    if (index == record_info.end()) {
        throw SemanticException(filename, 0, 0, "field '" + field + "' not found in record");
    }

    return builder.CreateStructGEP(record_type, record, index->second);
}

Value* CodeGenVisitor::loadIfPointer(llvm::Value* value) {
    if (value->getType()->isPointerTy()) {
        value = builder.CreateLoad(cast<PointerType>(value->getType())->getPointerElementType(), value);
    }
    return value;
}

std::vector<llvm::Value*> CodeGenVisitor::castBinary(llvm::Value* lhs, llvm::Value* rhs) {
    llvm::Type* lhsType = lhs->getType();
    llvm::Type* rhsType = rhs->getType();
    
    // 标准浮点类型 - 统一使用double类型
    llvm::Type* standardFloatType = Type::getDoubleTy(context);
    
    // 如果类型相同，且不是float，直接返回
    if (lhsType == rhsType && !lhsType->isFloatTy()) {
        return { lhs, rhs };
    }
    
    // 如果任一操作数是float类型，转换为double
    if (lhsType->isFloatTy()) {
        lhs = builder.CreateFPExt(lhs, standardFloatType, "floatToDouble");
        lhsType = standardFloatType;
    }
    
    if (rhsType->isFloatTy()) {
        rhs = builder.CreateFPExt(rhs, standardFloatType, "floatToDouble");
        rhsType = standardFloatType;
    }
    
    // 如果类型现在相同，直接返回
    if (lhsType == rhsType) {
        return { lhs, rhs };
    }
    
    // 处理不同类型的情况
    
    // 情况1: 整数和浮点数之间的转换
    if (lhsType->isIntegerTy() && rhsType->isDoubleTy()) {
        // 将整数转换为浮点数
        lhs = builder.CreateSIToFP(lhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    else if (lhsType->isDoubleTy() && rhsType->isIntegerTy()) {
        // 将整数转换为浮点数
        rhs = builder.CreateSIToFP(rhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    
    // 情况2: 不同位宽的整数类型之间的转换
    else if (lhsType->isIntegerTy() && rhsType->isIntegerTy()) {
        // 选择位宽较大的类型
        if (lhsType->getIntegerBitWidth() >= rhsType->getIntegerBitWidth()) {
            rhs = builder.CreateIntCast(rhs, lhsType, true, "intCast");
        } else {
            lhs = builder.CreateIntCast(lhs, rhsType, true, "intCast");
        }
        return { lhs, rhs };
    }
    
    // 情况3: 字符类型(i8)和整数类型之间的转换
    else if (lhsType->isIntegerTy(8) && rhsType->isIntegerTy() && !rhsType->isIntegerTy(8)) {
        // 将字符转换为整数
        lhs = builder.CreateIntCast(lhs, rhsType, true, "charToInt");
        return { lhs, rhs };
    }
    else if (rhsType->isIntegerTy(8) && lhsType->isIntegerTy() && !lhsType->isIntegerTy(8)) {
        // 将字符转换为整数
        rhs = builder.CreateIntCast(rhs, lhsType, true, "charToInt");
        return { lhs, rhs };
    }
    
    // 情况4: 字符类型和浮点数类型之间的转换
    else if (lhsType->isIntegerTy(8) && rhsType->isDoubleTy()) {
        // 先将字符转换为int32，再转换为浮点数
        lhs = builder.CreateIntCast(lhs, builder.getInt32Ty(), true, "charToInt");
        lhs = builder.CreateSIToFP(lhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    else if (rhsType->isIntegerTy(8) && lhsType->isDoubleTy()) {
        // 先将字符转换为int32，再转换为浮点数
        rhs = builder.CreateIntCast(rhs, builder.getInt32Ty(), true, "charToInt");
        rhs = builder.CreateSIToFP(rhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    
    // 情况5: 布尔类型(i1)和整数类型之间的转换
    else if (lhsType->isIntegerTy(1) && rhsType->isIntegerTy() && !rhsType->isIntegerTy(1)) {
        // 将布尔值转换为整数
        lhs = builder.CreateIntCast(lhs, rhsType, true, "boolToInt");
        return { lhs, rhs };
    }
    else if (rhsType->isIntegerTy(1) && lhsType->isIntegerTy() && !lhsType->isIntegerTy(1)) {
        // 将布尔值转换为整数
        rhs = builder.CreateIntCast(rhs, lhsType, true, "boolToInt");
        return { lhs, rhs };
    }
    
    // 情况6: 布尔类型和浮点数类型之间的转换
    else if (lhsType->isIntegerTy(1) && rhsType->isDoubleTy()) {
        // 先将布尔值转换为int32，再转换为浮点数
        lhs = builder.CreateIntCast(lhs, builder.getInt32Ty(), true, "boolToInt");
        lhs = builder.CreateSIToFP(lhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    else if (rhsType->isIntegerTy(1) && lhsType->isDoubleTy()) {
        // 先将布尔值转换为int32，再转换为浮点数
        rhs = builder.CreateIntCast(rhs, builder.getInt32Ty(), true, "boolToInt");
        rhs = builder.CreateSIToFP(rhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    
    // 尝试将浮点数转换为整数（即使可能会丢失精度）
    else if (lhsType->isDoubleTy() && rhsType->isIntegerTy()) {
        rhs = builder.CreateSIToFP(rhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    else if (rhsType->isDoubleTy() && lhsType->isIntegerTy()) {
        lhs = builder.CreateSIToFP(lhs, standardFloatType, "intToDouble");
        return { lhs, rhs };
    }
    
    // 如果以上都不适用，则尝试一个最后的兜底方案：将两个值都转换为标准浮点数类型
    if (lhsType->isIntegerTy()) {
        lhs = builder.CreateSIToFP(lhs, standardFloatType, "lastResortIntToDouble");
    }
    if (rhsType->isIntegerTy()) {
        rhs = builder.CreateSIToFP(rhs, standardFloatType, "lastResortIntToDouble");
    }
    
    // 确保两个操作数都是相同的浮点类型
    if ((lhsType->isFloatTy() || lhsType->isDoubleTy()) && 
        (rhsType->isFloatTy() || rhsType->isDoubleTy()) && 
        lhsType != rhsType) {
        // 将两个操作数都转换为标准浮点类型
        lhs = builder.CreateFPCast(lhs, standardFloatType, "floatCast");
        rhs = builder.CreateFPCast(rhs, standardFloatType, "floatCast");
    }
    
    return { lhs, rhs };
}

void CodeGenVisitor::checkType(llvm::Value* value, const std::string& context) {
    llvm::Type* type = value->getType();
    if (!((type->isIntegerTy() && type->getIntegerBitWidth() == 32) || type->isIntegerTy(1))) {
        throw SemanticException("type mismatch in " + context + ": Logical operators can only be applied to Int or Boolean types");
    }
}

void CodeGenVisitor::checkFunctionArgs(std::string func_name, llvm::Function* func, std::vector<llvm::Value*>& args) {
    FunctionType* func_type = func->getFunctionType();
    // 参数个数检查
    if (args.size() != func_type->getNumParams()) {
        throw SemanticException("Incorrect number of arguments for function " + func_name + ". Expected " + std::to_string(func_type->getNumParams()) + ", but got " + std::to_string(args.size()) + ".");
    }
    // 参数类型检查
    for (size_t i = 0; i < args.size(); ++i) {
        Type* expected_type = func_type->getParamType(i);
        Type* actual_type = args[i]->getType();

        // 如果需要值但传入了指针，加载指针内容
        if (!expected_type->isPointerTy() && actual_type->isPointerTy()) {
            args[i] = loadIfPointer(args[i]);
            actual_type = args[i]->getType();
        }
        
        // 如果类型已经相同，则跳过
        if (expected_type == actual_type) {
            continue;
        }
        
        // 放宽类型检查，允许各种转换
        
        // 1. 整数类型转浮点类型
        if ((expected_type->isFloatTy() || expected_type->isDoubleTy()) && actual_type->isIntegerTy()) {
            args[i] = builder.CreateSIToFP(args[i], expected_type, "intToFloat_arg");
            continue;
        }
        
        // 2. 浮点类型转整数类型（关键修改）
        if (expected_type->isIntegerTy() && (actual_type->isFloatTy() || actual_type->isDoubleTy())) {
            args[i] = builder.CreateFPToSI(args[i], expected_type, "floatToInt_arg");
            continue;
        }
        
        // 3. 不同位宽的整数类型之间的转换
        if (expected_type->isIntegerTy() && actual_type->isIntegerTy()) {
            args[i] = builder.CreateIntCast(args[i], expected_type, true, "intCast_arg");
            continue;
        }
        
        // 4. 字符类型和整数类型之间的转换
        if ((expected_type->isIntegerTy(8) && actual_type->isIntegerTy()) || 
            (expected_type->isIntegerTy() && actual_type->isIntegerTy(8))) {
            args[i] = builder.CreateIntCast(args[i], expected_type, true, "charCast_arg");
            continue;
        }
        
        // 5. 字符类型和浮点类型之间的转换
        if ((expected_type->isFloatTy() || expected_type->isDoubleTy()) && actual_type->isIntegerTy(8)) {
            // 字符转浮点
            args[i] = builder.CreateIntCast(args[i], builder.getInt32Ty(), true, "charToInt_arg");
            args[i] = builder.CreateSIToFP(args[i], expected_type, "intToFloat_arg");
            continue;
        }
        
        if (expected_type->isIntegerTy(8) && (actual_type->isFloatTy() || actual_type->isDoubleTy())) {
            // 浮点转字符
            args[i] = builder.CreateFPToSI(args[i], builder.getInt32Ty(), "floatToInt_arg");
            args[i] = builder.CreateIntCast(args[i], expected_type, true, "intToChar_arg");
            continue;
        }
        
        // 6. 布尔类型与其他类型之间的转换
        if (expected_type->isIntegerTy(1)) {
            // 转布尔类型
            if (actual_type->isIntegerTy()) {
                args[i] = builder.CreateICmpNE(args[i], 
                    ConstantInt::get(actual_type, 0), "toBool_arg");
                continue;
            }
            else if (actual_type->isFloatTy() || actual_type->isDoubleTy()) {
                args[i] = builder.CreateFCmpONE(args[i], 
                    ConstantFP::get(actual_type, 0.0), "floatToBool_arg");
                continue;
            }
        }
        
        if (actual_type->isIntegerTy(1)) {
            // 布尔转其他类型
            if (expected_type->isIntegerTy()) {
                args[i] = builder.CreateIntCast(args[i], expected_type, true, "boolToInt_arg");
                continue;
            }
            else if (expected_type->isFloatTy() || expected_type->isDoubleTy()) {
                args[i] = builder.CreateUIToFP(args[i], expected_type, "boolToFloat_arg");
                continue;
            }
        }
        
        // 指针类型特殊处理
        if (expected_type->isPointerTy() && actual_type->isPointerTy()) {
            Type* expected_elem_type = cast<PointerType>(expected_type)->getPointerElementType();
            Type* actual_elem_type = cast<PointerType>(actual_type)->getPointerElementType();
            
            // 指针类型的内容类型不同但可接受的情况
            if (expected_elem_type->isFloatTy() || expected_elem_type->isDoubleTy() || 
                expected_elem_type->isIntegerTy() || actual_elem_type->isFloatTy() || 
                actual_elem_type->isDoubleTy() || actual_elem_type->isIntegerTy()) {
                // 基本类型的指针转换，不报错，后续操作会视需要转换
                continue;
            }
        }
        
        // 7. 处理不同类型的浮点数转换 (float <-> double)
        if ((expected_type->isFloatTy() && actual_type->isDoubleTy()) || 
            (expected_type->isDoubleTy() && actual_type->isFloatTy())) {
            args[i] = builder.CreateFPCast(args[i], expected_type, "fpCast_arg");
            continue;
        }
        
        // 如果以上所有情况都不满足，尝试强制类型转换（最后的努力）
        try {
            // 尝试将两者都转换为公共类型
            if (expected_type->isFloatTy() || expected_type->isDoubleTy()) {
                // 目标是浮点型，尝试将参数转为浮点型
                if (actual_type->isIntegerTy()) {
                    args[i] = builder.CreateSIToFP(args[i], expected_type, "lastResort_intToFloat");
                    continue;
                }
            }
            else if (expected_type->isIntegerTy()) {
                // 目标是整数型，尝试转换
                if (actual_type->isFloatTy() || actual_type->isDoubleTy()) {
                    args[i] = builder.CreateFPToSI(args[i], expected_type, "lastResort_floatToInt");
                    continue;
                }
                else if (actual_type->isIntegerTy()) {
                    args[i] = builder.CreateIntCast(args[i], expected_type, true, "lastResort_intCast");
                    continue;
                }
            }
            
            // 实在不行就报错
            throw SemanticException("argument type mismatch for parameter " + std::to_string(i + 1) + " in function " + func_name + ".");
        }
        catch (...) {
            // 捕获所有异常，防止编译器崩溃
            throw SemanticException("argument type mismatch for parameter " + std::to_string(i + 1) + " in function " + func_name + ".");
        }
    }
}

// 处理赋值语句
antlrcpp::Any CodeGenVisitor::visitAssignmentStatement(PascalSParser::AssignmentStatementContext* ctx) {
    Value* var = std::any_cast<Value*>(visit(ctx->variable()));
    Value* expr = std::any_cast<Value*>(visit(ctx->expression()));
    expr = loadIfPointer(expr);

    if (!var) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "identifier(1073) '" + ctx->variable()->ID()->getText() + "' was not declared in this scope");
    }

    if (!expr) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "failed to evaluate expression '" + ctx->expression()->getText() + "'");
    }

    Type* varType = cast<PointerType>(var->getType())->getPointerElementType();
    Type* exprType = expr->getType();

    // 如果类型相同，直接赋值
    if (varType == exprType) {
        return builder.CreateStore(expr, var);
    }

    // 进行类型转换尝试
    
    // 1. 浮点数和整数之间的转换
    if ((varType->isFloatTy() || varType->isDoubleTy()) && exprType->isIntegerTy()) {
        // 整数到浮点
        expr = builder.CreateSIToFP(expr, varType, "assign_intToFloat");
        return builder.CreateStore(expr, var);
    }
    
    if (varType->isIntegerTy() && (exprType->isFloatTy() || exprType->isDoubleTy())) {
        // 浮点到整数
        expr = builder.CreateFPToSI(expr, varType, "assign_floatToInt");
        return builder.CreateStore(expr, var);
    }
    
    // 2. 不同位宽的整数类型之间的转换
    if (varType->isIntegerTy() && exprType->isIntegerTy()) {
        expr = builder.CreateIntCast(expr, varType, true, "assign_intCast");
        return builder.CreateStore(expr, var);
    }
    
    // 3. 字符类型和整数类型之间的转换
    if (varType->isIntegerTy(8) && exprType->isIntegerTy()) {
        expr = builder.CreateIntCast(expr, varType, true, "assign_intToChar");
        return builder.CreateStore(expr, var);
    }
    
    if (varType->isIntegerTy() && exprType->isIntegerTy(8)) {
        expr = builder.CreateIntCast(expr, varType, true, "assign_charToInt");
        return builder.CreateStore(expr, var);
    }
    
    // 4. 字符类型和浮点类型之间的转换
    if (varType->isIntegerTy(8) && (exprType->isFloatTy() || exprType->isDoubleTy())) {
        expr = builder.CreateFPToSI(expr, builder.getInt32Ty(), "assign_floatToInt");
        expr = builder.CreateIntCast(expr, varType, true, "assign_intToChar");
        return builder.CreateStore(expr, var);
    }
    
    if ((varType->isFloatTy() || varType->isDoubleTy()) && exprType->isIntegerTy(8)) {
        expr = builder.CreateIntCast(expr, builder.getInt32Ty(), true, "assign_charToInt");
        expr = builder.CreateSIToFP(expr, varType, "assign_intToFloat");
        return builder.CreateStore(expr, var);
    }
    
    // 5. 处理不同类型的浮点数转换 (float <-> double)
    if ((varType->isFloatTy() && exprType->isDoubleTy()) || 
        (varType->isDoubleTy() && exprType->isFloatTy())) {
        expr = builder.CreateFPCast(expr, varType, "assign_fpCast");
        return builder.CreateStore(expr, var);
    }
    
    // 6. 布尔类型和其他类型之间的转换
    if (varType->isIntegerTy(1)) {
        // 转换为布尔值
        if (exprType->isIntegerTy()) {
            expr = builder.CreateICmpNE(expr, ConstantInt::get(exprType, 0), "assign_toBool");
            return builder.CreateStore(expr, var);
        }
        if (exprType->isFloatTy() || exprType->isDoubleTy()) {
            expr = builder.CreateFCmpONE(expr, ConstantFP::get(exprType, 0.0), "assign_floatToBool");
            return builder.CreateStore(expr, var);
        }
    }
    
    if (exprType->isIntegerTy(1)) {
        // 布尔值转其他类型
        if (varType->isIntegerTy()) {
            expr = builder.CreateIntCast(expr, varType, true, "assign_boolToInt");
            return builder.CreateStore(expr, var);
        }
        if (varType->isFloatTy() || varType->isDoubleTy()) {
            expr = builder.CreateUIToFP(expr, varType, "assign_boolToFloat");
            return builder.CreateStore(expr, var);
        }
    }
    
    // 7. 最后尝试一些非标准转换
    try {
        // 如果目标类型是浮点型，尝试将表达式转为浮点型
        if (varType->isFloatTy() || varType->isDoubleTy()) {
            if (exprType->isIntegerTy() || exprType->isIntegerTy(1) || exprType->isIntegerTy(8)) {
                expr = builder.CreateSIToFP(expr, varType, "assign_lastResort_toFloat");
                return builder.CreateStore(expr, var);
            }
        }
        
        // 如果目标类型是整数型，尝试将表达式转为整数
        if (varType->isIntegerTy()) {
            if (exprType->isFloatTy() || exprType->isDoubleTy()) {
                expr = builder.CreateFPToSI(expr, varType, "assign_lastResort_toInt");
                return builder.CreateStore(expr, var);
            }
            if (exprType->isIntegerTy() || exprType->isIntegerTy(1) || exprType->isIntegerTy(8)) {
                expr = builder.CreateIntCast(expr, varType, true, "assign_lastResort_intCast");
                return builder.CreateStore(expr, var);
            }
        }
        
        // 如果还是无法转换，尝试位转换
        expr = builder.CreateBitCast(expr, varType, "assign_desperate_bitcast");
        return builder.CreateStore(expr, var);
    }
    catch (...) {
        // 如果所有尝试都失败，抛出类型不匹配错误
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "type mismatch: cannot assign " + ctx->expression()->getText() + " to " + ctx->variable()->getText());
    }
}

// 处理表达式列表
antlrcpp::Any CodeGenVisitor::visitExpressionList(PascalSParser::ExpressionListContext* ctx) {
    std::vector<Value*> expressions;

    // 假如有嵌套的表达式列表
    if (ctx->expressionList()) {
        auto nestedExpressions = std::any_cast<std::vector<Value*>>(visit(ctx->expressionList()));
        expressions.insert(expressions.end(), nestedExpressions.begin(), nestedExpressions.end());
    }

    Value* exprValue = std::any_cast<Value*>(visit(ctx->expression()));
    if (!exprValue) {
        throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
            "failed to evaluate expression '" + ctx->expression()->getText() + "'");
    }
    expressions.push_back(exprValue);

    return expressions;
}

// 处理函数调用
antlrcpp::Any CodeGenVisitor::visitCallProcedureStatement(PascalSParser::CallProcedureStatementContext* ctx) {
    std::vector<Value*> args;
    if (ctx->expressionList()) {
        auto expr_list = std::any_cast<std::vector<Value*>>(visit(ctx->expressionList()));
        args.insert(args.end(), expr_list.begin(), expr_list.end());
    }
    std::string func_name = ctx->ID()->getText();

    if (StandardProcedure::hasProcedure(func_name)) {
        std::transform(func_name.begin(), func_name.end(), func_name.begin(), ::tolower);
        if (func_name != "read" && func_name != "readln") {
            for (auto& arg : args) {
                arg = loadIfPointer(arg);
            }
        }
        auto stdProcedure = StandardProcedure::prototypeMap[func_name](module.get());
        StandardProcedure::argsConstructorMap[func_name](filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), &builder, args);
        llvm::ArrayRef<llvm::Value*> argsRef(args);
        builder.CreateCall(stdProcedure, argsRef);
    } else {
        Value* symbol = current_scope->get(func_name);
        // 作用域中无该符号
        if (!symbol) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "identifier(1140) '" + func_name + "' was not declared in this scope");
        }

        // 该符号不是函数
        if (!llvm::isa<llvm::Function>(symbol)) {
            throw SemanticException(filename, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(),
                "'" + func_name + "' is not a function");
        }
        Function* func = llvm::cast<llvm::Function>(symbol);
        checkFunctionArgs(func_name, func, args);
        builder.CreateCall(func, args);
    }
    return nullptr;
}


