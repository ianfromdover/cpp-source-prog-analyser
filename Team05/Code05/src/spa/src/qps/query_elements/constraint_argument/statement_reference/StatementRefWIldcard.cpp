//
// Created by tohzh on 15/2/2024.
//

#include "StatementRefWildcard.h"
#include "qps/Exceptions/QPSException.h"


std::string StatementRefWildCard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string StatementRefWildCard::toString() {
    return "_ [STMT WILDCARD]";
}

std::string StatementRefWildCard::getArgumentValue() {
    return "_";
}

std::vector<std::vector<std::string>> StatementRefWildCard::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid PKB Query");
}


