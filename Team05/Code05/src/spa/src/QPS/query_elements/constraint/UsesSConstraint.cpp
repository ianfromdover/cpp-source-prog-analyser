//
// Created by tohzh on 15/2/2024.
//

#include "UsesSConstraint.h"

UsesSConstraint::UsesSConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string UsesSConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_USESS;
}

std::vector<std::shared_ptr<ConstraintArgument>> UsesSConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> UsesSConstraint::getRelationshipTable(QueryPKB &) {
    return {};
}
