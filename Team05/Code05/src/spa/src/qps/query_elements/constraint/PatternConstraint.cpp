//
// Created by tohzh on 10/2/2024.
//

#include "PatternConstraint.h"
#include "pkb/apis/QueryPkb.h"


std::string PatternConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::vector<std::vector<std::string>> PatternConstraint::getRelationshipTable(QueryPkbVirtual &) {
    return {};
}
