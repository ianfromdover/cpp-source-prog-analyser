//
// Created by tohzh on 15/2/2024.
//

#include "UsesPConstraint.h"
#include "qps/query_projector/ResultTable.h"

UsesPConstraint::UsesPConstraint(std::shared_ptr<EntityReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string UsesPConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_USESP;
}

std::vector<std::shared_ptr<ConstraintArgument>> UsesPConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> UsesPConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        Table wholeSet = pkb.getUsesPTable();
        Table subSet = getTable(pkb);
        return ResultTable::minusTable(wholeSet, subSet);
    } else {
        return getTable(pkb);
    }
}

std::string& UsesPConstraint::stripCharacters(std::string& str, const std::string& chars) {
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

Table UsesPConstraint::getTable(QueryPkbVirtual &pkb) {
    // Get follows table and populate it into our results table
    std::vector<std::vector<std::string>> result = pkb.getUsesPTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = lhsEntityType == TYPE_PROCEDURE ? args[0]->getArgumentValue()[0] : HEADER_USESPLHS;
    std::string rhsHeader = rhsEntityType == TYPE_VARIABLE ? args[1]->getArgumentValue()[0] : HEADER_USESPRHS;

    if (lhsHeader==rhsHeader) {
        return {{lhsHeader}};
    }

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_PROCEDURE) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[0]->getEntityTable(pkb);
        table.add(entityTable);
    }
    if (lhsEntityType == TYPE_QUOTED_IDENT){
        std::string string1=args[0]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(lhsHeader,stripped);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_VARIABLE) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        table.add(entityTable);
    }
    if (rhsEntityType == TYPE_QUOTED_IDENT){
        std::string string1=args[1]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(rhsHeader,stripped);
    }

    if (lhsHeader == HEADER_USESPLHS){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == HEADER_USESPRHS){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}
