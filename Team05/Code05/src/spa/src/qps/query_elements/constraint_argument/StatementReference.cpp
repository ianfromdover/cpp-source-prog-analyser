//
// Created by tohzh on 8/2/2024.
//

#include "StatementReference.h"

std::string StatementReference::getReferenceType() {
    return REFERENCE_TYPE_STATEMENT;
}

std::string StatementReference::getArgumentValue() {
    return "s";
}
