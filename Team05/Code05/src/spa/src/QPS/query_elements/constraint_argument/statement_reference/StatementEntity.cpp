//
// Created by tohzh on 8/2/2024.
//

#include "StatementEntity.h"

std::string StatementEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string StatementEntity::getEntityType() {
    return TYPE_STATEMENT;
}

StatementEntity::StatementEntity(std::string s) {
    identifier = std::move(s);
}

std::string StatementEntity::getArgumentValue() {
    return this->value;
}

std::string StatementEntity::toString() {
    return this->identifier + " [STMT]";
}
