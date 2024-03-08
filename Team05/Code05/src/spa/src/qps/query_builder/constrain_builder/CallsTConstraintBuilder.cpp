//
// Created by tohzh on 6/3/2024.
//

#include "CallsTConstraintBuilder.h"

void CallsTConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::CALLS_T) {
        throw std::invalid_argument( "Not CallsT argument" );
    }

    arg1 = buildArgAsEntityRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<CallsTConstraint>(arg1, arg2);
}
