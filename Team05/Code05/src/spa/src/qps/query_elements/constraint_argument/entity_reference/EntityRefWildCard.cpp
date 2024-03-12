//
// Created by tohzh on 8/2/2024.
//

#include "EntityRefWildCard.h"
#include "qps/Exceptions/QPSException.h"

std::string EntityRefWildCard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string EntityRefWildCard::toString() {
    return "_ [ENT WILDCARD]";
}

std::string EntityRefWildCard::getArgumentValue() {
    return "_";
}

std::vector<std::vector<std::string>> EntityRefWildCard::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}
