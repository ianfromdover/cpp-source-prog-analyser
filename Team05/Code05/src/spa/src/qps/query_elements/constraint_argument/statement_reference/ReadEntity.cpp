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

std::vector<std::string> ReadEntity::getArgumentValue() {
    return {this->identifier};
}

Table ReadEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getReadTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier, HEADER_ENT_READRHS});
    return entityTable;
}

std::vector<std::vector<std::string>> ReadEntity::getRawTable(QueryPkbVirtual &pkb) {
    return pkb.getReadTable();
}
