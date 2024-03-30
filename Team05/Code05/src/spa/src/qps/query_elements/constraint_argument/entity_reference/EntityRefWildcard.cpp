//
// Created by tohzh on 8/2/2024.
//

#include "EntityRefWildCard.h"
#include "qps/Exceptions/QPSException.h"

std::string EntityRefWildcard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string EntityRefWildcard::toString() {
    return "_ [ENT WILDCARD]";
}

std::string EntityRefWildcard::getArgumentValue() {
    return "_";
}

std::vector<std::vector<std::string>> EntityRefWildcard::getEntityTable(QueryPkbVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}

std::vector<std::vector<std::string>> EntityRefWildcard::getRawTable(QueryPkbVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}
