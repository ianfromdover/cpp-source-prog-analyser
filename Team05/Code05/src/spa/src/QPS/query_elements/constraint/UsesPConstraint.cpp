//
// Created by tohzh on 15/2/2024.
//

#include "UsesPConstraint.h"

UsesPConstraint::UsesPConstraint(std::shared_ptr<EntityReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string UsesPConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_USESP;
}

std::vector<std::shared_ptr<ConstraintArgument>> UsesPConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> UsesPConstraint::getRelationshipTable(QueryPKBVirtual &) {
    return {};
}
