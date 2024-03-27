//
// Created by tohzh on 15/2/2024.
//

#include "ExpressionReference.h"
#include "qps/exceptions/QPSException.h"

std::string ExpressionReference::getReferenceType() {
    return REFERENCE_TYPE_EXPRESSION;
}

Table ExpressionReference::getEntityTable(QueryPkbVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}

std::vector<std::vector<std::string>> ExpressionReference::getRawTable(QueryPkbVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}

