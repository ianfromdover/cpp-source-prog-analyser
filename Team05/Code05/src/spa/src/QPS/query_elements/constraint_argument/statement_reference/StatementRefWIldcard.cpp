//
// Created by tohzh on 15/2/2024.
//

#include "StatementRefWildcard.h"


std::string StatementRefWildCard::getEntityType() {
    return RETURN_TYPE_WILDCARD;
}

std::string StatementRefWildCard::toString() {
    return "_ [STMT WILDCARD]";
}