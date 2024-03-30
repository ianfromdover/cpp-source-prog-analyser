//
// Created by tohzh on 8/2/2024.
//

#include "AssignEntity.h"

#include <utility>

std::string AssignEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string AssignEntity::getEntityType() {
    return TYPE_ASSIGN;
}

AssignEntity::AssignEntity(std::string s) {
    identifier = std::move(s);
}

std::string AssignEntity::toString() {
    return this->identifier + " [ASSIGN]";
}

std::string AssignEntity::getArgumentValue() {
    return this->identifier;
}

Table AssignEntity::getEntityTable(QueryPkbVirtual & pkb ) {
    auto entityTable = pkb.getPatternAsgnTable();
    // Insertion of headers into our entity table
    //    entityTable.insert(entityTable.begin(), {this->identifier,
    //    "ASSIGNLHS", "ASSIGNRHS"});
    entityTable.insert(entityTable.begin(), {this->identifier, "ASSIGNRHS"});
    return entityTable;
}

std::vector<std::vector<std::string>> AssignEntity::getRawTable(QueryPkbVirtual &pkb) {
    return pkb.getPatternAsgnTable();
}
