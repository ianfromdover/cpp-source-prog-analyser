//
// Created by tohzh on 10/2/2024.
//

#include "ParentConstraint.h"
#include "qps/QueryProjector/ResultTable/ResultTable.h"

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

Table ParentConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    // Get parent table and populate it into our results table
    Table result = pkb.getParentTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue() : "PARENTLHS";
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue() : "PARENTRHS";

    if (lhsHeader==rhsHeader) {
        return {{lhsHeader}};
    }

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[0]->getArgumentValue()};
        table.filterByColumnValues(lhsHeader, intVals);
    }
    if (isStatementSynonym(lhsEntityType)) {
        // Get entity table by type
        Table entityTable = args[0]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        entityTableResult.removeAllColumnsExceptIndex(0);
        table.add(entityTableResult.getTable());
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()};
        table.filterByColumnValues(rhsHeader, intVals);
    }
    if (isStatementSynonym(rhsEntityType)) {
        // Get entity table by type
        Table entityTable = args[1]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        entityTableResult.removeAllColumnsExceptIndex(0);
        table.add(entityTableResult.getTable());
    }

    if (lhsHeader == "PARENTLHS"){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == "PARENTRHS"){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}

bool ParentConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}