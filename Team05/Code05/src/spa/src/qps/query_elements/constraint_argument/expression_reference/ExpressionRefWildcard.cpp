//
// Created by tohzh on 17/2/2024.
//

#include "ExpressionRefWildcard.h"

std::string ExpressionRefWildcard::getEntityType() {
    return TYPE_WILDCARD;
}

std::string ExpressionRefWildcard::toString() {
    return "_ [EXPR WILDCARD]";
}

std::vector<std::string> ExpressionRefWildcard::getArgumentValue() {
    return {"_"};
}
