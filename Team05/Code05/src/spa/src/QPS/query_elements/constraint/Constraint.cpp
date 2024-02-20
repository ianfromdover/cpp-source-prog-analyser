//
// Created by tohzh on 20/2/2024.
//

#include "Constraint.h"

std::string Constraint::toString() {
    return getConstraintClass() + "(" + this->getConstraintArguments()[0]->toString()
    + ", " + this->getConstraintArguments()[1]->toString() + ")";
}
