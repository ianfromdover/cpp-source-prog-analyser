//
// Created by tohzh on 6/3/2024.
//

#include "CallsConstraintBuilder.h"

void CallsConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::CALLS) {
        throw std::invalid_argument( "Not Calls argument" );
    }

    arg1 = buildArgAsEntityRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<CallsConstraint>(arg1, arg2);
}
