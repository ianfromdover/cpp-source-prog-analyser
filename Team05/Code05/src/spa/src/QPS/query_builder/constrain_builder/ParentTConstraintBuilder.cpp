//
// Created by tohzh on 17/2/2024.
//

#include "ParentTConstraintBuilder.h"

void ParentTConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::PARENT_T) {
        throw std::invalid_argument( "Not Parent T argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<ParentTConstraint>(arg1, arg2);
}