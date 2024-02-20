//
// Created by tohzh on 15/2/2024.
//

#include "VariableEntity.h"

std::string VariableEntity::getReturnType() {
    return RETURN_TYPE_VARIABLE;
}

std::string VariableEntity::getEntityType() {
    return RETURN_TYPE_VARIABLE;
}

VariableEntity::VariableEntity(std::string s) {
    identifier = std::move(s);
}