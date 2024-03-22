//
// Created by tohzh on 15/2/2024.
//

#include "ExpressionReference.h"
#include "qps/Exceptions/QpsException.h"

std::string ExpressionReference::getReferenceType() {
    return REFERENCE_TYPE_EXPRESSION;
}

Table ExpressionReference::getEntityTable(QueryPkbVirtual &pkb) {
    throw QpsException("Invalid QPS Query");
}

