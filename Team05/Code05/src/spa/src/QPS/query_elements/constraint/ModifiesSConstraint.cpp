//
// Created by tohzh on 15/2/2024.
//

#include "ModifiesSConstraint.h"

ModifiesSConstraint::ModifiesSConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ModifiesSConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_MODIFIESS;
}

std::vector<std::shared_ptr<ConstraintArgument>> ModifiesSConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> ModifiesSConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    return pkb.getModifies();
}
