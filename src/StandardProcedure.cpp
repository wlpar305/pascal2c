#include "StandardProcedure.h"
#include "Exception/SemanticException.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"
#include <iostream>

std::unordered_map<std::string, llvm::Function* (*)(llvm::Module*)> StandardProcedure::prototypeMap;
std::unordered_map<std::string, void (*)(std::string filename, int line, int column, llvm::IRBuilder<>*, std::vector<llvm::Value*>&)> StandardProcedure::argsConstructorMap;

std::string StandardProcedure::getFormatString(llvm::Type* type) {
    if (type->isIntegerTy(8)) {
        return "%c";
    } else if (type->isFloatTy()) {
        return "%f";
    } else if (type->isPointerTy()) {
        return "%p";
    } else if (type->isIntegerTy(1)) {
        return "%d";
    } else if (type->isIntegerTy()) {
        return "%d";
    } else {
        std::string type_str;
        llvm::raw_string_ostream rso(type_str);
        type->print(rso);
        rso.flush();
        throw std::runtime_error("Unsupported argument type '" + type_str + "' for write");
    }
}

void StandardProcedure::init() {
    prototypeMap["write"] = writelnPrototype;
    prototypeMap["read"] = readlnPrototype;
    prototypeMap["writeln"] = writelnPrototype;
    prototypeMap["readln"] = readlnPrototype;
    argsConstructorMap["write"] = writeArgsConstructor;
    argsConstructorMap["read"] = readArgsConstructor;
    argsConstructorMap["writeln"] = writelnArgsConstructor;
    argsConstructorMap["readln"] = readlnArgsConstructor;
}

bool StandardProcedure::hasProcedure(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    return prototypeMap.find(name) != prototypeMap.end();
}