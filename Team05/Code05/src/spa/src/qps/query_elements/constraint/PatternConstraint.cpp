//
// Created by tohzh on 10/2/2024.
//

#include "PatternConstraint.h"
#include "pkb/apis/QueryPkb.h"


std::string PatternConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_PATTERN;
}

Table PatternConstraint::getRelationshipTable(QueryPkbVirtual &) {
    return {};
}

std::size_t PatternConstraint::hash() const {
    // TODO
    return 0;
}
