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
    // join based on the header: HEADER_ENT_WITH_TOMERGE
    auto table1 = constraintArguments[0]->getEntityTable(pkb);
    auto table2 = constraintArguments[1]->getEntityTable(pkb);
    table result = ResultTable::nestedLoopJoin(table1, table2);
    ResultTable ans = ResultTable(result);
    ans.removeColumnByHeader(HEADER_ENT_WITH_TOMERGE);
    return ans.getTable();
}

bool WithConstraint::isVariable(std::string s) {
    return s == TYPE_VAR_WITH;
}
