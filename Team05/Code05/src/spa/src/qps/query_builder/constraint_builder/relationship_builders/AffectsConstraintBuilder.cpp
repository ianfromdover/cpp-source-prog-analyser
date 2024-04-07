//
// Created by sjh_9 on 1/4/2024.
//

#include "AffectsConstraintBuilder.h"

void AffectsConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::AFFECTS) {
        throw std::invalid_argument( "Not Affects argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<AffectsConstraint>(arg1, arg2);
}