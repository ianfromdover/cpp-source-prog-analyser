//
// Created by tohzh on 15/2/2024.
//

#include "AssignPatternConstraint.h"
#include "qps/query_projector/ResultTable.h"
#include "common/StringUtils.h"

#include <utility>

AssignPatternConstraint::AssignPatternConstraint(std::shared_ptr<EntityReference> arg1,
                                                 std::shared_ptr<ExpressionReference> arg2, std::shared_ptr<AssignEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintArguments.push_back(arg2);
    constraintIdentifier = std::move(assignment);
}

std::string AssignPatternConstraint::getConstraintType() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::shared_ptr<AssignEntity> AssignPatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> AssignPatternConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table AssignPatternConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    Table temp = pkb.getPatternAsgnTable();
    Table res;

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
        table.filterByColumnPartial(rhsHeader,
                                    StringUtils::formatAsRegex(stripped));
    }

    for (const std::string& header : {"ASSIGNLHS", "ASSIGNRHS"}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }

    return table.getTable();
}

std::string& AssignPatternConstraint::stripCharacters(std::string& str, const std::string& chars) {
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

std::size_t AssignPatternConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue();
    std::string s2 = constraintArguments[1]->getArgumentValue();

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    // TODO: how does the pattern if, while, assign differentiate in the query object?
    hashValue ^= stringHasher(CONSTRAINT_CLASS_PATTERN) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}
