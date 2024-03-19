//
// Created by tohzh on 8/2/2024.
//

#include "IfEntity.h"

std::string IfEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string IfEntity::getEntityType() {
    return TYPE_IF;
}

IfEntity::IfEntity(std::string s) {
    identifier = std::move(s);
}

std::string IfEntity::toString() {
    return this->identifier + " [IF]";
}

std::string IfEntity::getArgumentValue() {
    return this->identifier;
}

Table IfEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getIfTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier, "IFRHS"});
    return entityTable;
}

