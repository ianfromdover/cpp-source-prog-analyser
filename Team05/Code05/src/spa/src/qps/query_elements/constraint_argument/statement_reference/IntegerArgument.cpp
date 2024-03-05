//
// Created by tohzh on 8/2/2024.
//

#include "IntegerArgument.h"
#include "qps/Exceptions/QPSException.h"

std::string IntegerArgument::getArgumentValue() {
    return to_string(this->value);
}

std::string IntegerArgument::getEntityType() {
    return TYPE_INTEGER;
}

std::string IntegerArgument::toString() {
    return to_string(this->value) + " [INTEGER]";
}

std::vector<std::vector<std::string>> IntegerArgument::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid PKB Query");
}

