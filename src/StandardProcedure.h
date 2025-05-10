#ifndef STANDARDPROCEDURE_H
#define STANDARDPROCEDURE_H

#include <llvm/IR/IRBuilder.h>
#include <unordered_map>

class StandardProcedure {
public:
    static std::unordered_map<std::string, llvm::Function* (*)(llvm::Module*)> prototypeMap;
    static std::unordered_map<std::string, void (*)(std::string filename, int line, int column, llvm::IRBuilder<>*, std::vector<llvm::Value*>&)> argsConstructorMap;

    static void init();
    static bool hasProcedure(std::string name);

private:
    static std::string getFormatString(llvm::Type* type);
};

#endif