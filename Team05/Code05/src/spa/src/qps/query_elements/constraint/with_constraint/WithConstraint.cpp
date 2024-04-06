//
// Created by tohzh on 20/3/2024.
//

#include "WithConstraint.h"


WithConstraint::WithConstraint(std::shared_ptr<WithReference> s1, std::shared_ptr<WithReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string WithConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_WITH;
}

std::string WithConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_WITH;
}

std::vector<std::shared_ptr<ConstraintArgument>> WithConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> WithConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    // Get uses table and populate it into our results table
    std::vector<std::vector<std::string>> result;
    return result;
}

bool WithConstraint::isVariable(std::string s) {
    return s == TYPE_VAR_WITH;
}

std::size_t WithConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_WITH) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}
