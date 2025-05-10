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
};

#endif // CODEGENVISITOR_H