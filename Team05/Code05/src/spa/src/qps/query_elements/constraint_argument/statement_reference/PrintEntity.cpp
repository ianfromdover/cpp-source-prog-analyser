//
// Created by tohzh on 8/2/2024.
//

#include "PrintEntity.h"

std::string PrintEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string PrintEntity::getEntityType() {
    return TYPE_PRINT;
}

PrintEntity::PrintEntity(std::string s) {
    identifier = std::move(s);
}

std::string PrintEntity::toString() {
    return this->identifier + " [PRINT]";
}

std::string PrintEntity::getArgumentValue() {
    return this->identifier;
}

std::vector<std::vector<std::string>> PrintEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getPrintTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(), {this->identifier, "PRINTRHS"});
    return entityTable;
}
