//
// Created by tohzh on 8/2/2024.
//

#include "IntegerArgument.h"
#include "qps/Exceptions/QpsException.h"

std::string IntegerArgument::getArgumentValue() {
    return to_string(this->value);
}

std::string IntegerArgument::getEntityType() {
    return TYPE_INTEGER;
}

std::string IntegerArgument::toString() {
    return to_string(this->value) + " [INTEGER]";
}

Table IntegerArgument::getEntityTable(QueryPkbVirtual &pkb) {
    throw QpsException("Invalid PKB Query");
}

