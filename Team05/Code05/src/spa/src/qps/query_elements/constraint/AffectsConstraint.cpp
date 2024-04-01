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
    // Initialise results table
    std::vector<std::vector<std::string>> result;

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = lhsEntityType ==  TYPE_ASSIGN ? args[0]->getArgumentValue() : "AffectsLHS";
    std::string rhsHeader = rhsEntityType ==  TYPE_ASSIGN ? args[1]->getArgumentValue() : "AffectsRHS";

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});

    // Stores LHS values and RHS values in a 1D vector
    std::vector<std::string> lhsValues;
    std::vector<std::string> rhsValues;

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        lhsValues.push_back(args[0]->getArgumentValue());
    }
    if (lhsEntityType == TYPE_ASSIGN) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[0]->getEntityTable(pkb);
        lhsValues = getDistinctColumnByIndex(entityTable, 0);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        rhsValues.push_back(args[1]->getArgumentValue());
    }
    if (rhsEntityType == TYPE_ASSIGN) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        rhsValues = getDistinctColumnByIndex(entityTable, 0);
    }

    // Populate results table
    for (const auto& lhsVal : lhsValues) {
        for (const auto& rhsVal : rhsValues) {
            if (pkb.checkAffects(std::stoi(lhsVal), std::stoi(rhsVal))) {
                result.push_back({lhsVal, rhsVal});
            }
        }
    }

    ResultTable table(result);

    if (lhsHeader == "AffectsLHS"){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == "AffectsRHS"){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}

std::vector<std::string> AffectsConstraint::getDistinctColumnByIndex(const table& entityTable, int index) {
    std::set<std::string> uniqueValues;
    for (const auto& row : entityTable) {
        if (!row.empty()) {
            uniqueValues.insert(row[index]);
        }
    }
    std::vector<std::string> result(uniqueValues.begin(), uniqueValues.end());
    return result;
}
