//
// Created by tohzh on 15/2/2024.
//

#include "Expression.h"
#include "qps/Exceptions/QpsException.h"

#include <utility>

std::string Expression::getArgumentValue() {
    return regularExpression;
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
    throw QpsException("Invalid QPS Query");
}
