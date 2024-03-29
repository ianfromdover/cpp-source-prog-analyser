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
    // TODO: what elements do we hash for this case?
//    std::hash<std::string> stringHasher;
//
//    std::string s1 = constraintArguments[0]->getArgumentValue();
//    std::string s2 = constraintArguments[1]->getArgumentValue();
//
//    std::size_t hashValue = 0;
//
//    // Combine hash values for both stringVars while maintaining their order
//    hashValue ^= stringHasher(CONSTRAINT_TYPE_PARENT) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
//    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
//    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
//
//    return hashValue;
    return 0;
}
