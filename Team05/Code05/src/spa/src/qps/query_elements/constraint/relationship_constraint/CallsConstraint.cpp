//
// Created by tohzh on 6/3/2024.
//

#include "CallsConstraint.h"

CallsConstraint::CallsConstraint(std::shared_ptr<EntityReference> s1, std::shared_ptr<EntityReference>  s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string CallsConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_CALLS;
}

std::vector<std::shared_ptr<ConstraintArgument>> CallsConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table CallsConstraint::getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) {
    auto t = pkb.getCallsTable();
    t.insert(t.begin(), getDefaultHeaders());
    return t;
}

Table CallsConstraint::getTable(QueryPkbVirtual &pkb) {
    // Get follows table and populate it into our results table
    Table result = pkb.getCallsTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = lhsEntityType == TYPE_PROCEDURE ? args[0]->getArgumentValue()[0] : HEADER_CALLSLHS;
    std::string rhsHeader = rhsEntityType == TYPE_PROCEDURE ? args[1]->getArgumentValue()[0] : HEADER_CALLSRHS;

    if (lhsHeader==rhsHeader) {
        return {{lhsHeader}};
    }

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_PROCEDURE) {
        // Get entity table by type
        Table entityTable = args[0]->getEntityTable(pkb);
        table.add(entityTable);
    }
    if (lhsEntityType == TYPE_QUOTED_IDENT){
        std::string string1=args[0]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(lhsHeader,stripped);
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_PROCEDURE) {
        // Get entity table by type
        Table entityTable = args[1]->getEntityTable(pkb);
        table.add(entityTable);
    }
    if (rhsEntityType == TYPE_QUOTED_IDENT){
        std::string string1=args[1]->getArgumentValue()[0];
        string stripped = stripCharacters(string1,"\"");
        table.filterByColumnExact(rhsHeader,stripped);
    }

//    if (lhsHeader == HEADER_CALLSLHS){
//        table.removeColumnByHeader(lhsHeader);
//    }
//    if (rhsHeader == HEADER_CALLSRHS){
//        table.removeColumnByHeader(rhsHeader);
//    }
    removeHeaders({HEADER_CALLSLHS, HEADER_CALLSRHS}, make_shared<ResultTable>(table));

    return table.getTable();
}

std::size_t CallsConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_CALLS) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

std::vector<std::string> CallsConstraint::getDefaultHeaders() {
    return {HEADER_CALLSLHS, HEADER_CALLSRHS};
}
