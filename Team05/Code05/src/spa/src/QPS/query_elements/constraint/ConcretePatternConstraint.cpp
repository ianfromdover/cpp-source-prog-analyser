//
// Created by tohzh on 15/2/2024.
//

#include "ConcretePatternConstraint.h"

#include <utility>

ConcretePatternConstraint::ConcretePatternConstraint(std::shared_ptr<EntityReference> arg1,
            std::shared_ptr<ExpressionReference> arg2, std::shared_ptr<AssignEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintArguments.push_back(arg2);
    constraintIdentifier = std::move(assignment);
}

std::string ConcretePatternConstraint::getConstraintType() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::shared_ptr<AssignEntity> ConcretePatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> ConcretePatternConstraint::getConstraintArguments() {
    return constraintArguments;
}
