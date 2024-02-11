//
// Created by tohzh on 8/2/2024.
//

#include "WhileEntity.h"


std::string WhileEntity::getReturnType() {
    return RETURN_TYPE_WHILE;
}

std::string WhileEntity::getEntityType() {
    return RETURN_TYPE_WHILE;
}

WhileEntity::WhileEntity(std::string s) {
    identifier = std::move(s);
}
