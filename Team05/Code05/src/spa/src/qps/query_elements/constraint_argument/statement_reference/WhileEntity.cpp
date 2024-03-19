//
// Created by tohzh on 8/2/2024.
//

#include "WhileEntity.h"


std::string WhileEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string WhileEntity::getEntityType() {
    return TYPE_WHILE;
}

WhileEntity::WhileEntity(std::string s) {
    identifier = std::move(s);
}

std::string WhileEntity::toString() {
    return this->identifier + " [WHILE]";
}

std::string WhileEntity::getArgumentValue() {
    return this->identifier;
}

Table WhileEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getWhileTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier, "WhileVar"});
    return entityTable;
}
