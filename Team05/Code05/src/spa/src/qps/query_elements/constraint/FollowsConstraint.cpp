//
// Created by tohzh on 8/2/2024.
//

#include "FollowsConstraint.h"
#include "pkb/constraintTablesNew/FollowsTableNew.h"

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

std::pair<Column<std::string>, Column<std::string>> FollowsConstraint::getRelationshipTable() {
    FollowsTableNew table; // Replace with pkb query

    std::pair<Column<std::string>,Column<std::string>> convertedTable;

    for (int i=0;i<table.table.first.getAllElements().size(); i++) {
        convertedTable.first.addElement(std::to_string(table.table.first.getElement(i)));
        convertedTable.second.addElement(std::to_string(table.table.second.getElement(i)));
    }

    return convertedTable;
}

std::pair<Column<std::string>, Column<std::string>> FollowsConstraint::getFirstArgTable() {
    return {};
}
