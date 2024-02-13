//
// Created by tohzh on 10/2/2024.
//

#include "ParentTConstraint.h"

ParentTConstraint::ParentTConstraint(std::shared_ptr<ConstraintArgument> s1, std::shared_ptr<ConstraintArgument> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ParentTConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PARENTT;
}

std::vector<std::shared_ptr<ConstraintArgument>> ParentTConstraint::getConstraintArguments() {
    return constraintArguments;
}
