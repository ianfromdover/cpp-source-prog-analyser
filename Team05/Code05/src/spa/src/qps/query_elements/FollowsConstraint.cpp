//
// Created by tohzh on 8/2/2024.
//

#include "FollowsConstraint.h"

FollowsConstraint::FollowsConstraint(class StatementReference* s1, class StatementReference* s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string FollowsConstraint::getConstraintType() {
    return QueryEnums::ENUM_CONSTRAINT_TYPE[enumConstraintType::Follows];
}

std::vector<ConstraintArgument*> FollowsConstraint::getConstraintArguments() {
    return constraintArguments;
}
