//
// Created by tohzh on 20/3/2024.
//

#include "LiteralWith.h"
#include "common/StringUtils.h"

LiteralWith::LiteralWith(std::string i) {
    std::string str = StringUtils::stripCharacters(i, "\"");
    this->value = std::move(str);
}

std::string LiteralWith::getEntityType() {
    return TYPE_LITERAL_WITH;
}

std::string LiteralWith::toString() {
    return this->value + " [LITERAL WITH]";
}

std::vector<std::string> LiteralWith::getArgumentValue() {
    return {this->value};
}

std::vector<std::vector<std::string>> LiteralWith::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = getRawTable(pkb);
    entityTable.insert(entityTable.begin(), {HEADER_ENT_WITH_TOMERGE});
    return entityTable;
}


std::vector<std::vector<std::string>> LiteralWith::getRawTable(QueryPkbVirtual &pkb) {
    std::vector<std::vector<std::string>> table = {{this->value}};
    return table;
}

void LiteralWith::setVariable(std::shared_ptr<QueryObject>) {
    // do nothing
}


