//
// Created by tohzh on 21/3/2024.
//

#include "WhilePatternConstraint.h"

// Second argument in patternConstraint can only be wildcard.
WhilePatternConstraint::WhilePatternConstraint(std::shared_ptr<EntityReference> arg1, std::shared_ptr<WhileEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintArguments.push_back(ConstraintArgCreator::createStatementRefWildCard());
    constraintIdentifier = std::move(assignment);
}

std::string WhilePatternConstraint::getConstraintType() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::shared_ptr<Entity> WhilePatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> WhilePatternConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> WhilePatternConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    std::vector<std::vector<std::string>> temp = pkb.getPatternAsgn(); // TODO: get pattern if
    std::vector<std::vector<std::string>> res;

    for (const auto& entry : temp){
        // guaranteed 2 columns
        std::string stmtNo = entry[0];
        std::string lhs = entry[1].substr(0, entry[1].find('='));
        std::string rhs = entry[1].substr(entry[1].find('=')+1);
        res.push_back({stmtNo, lhs,rhs});
    }

    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();

    std::string stmtHeader = constraintIdentifier->getIdentifier();
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue() : "WHILEPATLHS";
    std::string rhsHeader = "WHILEPATRHS";

    res.insert(res.begin(), {stmtHeader, lhsHeader, rhsHeader});
    ResultTable table(res);

    if (args[0]->getEntityType() == TYPE_VARIABLE){
        std::vector<std::vector<std::string>> t = args[0]->getEntityTable(pkb);
        ResultTable entityTable(t);
        entityTable.removeColumnByIndex(0);
        table.add(entityTable.getTable());
    } else if (args[0]->getEntityType() == TYPE_QUOTED_IDENT){
        std::string string1=args[0]->getArgumentValue();
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(lhsHeader,stripped);
    }

    if (args[1]->getEntityType()== TYPE_EXPRESSION){
        std::string string1=args[1]->getArgumentValue();
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(rhsHeader,stripped);
    } else if (args[1]->getEntityType()==TYPE_EXPRESSION_W_WILDCARD){
        std::string string1=args[1]->getArgumentValue();
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnPartial(rhsHeader,"\\b" + stripped + "\\b");
    }

    for (const std::string& header : {"WHILEPATLHS", "WHILEPATRHS"}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }

    return table.getTable();
}

