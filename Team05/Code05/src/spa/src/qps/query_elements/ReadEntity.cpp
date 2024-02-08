//
// Created by tohzh on 8/2/2024.
//

#include "ReadEntity.h"

std::string ReadEntity::getReturnType() {
    return QueryEnums::ENUM_RETURN_TYPE[enumReturnType::Read];
}

std::string ReadEntity::getEntityType() {
    return QueryEnums::ENUM_RETURN_TYPE[enumReturnType::Read];
}