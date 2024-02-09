//
// Created by tohzh on 8/2/2024.
//

#include "StatementReference.h"

std::string StatementReference::getReferenceType() {
    return QueryEnums::ENUM_RETURN_TYPE[enumReturnType::Statement];
}

std::string StatementReference::getArgumentValue() {
    return "";
}
