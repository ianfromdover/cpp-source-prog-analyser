//
// Created by tohzh on 8/2/2024.
//

#include "FollowsTConstraint.h"

FollowsTConstraint::FollowsTConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<StatementReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string FollowsTConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_FOLLOWST;
}

std::vector<std::shared_ptr<ConstraintArgument>> FollowsTConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::pair<Column<std::string>, Column<std::string>> FollowsTConstraint::getRelationshipTable() {
    return Constraint::getRelationshipTable();
}
