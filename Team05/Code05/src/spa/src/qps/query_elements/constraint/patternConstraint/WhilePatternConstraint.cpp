//
// Created by tohzh on 21/3/2024.
//

#include "WhilePatternConstraint.h"

// Second argument in patternConstraint can only be wildcard.
WhilePatternConstraint::WhilePatternConstraint(std::shared_ptr<EntityReference> arg1, std::shared_ptr<WhileEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintIdentifier = std::move(assignment);
}

std::string WhilePatternConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PATTERN_WHILE;
}

std::shared_ptr<Entity> WhilePatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> WhilePatternConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> WhilePatternConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    Table res = pkb.getPatternWhileTable();

    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();

    std::string stmtHeader = constraintIdentifier->getIdentifier();
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue()[0] : "WHILEPATLHS";

    res.insert(res.begin(), {stmtHeader, lhsHeader});
    ResultTable table(res);

    if (args[0]->getEntityType() == TYPE_VARIABLE){
        std::vector<std::vector<std::string>> t = args[0]->getEntityTable(pkb);
        ResultTable entityTable(t);
//        entityTable.removeColumnByIndex(0);
        table.add(entityTable.getTable());
    } else if (args[0]->getEntityType() == TYPE_QUOTED_IDENT){
        std::string string1=args[0]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(lhsHeader,stripped);
    }

    for (const std::string& header : {"WHILEPATLHS"}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }

    return table.getTable();
}

