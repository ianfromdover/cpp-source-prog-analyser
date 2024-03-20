//
// Created by tohzh on 20/3/2024.
//

#include "IntegerWith.h"

IntegerWith::IntegerWith(std::string i) {
    this->value = std::move(i);
}

std::string IntegerWith::getEntityType() {
    return TYPE_INT_WITH;
}

std::string IntegerWith::toString() {
    return this->value + " [INT WITH]";
}

std::string IntegerWith::getArgumentValue() {
    return this->value;
}

std::vector<std::vector<std::string>> IntegerWith::getEntityTable(QueryPKBVirtual &pkb) {
    auto entityTable = getRawTable(pkb);
    entityTable.insert(entityTable.begin(), {this->value, "IntWith"});
    return entityTable;
}

std::vector<std::vector<std::string>> IntegerWith::getRawTable(QueryPKBVirtual &pkb) {
    std::vector<std::vector<std::string>> table = {{this->value}};
    return table;
}

void IntegerWith::setVariable(std::shared_ptr<QueryObject>) {
    // do nothing
}

