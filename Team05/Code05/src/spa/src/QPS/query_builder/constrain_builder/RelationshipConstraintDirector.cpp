//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintDirector.h"


std::shared_ptr<Constraint> RelationshipConstraintDirector::process(shared_ptr<RelationshipClause> r) {
    QPSTokenType::QPSTypeInfo type = r->getRelationshipType();
    switch (type) {
        case (QPSTokenType::FOLLOWS): {
            FollowsConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::FOLLOWS_T): {
            FollowsTConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::PARENT): {
            ParentConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::PARENT_T): {
            ParentTConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::USES_S): {
            UsesSConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::USES_P): {
            UsesPConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::MODIFIES_P): {
            ModifiesPConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (QPSTokenType::MODIFIES_S): {
            ModifiesSConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        default: {
            throw std::invalid_argument("Invalid relationship constraint token");
        }
    }
}
