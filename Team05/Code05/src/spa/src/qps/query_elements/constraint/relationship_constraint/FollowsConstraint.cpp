//
// Created by tohzh on 8/2/2024.
//

#include "FollowsConstraint.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

FollowsConstraint::FollowsConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<StatementReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string FollowsConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_FOLLOWS;
}

std::vector<std::shared_ptr<ConstraintArgument>> FollowsConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table FollowsConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    // Get follows table and populate it into our results table
    Table result = pkb.getFollowsTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue()[0] : "FollowsLHS";
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue()[0] : "FollowsRHS";

    if (lhsHeader==rhsHeader) {
        return {{lhsHeader}};
    }
    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[0]->getArgumentValue()[0]};
        table.filterByColumnValues(lhsHeader, intVals);
    }
    if (isStatementSynonym(lhsEntityType)) {
        // Get entity table by type
        Table entityTable = args[0]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        if (lhsEntityType != TYPE_STATEMENT) {
  //          entityTableResult.removeColumnByIndex(1);
            entityTableResult.removeAllColumnsExceptIndex(0);
        }
        table.add(entityTableResult.getTable());
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()[0]};
        table.filterByColumnValues(rhsHeader, intVals);
    }
    if (isStatementSynonym(rhsEntityType)) {
        Table entityTable = args[1]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        if (rhsEntityType != TYPE_STATEMENT) {
//            entityTableResult.removeColumnByIndex(1);
            entityTableResult.removeAllColumnsExceptIndex(0);
        }
        table.add(entityTableResult.getTable());
    }

    if (lhsHeader == "FollowsLHS"){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == "FollowsRHS"){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}

bool FollowsConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

std::size_t FollowsConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[1]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_FOLLOWS) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}
