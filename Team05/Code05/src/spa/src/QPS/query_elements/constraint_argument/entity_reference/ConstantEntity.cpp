//
// Created by tohzh on 15/2/2024.
//

#include "ConstantEntity.h"

std::string ConstantEntity::getReturnType() {
    return RETURN_TYPE_CONSTANT;
}

std::string ConstantEntity::getEntityType() {
    return RETURN_TYPE_CONSTANT;
}

ConstantEntity::ConstantEntity(std::string s) {
    identifier = std::move(s);
}

std::string ConstantEntity::toString() {
    return this->identifier + " [CONST]";
}
