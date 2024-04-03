//
// Created by sjh_9 on 1/4/2024.
//

#include "AffectsConstraint.h"

#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

AffectsConstraint::AffectsConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<StatementReference>  s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string AffectsConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_AFFECTS;
}

std::vector<std::shared_ptr<ConstraintArgument>> AffectsConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table AffectsConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    // Initialise retrieved table
    Table assign = pkb.getPatternAsgnTable();
    Table retrieved = generateCartesianProductTable(getDistinctColumnByIndex(assign,0));

    // Initialise empty result table
    Table result;

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = lhsEntityType == TYPE_ASSIGN ? args[0]->getArgumentValue()[0] : "AffectsLHS";
    std::string rhsHeader = rhsEntityType == TYPE_ASSIGN ? args[1]->getArgumentValue()[0] : "AffectsRHS";

    // Insertion of headers into our retrieved and result table
    retrieved.insert(retrieved.begin(), {lhsHeader, rhsHeader});
    result.insert(retrieved.begin(), {lhsHeader, rhsHeader});

    // Initialise retrieved table as ResultTable to conduct operations
    ResultTable table(retrieved);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[0]->getArgumentValue()};
        table.filterByColumnValues(lhsHeader, intVals);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()};
        table.filterByColumnValues(rhsHeader, intVals);
    }

    // Retrieve rawTable
    auto rawTable = table.getTable();
    // Remove header used for operations
    auto noHeaderTable = rawTable.erase(rawTable.begin());
    // Check against PKB to see if there is a NextT relationship
    for (const auto& row : rawTable) {
        if (pkb.checkNextT(stoi(row.at(0)), stoi(row.at(1)))) {
            result.push_back({row.at(0), row.at(1)});
        }
    }

    // Initialise result table as ResultTable to conduct operations
    ResultTable final(result);

    // Remove columns by header
    if (lhsHeader == "AffectsLHS"){
        final.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == "AffectsRHS"){
        final.removeColumnByHeader(rhsHeader);
    }

    return final.getTable();
}

Table AffectsConstraint::generateCartesianProductTable(const vector<string>& table) {
    vector<vector<string>> product;
    for (const auto& col1 : table) {
        for (const auto& col2 : table) {
            product.push_back({col1, col2});
        }
    }
    return product;
}

vector<string> AffectsConstraint::getDistinctColumnByIndex(const Table& entityTable, int index) {
    std::set<std::string> uniqueValues;
    for (const auto& row : entityTable) {
        if (!row.empty()) {
            uniqueValues.insert(row[index]);
        }
    }
    std::vector<std::string> result(uniqueValues.begin(), uniqueValues.end());
    return result;
}