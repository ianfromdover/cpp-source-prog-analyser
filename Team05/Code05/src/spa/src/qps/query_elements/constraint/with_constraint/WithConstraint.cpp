//
// Created by tohzh on 20/3/2024.
//

#include "WithConstraint.h"


WithConstraint::WithConstraint(std::shared_ptr<WithReference> s1, std::shared_ptr<WithReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string WithConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_WITH;
}

std::string WithConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_WITH;
}

std::vector<std::shared_ptr<ConstraintArgument>> WithConstraint::getConstraintArguments() {
    return constraintArguments;
}

std::vector<std::vector<std::string>> WithConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
        auto type1 = args[0]->getEntityType();
        auto type2 = args[1]->getEntityType();
        if (type1 == TYPE_VAR_WITH && type2 == TYPE_VAR_WITH) {
            table wholeSet = getFullTable(pkb);
            Table subSet = getTable(pkb);
            table result = ResultTable::minusTable(wholeSet, subSet);
            removeHeaders({HEADER_ENT_WITH_TOMERGE}, make_shared<ResultTable>(result));
            return result;
        } else if (type1 == TYPE_LITERAL_WITH && type2 == TYPE_LITERAL_WITH) {
            string val1 = args[0]->getArgumentValue()[0];
            string val2 = args[1]->getArgumentValue()[0];
            if (val1 == val2) {
                return {{}};
            } else {
                // return everything
                return {{HEADER_SPECIAL_ALL_RESULTS}};
            }
        } else {
            // one of them is a variableWith
            shared_ptr<table> wholeSet;
            if (type1 == TYPE_VAR_WITH) {
                wholeSet = make_shared<table>(args[0]->getEntityTable(pkb));
            } else {
                wholeSet = make_shared<table>(args[1]->getEntityTable(pkb));
            }
            Table subSet = getTable(pkb);
            table result = ResultTable::minusTable(*wholeSet, subSet);
            removeHeaders({HEADER_ENT_WITH_TOMERGE}, make_shared<ResultTable>(result));
            return result;
        }
    } else {
        return getTable(pkb);
    }
}

Table WithConstraint::getFullTable(QueryPkbVirtual &pkb){
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    ResultTable t;
    t.add(args[0]->getEntityTable(pkb));
    t.add(args[1]->getEntityTable(pkb));
    return t.getTable();
}

std::vector<std::vector<std::string>> WithConstraint::getTable(QueryPkbVirtual & pkb) {
    // join based on the header: HEADER_ENT_WITH_TOMERGE
    auto table1 = constraintArguments[0]->getEntityTable(pkb);
    auto table2 = constraintArguments[1]->getEntityTable(pkb);
    table result = ResultTable::hashJoin(table1, table2);
    ResultTable ans = ResultTable(result);
//    ans.removeColumnByHeader(HEADER_ENT_WITH_TOMERGE);
    removeHeaders({HEADER_ENT_WITH_TOMERGE}, make_shared<ResultTable>(ans));
    return ans.getTable();
}

bool WithConstraint::isVariable(std::string s) {
    return s == TYPE_VAR_WITH;
}

std::size_t WithConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_WITH) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}
