#ifndef CODEGENVISITOR_H
#define CODEGENVISITOR_H

#include "PascalSBaseVisitor.h"
#include "Scope.h"
#include "StandardProcedure.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

using namespace llvm;

struct SubprogramParameter {
    std::string name;
    llvm::Type* type;
    bool is_var;
};

class CodeGenVisitor : public PascalSBaseVisitor {
private:
    StandardProcedure standard_procedure;
    LLVMContext context;
    IRBuilder<> builder;
    Scope* scope = new Scope();
    Scope* subprogram_scope = new Scope();
    llvm::Value* current_return_value = ConstantInt::get(context, APInt(32, 0));
    std::string filename;
    BasicBlock* current_loop_end;

    void InitBuiltins();

public:
    std::unique_ptr<Module> module;

    CodeGenVisitor();
    CodeGenVisitor(const std::string& filename);
    ~CodeGenVisitor();

    antlrcpp::Any visitProgramHead(PascalSParser::ProgramHeadContext* ctx) override;
    antlrcpp::Any visitProgramBody(PascalSParser::ProgramBodyContext* ctx) override;

    antlrcpp::Any visitConstDeclaration(PascalSParser::ConstDeclarationContext* ctx) override;
    antlrcpp::Any visitConstVariable(PascalSParser::ConstVariableContext* ctx) override;

    antlrcpp::Any visitTypeDeclaration(PascalSParser::TypeDeclarationContext* ctx) override;

    antlrcpp::Any visitVarDeclarations(PascalSParser::VarDeclarationsContext* ctx) override;
    antlrcpp::Any visitVarDeclaration(PascalSParser::VarDeclarationContext* ctx) override;
    antlrcpp::Any visitIdentifierList(PascalSParser::IdentifierListContext* ctx) override;

    antlrcpp::Any visitType(PascalSParser::TypeContext* ctx) override;
    antlrcpp::Any visitPeriods(PascalSParser::PeriodsContext* ctx) override;
    antlrcpp::Any visitPeriod(PascalSParser::PeriodContext* ctx) override;
    antlrcpp::Any visitStandardType(PascalSParser::StandardTypeContext* ctx) override;
    antlrcpp::Any visitExpression(PascalSParser::ExpressionContext* ctx) override;

    antlrcpp::Any visitIfStatement(PascalSParser::IfStatementContext* ctx) override;
    antlrcpp::Any visitForStatement(PascalSParser::ForStatementContext* ctx) override;
    antlrcpp::Any visitWhileStatement(PascalSParser::WhileStatementContext* ctx) override;
    antlrcpp::Any visitRepeatStatement(PascalSParser::RepeatStatementContext* ctx) override;
    antlrcpp::Any visitStatementList(PascalSParser::StatementListContext* ctx) override;
    antlrcpp::Any visitCaseStatement(PascalSParser::CaseStatementContext* ctx) override;
    antlrcpp::Any visitConstList(PascalSParser::ConstListContext* ctx) override;
    antlrcpp::Any visitBranch(PascalSParser::BranchContext* ctx) override;
    antlrcpp::Any visitBranchList(PascalSParser::BranchListContext* ctx) override;

    antlrcpp::Any visitSubprogramDeclaration(PascalSParser::SubprogramDeclarationContext* ctx) override;
    antlrcpp::Any visitSubprogramHead(PascalSParser::SubprogramHeadContext* ctx) override;
    antlrcpp::Any visitParameterLists(PascalSParser::ParameterListsContext* ctx) override;
    antlrcpp::Any visitParameterList(PascalSParser::ParameterListContext* ctx) override;
    antlrcpp::Any visitVarParameter(PascalSParser::VarParameterContext* ctx) override;
    antlrcpp::Any visitValueParameter(PascalSParser::ValueParameterContext* ctx) override;

    antlrcpp::Any visitTerm(PascalSParser::TermContext* ctx) override;
    antlrcpp::Any visitFactor(PascalSParser::FactorContext* ctx) override;
    antlrcpp::Any visitAssignmentStatement(PascalSParser::AssignmentStatementContext* ctx) override;
    antlrcpp::Any visitExpressionList(PascalSParser::ExpressionListContext* ctx) override;
    antlrcpp::Any visitCallProcedureStatement(PascalSParser::CallProcedureStatementContext* ctx) override;
    antlrcpp::Any visitUnsignConstVariable(PascalSParser::UnsignConstVariableContext* ctx) override;
    antlrcpp::Any visitSimpleExpression(PascalSParser::SimpleExpressionContext* ctx) override;
    antlrcpp::Any visitBoolean(PascalSParser::BooleanContext* ctx) override;
    antlrcpp::Any visitVariable(PascalSParser::VariableContext* ctx) override;
    
};

#endif // CODEGENVISITOR_H