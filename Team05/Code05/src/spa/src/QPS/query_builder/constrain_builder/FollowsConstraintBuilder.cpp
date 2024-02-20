//
// Created by tohzh on 17/2/2024.
//

#include "FollowsConstraintBuilder.h"


void FollowsConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs) {
    if (rs->getRelationshipType() != QPSTokenType::FOLLOWS) {
        throw std::invalid_argument( "Not follows argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType());
    constraintClause = make_shared<FollowsConstraint>(arg1, arg2);
}
