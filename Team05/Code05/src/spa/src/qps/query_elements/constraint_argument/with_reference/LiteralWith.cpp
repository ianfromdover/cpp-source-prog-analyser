//
// Created by tohzh on 20/3/2024.
//

#include "LiteralWith.h"

LiteralWith::LiteralWith(std::string i) {
    this->value = std::move(i);
}

std::string LiteralWith::getEntityType() {
    return TYPE_LITERAL_WITH;
}

std::string LiteralWith::toString() {
    return this->value + " [LITERAL WITH]";
}

std::string LiteralWith::getArgumentValue() {
    return this->value;
}

std::vector<std::vector<std::string>> LiteralWith::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = getRawTable(pkb);
    entityTable.insert(entityTable.begin(), {"LiteralWith"});
    return entityTable;
}


std::vector<std::vector<std::string>> LiteralWith::getRawTable(QueryPkbVirtual &pkb) {
    std::vector<std::vector<std::string>> table = {{this->value}};
    return table;
}

void LiteralWith::setVariable(std::shared_ptr<QueryObject>) {
    // do nothing
}


