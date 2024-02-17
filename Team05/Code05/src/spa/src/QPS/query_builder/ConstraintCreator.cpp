//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintCreator.h"

void ConstraintCreator::reset() {
    constraintClause.reset();
}

std::shared_ptr<Constraint> ConstraintCreator::build() {
    return constraintClause;
}
