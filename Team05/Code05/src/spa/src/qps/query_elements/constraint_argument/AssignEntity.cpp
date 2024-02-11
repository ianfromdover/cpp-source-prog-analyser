//
// Created by tohzh on 8/2/2024.
//

#include "AssignEntity.h"

#include <utility>

std::string AssignEntity::getReturnType() {
    return RETURN_TYPE_ASSIGN;
}

std::string AssignEntity::getEntityType() {
    return RETURN_TYPE_ASSIGN;
}

AssignEntity::AssignEntity(std::string s) {
    identifier = std::move(s);
}
