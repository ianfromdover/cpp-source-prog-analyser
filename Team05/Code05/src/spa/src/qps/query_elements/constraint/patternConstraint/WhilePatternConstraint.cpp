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
    if (this->getNot()) {
        Table wholeSet = pkb.getPatternWhileTable();
        Table subSet = getTable(pkb);
        return ResultTable::minusTable(wholeSet, subSet);
    } else {
        return getTable(pkb);
    }
}

Table WhilePatternConstraint::getTable(QueryPkbVirtual &pkb) {
    Table res = pkb.getPatternWhileTable();

    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();

    std::string stmtHeader = constraintIdentifier->getIdentifier();
    std::string lhsHeader = args[0]->getEntityType() == TYPE_VARIABLE ? args[0]->getArgumentValue()[0] : HEADER_WHILEPATTERN;

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

    for (const std::string& header : {HEADER_WHILEPATTERN}){
        table.removeColumnByHeader(const_cast<string &>(header));
    }
//    removeHeaders({HEADER_WHILEPATTERN}, table);

    return table.getTable();
}

std::size_t WhilePatternConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_PATTERN_WHILE) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

