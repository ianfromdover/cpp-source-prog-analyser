//
// Created by tohzh on 10/2/2024.
//

#include "SynAssignDeclarationRule.h"

std::string SynAssignDeclarationRule::validate(QueryObject& qo) {
    bool followsRule = followsSynAssignDeclaration(qo);
    if (followsRule) {
        return "";
    } else {
        return QueryEnums::ENUM_VALIDATION_RULE[enumValidationRule::SynAssignDeclarationRule];
    }
}

bool SynAssignDeclarationRule::followsSynAssignDeclaration(QueryObject& qo) {
    return true;
}