//
// Created by tohzh on 8/2/2024.
//

#include "FollowsConstraint.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

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

Table FollowsConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        Table wholeSet = getFullTable(pkb);
        Table subSet = getTable(pkb);
        Table result = ResultTable::minusTable(wholeSet, subSet);
//        cout << ResultTable(wholeSet).toString();
//        cout << "*********************";
        return result;
    } else {
        return getTable(pkb);
    }
}

Table FollowsConstraint::getFullTable(QueryPkbVirtual &pkb){
  std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
  std::string lhsEntityType = args[0] -> getEntityType();
  std::string rhsEntityType = args[1] -> getEntityType();

  if (isStatementSynonym(lhsEntityType) || isStatementSynonym(rhsEntityType)) {
    ResultTable t;
    if (isStatementSynonym(lhsEntityType)) {
      t.add(args[0]->getEntityTable(pkb));
    }
    if (isStatementSynonym(rhsEntityType)) {
      t.add(args[1]->getEntityTable(pkb));
    }
    return t.getTable();;
  } else {
    return pkb.getFollowsTable();
  }
}

bool FollowsConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

Table FollowsConstraint::getTable(QueryPkbVirtual &pkb) {
    // Get follows table and populate it into our results table
    Table result = pkb.getFollowsTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue()[0] : HEADER_FOLLOWSLHS;
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue()[0] : HEADER_FOLLOWSRHS;

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

    if (lhsHeader == HEADER_FOLLOWSLHS){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == HEADER_FOLLOWSRHS){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}
