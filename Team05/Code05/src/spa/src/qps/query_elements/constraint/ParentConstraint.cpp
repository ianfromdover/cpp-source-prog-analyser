//
// Created by tohzh on 10/2/2024.
//

#include "ParentConstraint.h"
#include "QPS/QueryProjector/ResultTable/ResultTable.h"

ParentConstraint::ParentConstraint(std::shared_ptr<StatementReference>  s1, std::shared_ptr<StatementReference>  s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ParentConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PARENT;
}

std::vector<std::shared_ptr<ConstraintArgument>> ParentConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> ParentConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    return pkb.getParent();
}
