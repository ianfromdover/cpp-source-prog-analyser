//
// Created by tohzh on 8/2/2024.
//

#include "EntityRefWildcard.h"
#include "qps/exceptions/QPSException.h"

std::string EntityRefWildcard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string EntityRefWildcard::toString() {
    return "_ [ENT WILDCARD]";
}

std::string EntityRefWildcard::getArgumentValue() {
    return "_";
}

Table EntityRefWildcard::getEntityTable(QueryPkbVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}
