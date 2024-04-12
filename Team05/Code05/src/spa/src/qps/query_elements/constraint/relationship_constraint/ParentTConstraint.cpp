//
// Created by tohzh on 10/2/2024.
//

#include "ParentTConstraint.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

ParentTConstraint::ParentTConstraint(std::shared_ptr<ConstraintArgument> s1, std::shared_ptr<ConstraintArgument> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string ParentTConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_PARENTT;
}

std::vector<std::shared_ptr<ConstraintArgument>> ParentTConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table ParentTConstraint::getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) {
    auto t = pkb.getParentTTable();
    t.insert(t.begin(), getDefaultHeaders());
    return t;
}

Table ParentTConstraint::getTable(QueryPkbVirtual &pkb) {
    // Get parentT table and populate it into our results table
    Table result = pkb.getParentTTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue()[0] : HEADER_PARENTTLHS;
    std::string rhsHeader = isStatementSynonym(rhsEntityType) ? args[1]->getArgumentValue()[0] : HEADER_PARENTTRHS;

    if (lhsHeader==rhsHeader) {
        return {{lhsHeader}};
    }

    // Insertion of headers into our results table
    result.insert(result.begin(), {lhsHeader, rhsHeader});
    ResultTable table(result);

    // Handling LHS by Entity Type
    if (lhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[0]->getArgumentValue()[0]};
        table.filterByColumnValues(lhsHeader, intVals);
    }
    if (isStatementSynonym(lhsEntityType)) {
        // Get entity table by type
        Table entityTable = args[0]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        table.add(entityTableResult.getTable());
    }

    // Handling RHS by Entity Type
    if (rhsEntityType == TYPE_INTEGER) {
        std::vector<std::string> intVals = {args[1]->getArgumentValue()[0]};
        table.filterByColumnValues(rhsHeader, intVals);
    }
    if (isStatementSynonym(rhsEntityType)) {
        // Get entity table by type
        Table entityTable = args[1]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        table.add(entityTableResult.getTable());
    }

    removeHeaders(make_shared<ResultTable>(table));

    return table.getTable();
}

std::size_t ParentTConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[1]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_PARENTT) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}

std::vector<std::string> ParentTConstraint::getDefaultHeaders() {
    return {HEADER_PARENTTLHS, HEADER_PARENTTRHS};
}
