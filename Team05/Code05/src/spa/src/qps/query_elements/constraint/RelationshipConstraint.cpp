//
// Created by tohzh on 8/2/2024.
//

#include "RelationshipConstraint.h"

std::string RelationshipConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_RELATIONSHIP;
}

std::vector<std::vector<std::string>> RelationshipConstraint::getRelationshipTable(QueryPKB &) {
    return {};
}