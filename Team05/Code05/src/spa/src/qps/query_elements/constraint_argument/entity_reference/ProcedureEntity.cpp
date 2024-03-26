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

std::vector<std::vector<std::string>> ProcedureEntity::getEntityTable(QueryPKBVirtual &pkb) {
    auto entityTable = pkb.getProcedure();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {"PROCEDURELHS", this->identifier});
    // TODO: HOTFIX - remove first column
    for (auto &row : entityTable) {
        row.erase(row.begin());
    }
    return entityTable;
}

std::vector<std::vector<std::string>> ProcedureEntity::getRawTable(QueryPKBVirtual &pkb) {
    return pkb.getProcedure();
}


