//
// Created by tohzh on 8/2/2024.
//

#include "ReadEntity.h"

std::string ReadEntity::getReturnType() {
    return RETURN_TYPE_READ;
}

std::string ReadEntity::getEntityType() {
    return RETURN_TYPE_READ;
}

ReadEntity::ReadEntity(std::string s) {
    identifier = std::move(s);
}

std::string ReadEntity::toString() {
    return this->identifier + " [READ]";
}
