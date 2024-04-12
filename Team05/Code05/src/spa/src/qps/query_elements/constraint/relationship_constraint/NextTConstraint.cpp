//
// Created by sjh_9 on 1/4/2024.
//

#include "NextTConstraint.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

NextTConstraint::NextTConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<StatementReference>  s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string NextTConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_NEXTT;
}

std::vector<std::shared_ptr<ConstraintArgument>> NextTConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table NextTConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        Table wholeSet = getNextTTable(pkb);
        Table subSet = getTable(pkb);
        return ResultTable::minusTable(wholeSet, subSet);
    } else {
        return getTable(pkb);
    }
}

Table NextTConstraint::getNextTTable(QueryPkbVirtual & pkb) {
    // Initialise retrieved table
    vector<string> flattened = flattenTable(pkb.getStmtTable());
    Table retrieved = generateCartesianProductTable(flattened);
    // Initialise empty result table
    Table result;
    for (const auto& row : retrieved) {
        if (pkb.checkNextT(stoi(row.at(0)), stoi(row.at(1)))) {
            result.push_back({row.at(0), row.at(1)});
        }
    }
    ResultTable final(result);
    return result;
}

Table NextTConstraint::getTable(QueryPkbVirtual & pkb) {
    // Initialise retrieved table
    vector<string> flattened = flattenTable(pkb.getStmtTable());
    Table retrieved = generateCartesianProductTable(flattened);

    // Initialise empty result table
    Table result;

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue()[0] : HEADER_NEXTTLHS;
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue()[0] : HEADER_NEXTTRHS;

    // Insertion of headers into our retrieved and result table
    retrieved.insert(retrieved.begin(), {lhsHeader, rhsHeader});
    result.insert(result.begin(), {lhsHeader, rhsHeader});

    // Initialise retrieved table as ResultTable to conduct operations
    ResultTable table(retrieved);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[0]->getArgumentValue()};
        table.filterByColumnValues(lhsHeader, intVals);
    }
    if (isStatementSynonym(lhsEntityType)) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[0]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        if (lhsEntityType != TYPE_STATEMENT) {
            entityTableResult.removeColumnByIndex(1);
            table.add(entityTableResult.getTable());
        }
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()};
        table.filterByColumnValues(rhsHeader, intVals);
    }
    if (isStatementSynonym(rhsEntityType)) {
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        if (rhsEntityType != TYPE_STATEMENT) {
            entityTableResult.removeColumnByIndex(1);
            table.add(entityTableResult.getTable());
        }
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
//    if (lhsHeader == HEADER_NEXTTLHS){
//        final.removeColumnByHeader(lhsHeader);
//    }
//    if (rhsHeader == HEADER_NEXTTRHS){
//        final.removeColumnByHeader(rhsHeader);
//    }
    removeHeaders({HEADER_NEXTTLHS, HEADER_NEXTTRHS}, make_shared<ResultTable>(table));

    return final.getTable();
}

bool NextTConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

vector<string> NextTConstraint::flattenTable(const Table& table) {
    vector<string> flattened;
    for (const auto& row : table) {
        for (const auto& val : row) {
            flattened.push_back(val);
        }
    }
    return flattened;
}

Table NextTConstraint::generateCartesianProductTable(const vector<string>& table) {
    vector<vector<string>> product;
    for (const auto& col1 : table) {
        for (const auto& col2 : table) {
            product.push_back({col1, col2});
        }
    }
    return product;
}

std::size_t NextTConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[1]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_NEXTT) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}




