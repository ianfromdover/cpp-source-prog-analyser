//
// Created by tohzh on 10/2/2024.
//

#include "ParentTConstraint.h"

ParentTConstraint::ParentTConstraint(class StatementReference* s1, class StatementReference* s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ParentTConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PARENTT;
}

std::vector<ConstraintArgument*> ParentTConstraint::getConstraintArguments() {
    return constraintArguments;
}
