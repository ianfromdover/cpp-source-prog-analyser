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

std::vector<std::vector<std::string>> ParentConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    // Get parent table and populate it into our results table
    std::vector<std::vector<std::string>> result = pkb.getParent();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue() : "PARENTLHS";
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue() : "PARENTRHS";

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
        std::vector<std::vector<std::string>> entityTable = args[0]->getEntityTable(pkb);
        std::string lHeader = lhsHeader;;
        std::string rHeader = entityTable.at(0).at(1) + "1";
        // Removal of original headers in our entity table
        entityTable.erase(entityTable.begin());
        // Insertion of headers into our entity table
        entityTable.insert(entityTable.begin(), {lHeader, rHeader});
        table.add(entityTable);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()};
        table.filterByColumnValues(rhsHeader, intVals);
    }
    if (isStatementSynonym(rhsEntityType)) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        std::string lHeader = rhsHeader;
        std::string rHeader = entityTable.at(0).at(1) + "2";
        // Removal of original headers in our entity table
        entityTable.erase(entityTable.begin());
        // Insertion of headers into our entity table
        entityTable.insert(entityTable.begin(), {lHeader, rHeader});
        table.add(entityTable);
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

std::string& ParentConstraint::stripCharacters(std::string& str, const std::string& chars) {
    // Find the first character position after excluding leading characters
    std::size_t first = str.find_first_not_of(chars);
    if (first == std::string::npos) {
        // If there are no characters other than the ones to strip, return an empty string
        return str = "";
    }

    // Find the position of the last character not matching the strip characters
    std::size_t last = str.find_last_not_of(chars);

    // Erase the leading and trailing characters
    str = str.substr(first, (last - first + 1));

    return str;
}