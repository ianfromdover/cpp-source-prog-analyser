//
// Created by tohzh on 8/2/2024.
//

#include "IfEntity.h"

std::string IfEntity::getReturnType() {
    return RETURN_TYPE_IF;
}

std::string IfEntity::getEntityType() {
    return RETURN_TYPE_IF;
}

IfEntity::IfEntity(std::string s) {
    identifier = std::move(s);
}
