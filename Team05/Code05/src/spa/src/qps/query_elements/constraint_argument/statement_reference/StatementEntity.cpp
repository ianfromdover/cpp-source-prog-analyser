//
// Created by tohzh on 8/2/2024.
//

#include "StatementEntity.h"
#include "qps/Exceptions/QPSException.h"

std::string StatementEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string StatementEntity::getEntityType() {
    return TYPE_STATEMENT;
}

StatementEntity::StatementEntity(std::string s) {
    identifier = std::move(s);
}

std::string StatementEntity::getArgumentValue() {
    return this->identifier;
}

std::string StatementEntity::toString() {
    return this->identifier + " [STMT]";
}

Table StatementEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getStmtTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier});
    return entityTable;
}

