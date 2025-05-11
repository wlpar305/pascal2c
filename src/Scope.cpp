#include "Scope.h"
#include "llvm/IR/DerivedTypes.h"
#include <iostream>
#include <algorithm>

void Scope::put(const std::string& name, llvm::Value* value) {
    std::string transformed_name = name;
    std::transform(transformed_name.begin(), transformed_name.end(), transformed_name.begin(), ::tolower);
    table[transformed_name] = value;
}

void Scope::putArray(const llvm::Type* type, const std::vector<std::pair<int, int>>& array) {
    array_table[type] = array;
}

void Scope::putRecord(const llvm::Type* type, const std::map<std::string, int>& record) {
    record_table[type] = record;
}

llvm::Value* Scope::get(const std::string& name) {
    std::string transformed_name = name;
    std::transform(transformed_name.begin(), transformed_name.end(), transformed_name.begin(), ::tolower);
    if (table.find(transformed_name) != table.end()) {
        return table[transformed_name];
    }
    if (parent != nullptr) {
        return parent->get(transformed_name);
    }
    return 0;
}

std::vector<std::pair<int, int>> Scope::getArray(const llvm::Type* type) {
    if (array_table.find(type) != array_table.end()) {
        return array_table[type];
    }
    if (parent != nullptr) {
        return parent->getArray(type);
    }
    return {};
}

std::map<std::string, int> Scope::getRecord(const llvm::Type* type) {
    if (record_table.find(type) != record_table.end()) {
        return record_table[type];
    }
    if (parent != nullptr) {
        return parent->getRecord(type);
    }
    return {};
}

bool Scope::declared(const std::string& name) {
    std::string transformed_name = name;
    std::transform(transformed_name.begin(), transformed_name.end(), transformed_name.begin(), ::tolower);
    return table.find(transformed_name) != table.end();
}

// 新增方法：根据元素类型查找数组信息
std::vector<std::pair<int, int>> Scope::findArrayInfoByElementType(const llvm::Type* elementType) {
    // 遍历所有注册的数组类型
    for (const auto& entry : array_table) {
        const llvm::Type* arrayType = entry.first;
        const std::vector<std::pair<int, int>>& arrayInfo = entry.second;
        
        // 检查是否为数组类型
        if (arrayType->isArrayTy()) {
            const llvm::ArrayType* asArray = llvm::cast<llvm::ArrayType>(arrayType);
            const llvm::Type* containedType = asArray->getElementType();
            
            // 类型比较 - 优先使用指针比较
            bool typesMatch = (containedType == elementType);
            
            // 如果指针不相等，尝试基于类型的匹配
            if (!typesMatch) {
                // 对于整数类型，如果位宽相同则认为相同
                if (containedType->isIntegerTy() && elementType->isIntegerTy()) {
                    if (llvm::cast<llvm::IntegerType>(containedType)->getBitWidth() == 
                        llvm::cast<llvm::IntegerType>(elementType)->getBitWidth()) {
                        typesMatch = true;
                    }
                }
                // 对于浮点类型，如果都是浮点则认为相同
                else if (containedType->isFloatTy() && elementType->isFloatTy()) {
                    typesMatch = true;
                }
            }
            
            // 如果找到匹配的元素类型，返回对应的数组信息
            if (typesMatch) {
                return arrayInfo;
            }
        }
    }
    
    // 如果在当前作用域中找不到，尝试父作用域
    if (parent != nullptr) {
        return parent->findArrayInfoByElementType(elementType);
    }
    
    return {};
}
