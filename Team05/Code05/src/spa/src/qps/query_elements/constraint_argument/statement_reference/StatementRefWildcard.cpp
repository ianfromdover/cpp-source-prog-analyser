//
// Created by tohzh on 15/2/2024.
//

#include "StatementRefWildcard.h"
#include "qps/Exceptions/QpsException.h"


std::string StatementRefWildcard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string StatementRefWildcard::toString() {
    return "_ [STMT WILDCARD]";
}

std::string StatementRefWildcard::getArgumentValue() {
    return "_";
}

Table StatementRefWildcard::getEntityTable(QueryPkbVirtual &pkb) {
    throw QpsException("Invalid PKB Query");
}


