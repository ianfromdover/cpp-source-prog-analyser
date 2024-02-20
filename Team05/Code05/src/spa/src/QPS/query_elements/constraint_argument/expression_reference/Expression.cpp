//
// Created by tohzh on 15/2/2024.
//

#include "Expression.h"

#include <utility>

std::string Expression::getArgumentValue() {
    return regularExpression;
}

std::string Expression::getEntityType() {
    return RETURN_TYPE_EXPRESSION;
}

Expression::Expression(std::string s) {
    regularExpression = std::move(s);
}
