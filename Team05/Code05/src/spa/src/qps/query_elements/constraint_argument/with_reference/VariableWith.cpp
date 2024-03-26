//
// Created by tohzh on 20/3/2024.
//

#include "VariableWith.h"

#include <utility>

VariableWith::VariableWith(std::string name, QPSTokenType::QPSTypeInfo attribute) {
    varName = std::move(name);
    varAttribute = attribute;
}


std::string VariableWith::getArgumentValue() {
    return getVarName();
}

std::vector<std::vector<std::string>> VariableWith::getEntityTable(QueryPKBVirtual &pkb) {
    auto entityTable = getRawTable(pkb);
    // TODO: filter according to attributes. procName vs Stmt
    if (!hasMoreThanOneColumn(entityTable)) {
        entityTable.insert(entityTable.begin(), {this->varName});
        return entityTable;
    }
    entityTable.insert(entityTable.begin(), {this->varName, "LiteralWith"});
    if (varAttribute == QPSTokenType::STMT) {
        //drop right
        entityTable = removeColumnByIndex(1, entityTable);
        entityTable.insert(entityTable.begin(), {this->varName});
    } else if (varAttribute == QPSTokenType::VARNAME || varAttribute == QPSTokenType::PROCNAME) {
        //drop left
        entityTable = removeColumnByIndex(0, entityTable);
        entityTable.insert(entityTable.begin(), {this->varName});
    } else {
        throw new QPSException("Invalid token type provided for with variable");
    }
    return entityTable;
}

std::string VariableWith::toString() {
    return varName + "." + to_string(varAttribute) + " [VAR_WITH]";
}

std::string VariableWith::getEntityType() {
    return TYPE_VAR_WITH;
}

std::string VariableWith::getReturnType() {
    if (this->varAttribute == QPSTokenType::VARNAME || this->varAttribute == QPSTokenType::PROCNAME) {
        return RETURN_STR_RESULT;
    } else {
        return RETURN_INT_RESULT;
    }
}

std::string VariableWith::getVarName() {
    return varName;
}

QPSTokenType::QPSTypeInfo VariableWith::getVarAttribute() {
    return varAttribute;
}

void VariableWith::setVariable(std::shared_ptr<QueryObject> qo) {
    variable = qo->getEntityInDeclaration(varName);
}

std::vector<std::vector<std::string>> VariableWith::getRawTable(QueryPKBVirtual &pkb) {
    if (variable == nullptr) {
        throw QPSException("Invalid PKB Query");
    }
    return variable->getRawTable(pkb);
}

bool VariableWith::hasMoreThanOneColumn(std::vector<std::vector<std::string>> entityTable) {
    return entityTable.size() > 1;
}

std::vector<std::vector<std::string>> VariableWith::removeColumnByIndex(int i, std::vector<std::vector<std::string>> table){
    if (i >= 0 && i < table[0].size()) {
        for (int j = 0; j < table.size(); ++j) {
            table[j].erase(table[j].begin() + i);
        }
    }
    return table;
}