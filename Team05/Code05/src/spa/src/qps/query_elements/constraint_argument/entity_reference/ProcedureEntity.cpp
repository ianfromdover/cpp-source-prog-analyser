//
// Created by tohzh on 15/2/2024.
//

#include "ProcedureEntity.h"

std::string ProcedureEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string ProcedureEntity::getEntityType() {
    return TYPE_PROCEDURE;
}

ProcedureEntity::ProcedureEntity(std::string s) {
    identifier = std::move(s);
}

std::string ProcedureEntity::toString() {
    return this->identifier + " [PROCEDURE]";
}

std::string ProcedureEntity::getArgumentValue() {
    return this->identifier;
}

Table ProcedureEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getProcTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier});
    return entityTable;
}


