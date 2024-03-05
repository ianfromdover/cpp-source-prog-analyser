//
// Created by tohzh on 15/2/2024.
//

#include "ExpressionReference.h"
#include "qps/Exceptions/QPSException.h"

std::string ExpressionReference::getReferenceType() {
    return REFERENCE_TYPE_EXPRESSION;
}

std::vector<std::vector<std::string>> ExpressionReference::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}

