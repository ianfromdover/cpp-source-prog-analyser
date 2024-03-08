//
// Created by tohzh on 15/2/2024.
//

#include "ConcretePatternConstraint.h"
#include "qps/QueryProjector/ResultTable/ResultTable.h"

#include <utility>

ConcretePatternConstraint::ConcretePatternConstraint(std::shared_ptr<EntityReference> arg1,
            std::shared_ptr<ExpressionReference> arg2, std::shared_ptr<AssignEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintArguments.push_back(arg2);
    constraintIdentifier = std::move(assignment);
}

std::string ConcretePatternConstraint::getConstraintType() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::shared_ptr<AssignEntity> ConcretePatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> ConcretePatternConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> ConcretePatternConstraint::getRelationshipTable(QueryPKBVirtual & pkb) {
    std::vector<std::vector<std::string>> temp = pkb.getPatternAsgn();
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
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue() : "ASSIGNLHS";
    std::string rhsHeader = "ASSIGNRHS";

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
        table.filterByColumnPartial(rhsHeader,stripped);
    }

    for (const std::string& header : {"ASSIGNLHS", "ASSIGNRHS"}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }

    return table.getTable();
}

std::string& ConcretePatternConstraint::stripCharacters(std::string& str, const std::string& chars) {
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
