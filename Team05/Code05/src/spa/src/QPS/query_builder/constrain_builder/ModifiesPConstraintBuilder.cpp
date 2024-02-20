//
// Created by tohzh on 17/2/2024.
//

#include "ModifiesPConstraintBuilder.h"

void ModifiesPConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::MODIFIES_P) {
        throw std::invalid_argument( "Not Modifies P argument" );
    }

    arg1 = buildArgAsEntityRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<ModifiesPConstraint>(arg1, arg2);
}