//
// Created by sjh_9 on 1/4/2024.
//

#include "NextTConstraintBuilder.h"

void NextTConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::NEXT_T) {
        throw std::invalid_argument( "Not Next_T argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<NextTConstraint>(arg1, arg2);
}