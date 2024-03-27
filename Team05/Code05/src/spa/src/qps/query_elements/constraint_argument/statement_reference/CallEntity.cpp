//
// Created by tohzh on 8/2/2024.
//

#include "CallEntity.h"

std::string CallEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string CallEntity::getEntityType() {
    return TYPE_CALL;
}

CallEntity::CallEntity(std::string s) {
    identifier = std::move(s);
}

std::string CallEntity::toString() {
    return this->identifier + " [CALL]";
}

std::string CallEntity::getArgumentValue() {
    return this->identifier;
}

Table CallEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getCallTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier, "CALLRHS"});
    return entityTable;
}

std::vector<std::vector<std::string>> CallEntity::getRawTable(QueryPkbVirtual &pkb) {
    return pkb.getCallTable();
}
