//
// Created by tohzh on 20/2/2024.
//

#include "Constraint.h"

std::string Constraint::toString() {
    return getConstraintType() + "(" + this->getConstraintArguments()[0]->toString()
    + ", " + this->getConstraintArguments()[1]->toString() + ")";
}

std::pair<Column<std::string>, Column<std::string>> Constraint::getRelationshipTable() {
    return std::pair<Column<std::string>, Column<std::string>>();
}
