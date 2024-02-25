//
// Created by tohzh on 8/2/2024.
//

#include "FollowsConstraint.h"
#include "pkb/constraintTablesNew/FollowsTableNew.h"
#include "pkb/apis/QueryPKB.h"

FollowsConstraint::FollowsConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<StatementReference>  s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string FollowsConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_FOLLOWS;
}

std::vector<std::shared_ptr<ConstraintArgument>> FollowsConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> FollowsConstraint::getRelationshipTable(QueryPKBVirtual &) {
    return {};
}

std::pair<Column<std::string>, Column<std::string>> FollowsConstraint::getFirstArgTable() {
    return {};
}
