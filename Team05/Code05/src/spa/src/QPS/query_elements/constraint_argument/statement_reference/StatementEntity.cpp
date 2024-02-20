//
// Created by tohzh on 8/2/2024.
//

#include "StatementEntity.h"

std::string StatementEntity::getReturnType() {
    return RETURN_TYPE_STATEMENT;
}

std::string StatementEntity::getEntityType() {
    return RETURN_TYPE_STATEMENT;
}

StatementEntity::StatementEntity(std::string s) {
    identifier = std::move(s);
}

std::string StatementEntity::getArgumentValue() {
    return StatementReference::getArgumentValue();
}
