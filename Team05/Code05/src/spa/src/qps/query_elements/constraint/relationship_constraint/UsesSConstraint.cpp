//
// Created by tohzh on 15/2/2024.
//

#include "UsesSConstraint.h"
#include "qps/query_projector/ResultTable.h"
#include "common/StringUtils.h"

UsesSConstraint::UsesSConstraint(std::shared_ptr<StatementReference> s1, std::shared_ptr<EntityReference> s2) {
    constraintArguments.push_back(s1);
    constraintArguments.push_back(s2);
}

std::string UsesSConstraint::getConstraintType() {
    return CONSTRAINT_TYPE_USESS;
}

std::vector<std::shared_ptr<ConstraintArgument>> UsesSConstraint::getConstraintArguments() {
    return constraintArguments;
}

Table UsesSConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        Table wholeSet = pkb.getUsesSTable();
        Table subSet = getTable(pkb);
        return ResultTable::minusTable(wholeSet, subSet);
    } else {
        return getTable(pkb);
    }
}

Table UsesSConstraint::getTable(QueryPkbVirtual &pkb) {
    // Get uses table and populate it into our results table
    Table result = pkb.getUsesSTable();

    // Get constraint arguments and initialise it as our table headers
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = args[1] -> getEntityType();

    std::string lhsHeader = isStatementSynonym(lhsEntityType) ? args[0]->getArgumentValue()[0] : HEADER_USESSLHS;
    std::string rhsHeader = rhsEntityType == TYPE_VARIABLE ? args[1]->getArgumentValue()[0] : HEADER_USESSRHS;

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
    if (rhsEntityType == TYPE_VARIABLE) {
        // Get entity table by type
        Table entityTable = args[1]->getEntityTable(pkb);
        ResultTable entityTableResult(entityTable);
        table.add(entityTableResult.getTable());
    }
    if (rhsEntityType == TYPE_QUOTED_IDENT) {
        std::string string = args[1]->getArgumentValue()[0];
        std::string rhsHeaderNew = StringUtils::stripCharacters(string,"\"");
        table.filterByColumnExact(rhsHeader,rhsHeaderNew);
    }

//    if (lhsHeader == HEADER_USESSLHS){
//        table.removeColumnByHeader(lhsHeader);
//    }
//    if (rhsHeader == HEADER_USESSRHS){
//        table.removeColumnByHeader(rhsHeader);
//    }
    removeHeaders({HEADER_USESSLHS, HEADER_USESSRHS}, table);

    return table.getTable();
}

bool UsesSConstraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

std::size_t UsesSConstraint::hash() const {
    std::hash<std::string> stringHasher;

    std::string s1 = constraintArguments[0]->getArgumentValue()[0];
    std::string s2 = constraintArguments[0]->getArgumentValue()[0];

    std::size_t hashValue = 0;

    // Combine hash values for both stringVars while maintaining their order
    hashValue ^= stringHasher(CONSTRAINT_TYPE_USESS) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s1) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);
    hashValue ^= stringHasher(s2) + HASH_OFFSET + (hashValue << 6) + (hashValue >> 2);

    return hashValue;
}
