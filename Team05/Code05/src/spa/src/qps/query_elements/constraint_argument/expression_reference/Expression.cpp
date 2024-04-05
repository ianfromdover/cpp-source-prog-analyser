//
// Created by tohzh on 15/2/2024.
//

#include "Expression.h"
#include "qps/exceptions/QPSException.h"

#include <utility>

std::vector<std::string> Expression::getArgumentValue() {
    return {regularExpression};
}

std::string Expression::getEntityType() {
    return TYPE_EXPRESSION;
}

Expression::Expression(std::string s) {
    regularExpression = std::move(s);
}

std::string Expression::toString() {
    return this->regularExpression + " [EXPR]";
}

Table Expression::getEntityTable(QueryPkbVirtual &pkb) {
    throw QPSException(ERROR_INVALID_QUERY);
}

std::vector<std::vector<std::string>> Expression::getRawTable(QueryPkbVirtual &pkb) {
    throw QPSException(ERROR_INVALID_QUERY);
}
