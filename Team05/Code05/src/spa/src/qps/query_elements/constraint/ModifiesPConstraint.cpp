//
// Created by tohzh on 15/2/2024.
//

#include "ModifiesPConstraint.h"
#include "common/StringUtils.h"

ModifiesPConstraint::ModifiesPConstraint(std::shared_ptr<EntityReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ModifiesPConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_MODIFIESP;
}

std::vector<std::shared_ptr<ConstraintArgument>> ModifiesPConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> ModifiesPConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    // Get follows table and populate it into our results table
    std::vector<std::vector<std::string>> result = pkb.getModifiesP();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = lhsEntityType == TYPE_PROCEDURE ? args[0]->getArgumentValue() : "ModifiesPLHS";
    std::string rhsHeader = rhsEntityType == TYPE_VARIABLE ? args[1]->getArgumentValue() : "ModifiesPRHS";

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
    if (lhsEntityType == TYPE_QUOTED_IDENT) {
        std::string string = args[0]->getArgumentValue();
        std::string lhsHeaderNew = StringUtils::stripCharacters(string,"\"");
        table.filterByColumnExact(lhsHeader,lhsHeaderNew);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_VARIABLE) {
        // Get entity table by type
        std::vector<std::vector<std::string>> entityTable = args[1]->getEntityTable(pkb);
        table.add(entityTable);
    }
    if (rhsEntityType == TYPE_QUOTED_IDENT) {
        std::string string = args[1]->getArgumentValue();
        std::string rhsHeaderNew = StringUtils::stripCharacters(string,"\"");
        table.filterByColumnExact(rhsHeader,rhsHeaderNew);
    }

    if (lhsHeader == "ModifiesPLHS"){
        table.removeColumnByHeader(lhsHeader);
    }
    if (rhsHeader == "ModifiesPRHS"){
        table.removeColumnByHeader(rhsHeader);
    }

    return table.getTable();
}
