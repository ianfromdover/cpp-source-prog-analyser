//
// Created by tohzh on 15/2/2024.
//

#include "ProcedureEntity.h"

std::string ProcedureEntity::getReturnType() {
    return RETURN_TYPE_PROCEDURE;
}

std::string ProcedureEntity::getEntityType() {
    return RETURN_TYPE_PROCEDURE;
}

ProcedureEntity::ProcedureEntity(std::string s) {
    identifier = std::move(s);
}

std::string ProcedureEntity::toString() {
    return this->identifier + " [PROCEDURE]";
}


