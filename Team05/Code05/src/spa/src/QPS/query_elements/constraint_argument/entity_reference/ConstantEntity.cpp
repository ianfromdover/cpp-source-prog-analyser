//
// Created by tohzh on 15/2/2024.
//

#include "ConstantEntity.h"

std::string ConstantEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string ConstantEntity::getEntityType() {
    return TYPE_CONSTANT;
}

ConstantEntity::ConstantEntity(std::string s) {
    identifier = std::move(s);
}

std::string ConstantEntity::toString() {
    return this->identifier + " [CONST]";
}

std::string ConstantEntity::getArgumentValue() {
    return this->identifier;
}
