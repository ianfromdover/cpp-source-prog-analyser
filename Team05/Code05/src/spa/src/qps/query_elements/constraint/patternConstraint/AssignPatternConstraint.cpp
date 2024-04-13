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
    return CONSTRAINT_TYPE_PATTERN_ASSIGN;
}

std::shared_ptr<Entity> AssignPatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> AssignPatternConstraint::getConstraintArguments() {
    return constraintArguments;
}


Table AssignPatternConstraint::getTable(QueryPkbVirtual &pkb) {
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
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue()[0] : HEADER_ASSIGNLHS;
    std::string rhsHeader = HEADER_ASSIGNRHS;

    res.insert(res.begin(), {stmtHeader, lhsHeader, rhsHeader});
    ResultTable table(res);

    if (args[0]->getEntityType() == TYPE_VARIABLE){
        std::vector<std::vector<std::string>> t = args[0]->getEntityTable(pkb);
        ResultTable entityTable(t);
        entityTable.removeColumnByIndex(0);
        table.add(entityTable.getTable());
    } else if (args[0]->getEntityType() == TYPE_QUOTED_IDENT){
        std::string string1=args[0]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(lhsHeader,stripped);
    }

    if (args[1]->getEntityType()== TYPE_EXPRESSION){
        std::string string1=args[1]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(rhsHeader,stripped);
    } else if (args[1]->getEntityType()==TYPE_EXPRESSION_W_WILDCARD){
        std::string string1=args[1]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnPartial(rhsHeader,
                                    StringUtils::formatAsRegex(stripped));
    }

    for (const std::string& header : {HEADER_ASSIGNLHS, HEADER_ASSIGNRHS}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }
//    removeHeaders({HEADER_ASSIGNLHS, HEADER_ASSIGNRHS}, table);

    return table.getTable();
}



std::size_t AssignPatternConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_PATTERN_ASSIGN) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

Table AssignPatternConstraint::getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) {
    auto t = pkb.getPatternAsgnTable();
    t.insert(t.begin(), getDefaultHeaders());
    ResultTable r(t);
    r.removeColumnByIndex(1);
    return r.getTable();
}

vector<string> AssignPatternConstraint::getDefaultHeaders() {
    return {constraintIdentifier->getIdentifier(), HEADER_ASSIGNRHS};
}
