//
// Created by tohzh on 15/2/2024.
//

#include "ModifiesPConstraint.h"

ModifiesPConstraint::ModifiesPConstraint(std::shared_ptr<EntityReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ModifiesPConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_MODIFIESP;
}

std::vector<std::shared_ptr<ConstraintArgument>> ModifiesPConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> ModifiesPConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    return pkb.getModifiesPTable();
}
