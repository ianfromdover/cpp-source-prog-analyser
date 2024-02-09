//
// Created by tohzh on 8/2/2024.
//

#include "StatementEntity.h"

std::string StatementEntity::getReturnType() {
    return QueryEnums::ENUM_RETURN_TYPE[enumReturnType::Statement];
}

std::string StatementEntity::getEntityType() {
    return QueryEnums::ENUM_RETURN_TYPE[enumReturnType::Statement];
}
