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

Table AffectsConstraint::getAffectsTable(QueryPkbVirtual & pkb) {
    // Initialise retrieved table
    Table assign = pkb.getPatternAsgnTable();
    Table retrieved = generateCartesianProductTable(getDistinctColumnByIndex(assign,0));
    // Initialise empty result table
    Table result;
    for (const auto& row : retrieved) {
        if (pkb.checkNextT(stoi(row.at(0)), stoi(row.at(1)))) {
            result.push_back({row.at(0), row.at(1)});
        }
    }
    return result;
}

Table AffectsConstraint::getTable(QueryPkbVirtual & pkb) {

    // Initialise empty result table
    Table result = getAffectsTable(pkb);

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = (lhsEntityType == TYPE_STATEMENT || lhsEntityType == TYPE_ASSIGN ) ? args[0]->getArgumentValue()[0] : HEADER_AFFECTSLHS;
    std::string rhsHeader = (rhsEntityType == TYPE_STATEMENT || rhsEntityType == TYPE_ASSIGN) ? args[1]->getArgumentValue()[0] : HEADER_AFFECTSRHS;

    if (lhsHeader == HEADER_AFFECTSLHS && !(lhsEntityType  == TYPE_INTEGER || lhsEntityType == TYPE_WILDCARD)) {
        return {{}};
    }

    if (rhsHeader == HEADER_AFFECTSRHS && !(rhsEntityType  == TYPE_INTEGER || rhsEntityType  == TYPE_WILDCARD)) {
        return {{}};
    }

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

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

    removeHeaders(make_shared<ResultTable>(table));

    return table.getTable();
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

std::size_t AffectsConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[1]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_AFFECTS) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

Table AffectsConstraint::getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) {
    auto t = getAffectsTable(pkb);
    t.insert(t.begin(), getDefaultHeaders());
    return t;
}

std::vector<std::string> AffectsConstraint::getDefaultHeaders() {
    return {HEADER_AFFECTSLHS, HEADER_AFFECTSRHS};
}
