//
// Created by tohzh on 10/2/2024.
//

#include "ParentConstraint.h"

ParentConstraint::ParentConstraint(class StatementReference* s1, class StatementReference* s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ParentConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PARENT;
}

std::vector<ConstraintArgument*> ParentConstraint::getConstraintArguments() {
    return constraintArguments;
}
