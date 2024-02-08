//
// Created by tohzh on 8/2/2024.
//

#include "FollowsTConstraint.h"

FollowsTConstraint::FollowsTConstraint(class StatementReference& s1, class StatementReference& s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string FollowsTConstraint::getConstraintType() {
    return QueryEnums::ENUM_CONSTRAINT_TYPE[enumConstraintType::FollowsT];
}

std::vector<ConstraintArgument> FollowsTConstraint::getConstraintArguments() {
    return constraintArguments;
}