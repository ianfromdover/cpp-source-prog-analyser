//
// Created by tohzh on 20/2/2024.
//

#include "ExpressionWithWildcard.h"
#include "QPS/Exceptions/QPSException.h"

std::string ExpressionWithWildcard::getArgumentValue() {
    return regularExpression;
}

std::string ExpressionWithWildcard::getEntityType() {
    return TYPE_EXPRESSION_W_WILDCARD;
}

ExpressionWithWildcard::ExpressionWithWildcard(std::string s) {
    regularExpression = std::move(s);
}

std::string ExpressionWithWildcard::toString() {
    return this->regularExpression + " [EXPR WITH WILDCARD]";
}

std::vector<std::vector<std::string>> ExpressionWithWildcard::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}
