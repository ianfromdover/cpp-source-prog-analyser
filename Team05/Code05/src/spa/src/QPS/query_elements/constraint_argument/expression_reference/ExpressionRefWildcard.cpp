//
// Created by tohzh on 17/2/2024.
//

#include "ExpressionRefWildcard.h"

std::string ExpressionRefWildcard::getEntityType() {
    return RETURN_TYPE_WILDCARD;
}

std::string ExpressionRefWildcard::toString() {
    return "_ [EXPR WILDCARD]";
}
