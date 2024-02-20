//
// Created by tohzh on 15/2/2024.
//

#include "ExpressionSpec.h"

#include <utility>

std::string ExpressionSpec::getArgumentValue() {
    return regularExpression;
}

std::string ExpressionSpec::getEntityType() {
    return RETURN_TYPE_EXPRESSION;
}

ExpressionSpec::ExpressionSpec(std::string s) {
    regularExpression = std::move(s);
}
