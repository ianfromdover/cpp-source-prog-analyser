//
// Created by tohzh on 15/2/2024.
//

#include "VariableEntity.h"

std::string VariableEntity::getReturnType() {
    return RETURN_STR_RESULT;
}

std::string VariableEntity::getEntityType() {
    return TYPE_VARIABLE;
}

VariableEntity::VariableEntity(std::string s) {
    identifier = std::move(s);
}

std::string VariableEntity::toString() {
    return this->identifier + " [VARIABLE]";
}

std::string VariableEntity::getArgumentValue() {
    return this->identifier;
}

std::vector<std::vector<std::string>> VariableEntity::getEntityTable(QueryPKBVirtual &pkb) {
    auto entityTable = pkb.getVar();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {TYPE_STATEMENT, getEntityType()});
    return entityTable;
}
