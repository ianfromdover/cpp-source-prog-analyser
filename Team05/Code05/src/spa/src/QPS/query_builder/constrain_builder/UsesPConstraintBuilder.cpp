//
// Created by tohzh on 17/2/2024.
//

#include "UsesPConstraintBuilder.h"

void UsesPConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs) {
    if (rs->getRelationshipType() != QPSTokenType::USES_P) {
        throw std::invalid_argument( "Not Uses P argument" );
    }

    arg1 = buildArgAsEntityRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType());
    constraintClause = make_shared<UsesPConstraint>(arg1, arg2);
}