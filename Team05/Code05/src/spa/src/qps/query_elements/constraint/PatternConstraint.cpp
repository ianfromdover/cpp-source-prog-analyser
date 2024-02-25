//
// Created by tohzh on 10/2/2024.
//

#include "PatternConstraint.h"


std::string PatternConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::pair<Column<std::string>, Column<std::string>> PatternConstraint::getRelationshipTable() {
    return Constraint::getRelationshipTable();
}
