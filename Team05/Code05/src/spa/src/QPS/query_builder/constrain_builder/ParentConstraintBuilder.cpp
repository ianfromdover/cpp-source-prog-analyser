//
// Created by tohzh on 17/2/2024.
//

#include "ParentConstraintBuilder.h"

void ParentConstraintBuilder::addConstraintClause(shared_ptr<qps::RelationshipClause> rs) {
    if (rs->getRelationshipType() != qps::TokenType::PARENT) {
        throw std::invalid_argument( "Not Parent argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType());
    constraintClause = make_shared<ParentConstraint>(arg1, arg2);
}