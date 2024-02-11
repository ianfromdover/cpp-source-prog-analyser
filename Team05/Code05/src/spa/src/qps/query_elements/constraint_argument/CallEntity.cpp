//
// Created by tohzh on 8/2/2024.
//

#include "CallEntity.h"

std::string CallEntity::getReturnType() {
    return RETURN_TYPE_CALL;
}

std::string CallEntity::getEntityType() {
    return RETURN_TYPE_CALL;
}

CallEntity::CallEntity(std::string s) {
    identifier = std::move(s);
}
