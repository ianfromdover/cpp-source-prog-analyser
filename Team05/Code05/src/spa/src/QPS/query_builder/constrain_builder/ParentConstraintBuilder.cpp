//
// Created by tohzh on 17/2/2024.
//

#include "ParentConstraintBuilder.h"

void ParentConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::PARENT) {
        throw std::invalid_argument( "Not Parent argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<ParentConstraint>(arg1, arg2);
}