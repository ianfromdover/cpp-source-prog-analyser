//
// Created by tohzh on 8/2/2024.
//

#include "PrintEntity.h"

std::string PrintEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string PrintEntity::getEntityType() {
    return TYPE_PRINT;
}

PrintEntity::PrintEntity(std::string s) {
    identifier = std::move(s);
}

std::string PrintEntity::toString() {
    return this->identifier + " [PRINT]";
}

std::string PrintEntity::getArgumentValue() {
    return this->identifier;
}
