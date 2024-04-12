//
// Created by tohzh on 21/3/2024.
//

#include "IfPatternConstraint.h"

//second and third argument in `IFpattern` can only be wildcard.
IfPatternConstraint::IfPatternConstraint(std::shared_ptr<EntityReference> arg1, std::shared_ptr<IfEntity> assignment) {
    constraintArguments.push_back(arg1);
    constraintIdentifier = std::move(assignment);
}

std::string IfPatternConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PATTERN_IF;
}

std::shared_ptr<Entity> IfPatternConstraint::getPatternConstraintIdentifier() {
    return constraintIdentifier;
}

std::vector<std::shared_ptr<ConstraintArgument>> IfPatternConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table IfPatternConstraint::getTable(QueryPkbVirtual &pkb) {
    Table res = pkb.getPatternIfTable();

    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();

    std::string stmtHeader = constraintIdentifier->getIdentifier();
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue()[0] : HEADER_IFPATTERN;

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

    for (const std::string& header : {HEADER_IFPATTERN}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }
//    removeHeaders({HEADER_IFPATTERN}, table);

    return table.getTable();
}

std::size_t IfPatternConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_PATTERN_IF) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

Table IfPatternConstraint::getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) {
    auto t = pkb.getPatternIfTable();
    t.insert(t.begin(), getDefaultHeaders());
    return t;
}

vector<string> IfPatternConstraint::getDefaultHeaders() {
    return {constraintIdentifier->getIdentifier(), HEADER_IFPATTERN};
}
