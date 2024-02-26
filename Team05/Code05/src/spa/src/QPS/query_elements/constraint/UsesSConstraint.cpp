//
// Created by tohzh on 15/2/2024.
//

#include "UsesSConstraint.h"
#include "QPS/QueryProjector/ResultTable/ResultTable.h"

UsesSConstraint::UsesSConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string UsesSConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_USESS;
}

std::vector<std::shared_ptr<ConstraintArgument>> UsesSConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> UsesSConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    // Get uses table and populate it into our results table
    std::vector<std::vector<std::string>> result = pkb.getUses();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsHeader = args[0]->getArgumentValue();
    std::string rhsHeader = args[1]->getArgumentValue();

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    std::string lhsEntityType = args[0] -> getEntityType();
    if (lhsEntityType == TYPE_INTEGER) {
        table.filterByColumnExact(lhsHeader,lhsHeader);
    }
    if (isStatementSynonym(lhsEntityType)) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[0]->getEntityTable(pkb);
        // Removal of original headers in our entity table
        entityTable.erase(entityTable.begin());
        // Insertion of headers into our entity table
        entityTable.insert(entityTable.begin(), {lhsHeader, " "});
        table.add(entityTable);
    }

    // Handling RHS by Entity Type
    std::string rhsEntityType = args[1] -> getEntityType();
    if (rhsEntityType == TYPE_VARIABLE) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        // Removal of original headers in our entity table
        entityTable.erase(entityTable.begin());
        // Insertion of headers into our entity table
        entityTable.insert(entityTable.begin(), {" ", rhsHeader});
        table.add(entityTable);
    }
    if (rhsEntityType == TYPE_QUOTED_IDENT) {
        std::string string = rhsHeader;
        std::string rhsHeaderNew = stripCharacters(string,"\"");
        table.filterByColumnExact(rhsHeader,rhsHeaderNew);
    }

    return table.getTable();
}

bool UsesSConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

std::string& UsesSConstraint::stripCharacters(std::string& str, const std::string& chars) {
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