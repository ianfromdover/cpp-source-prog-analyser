//
// Created by tohzh on 8/2/2024.
//

#include "ReadEntity.h"

std::string ReadEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string ReadEntity::getEntityType() {
    return TYPE_READ;
}

ReadEntity::ReadEntity(std::string s) {
    identifier = std::move(s);
}

std::string ReadEntity::toString() {
    return this->identifier + " [READ]";
}

std::string ReadEntity::getArgumentValue() {
    return this->identifier;
}

std::vector<std::vector<std::string>> ReadEntity::getEntityTable(QueryPKBVirtual &pkb) {
    auto entityTable = pkb.getRead();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {TYPE_STATEMENT, getEntityType()});
    return entityTable;
}
