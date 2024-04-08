//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintDirector.h"

#include <utility>
#include "qps/query_elements/QueryObject.h"


std::shared_ptr<Constraint> RelationshipConstraintDirector::process(shared_ptr<RelationshipClause> r,
                                                                    shared_ptr<QueryObject> qo) {
    QPSTokenType::QPSTypeInfo type = r->getRelationshipType();
    shared_ptr<RelationshipConstraintBuilderTemplate> b;
    switch (type) {
        case (QPSTokenType::FOLLOWS): {
            b = make_shared<FollowsConstraintBuilder>();
            break;
        }
        case (QPSTokenType::FOLLOWS_T): {
            b = make_shared<FollowsTConstraintBuilder>();
            break;
        }
        case (QPSTokenType::PARENT): {
            b = make_shared<ParentConstraintBuilder>();
            break;
        }
        case (QPSTokenType::PARENT_T): {
            b = make_shared<ParentTConstraintBuilder>();
            break;
        }
        case (QPSTokenType::USES_S): {
            b = make_shared<UsesSConstraintBuilder>();
            break;
        }
        case (QPSTokenType::USES_P): {
            b = make_shared<UsesPConstraintBuilder>();
            break;
        }
        case (QPSTokenType::MODIFIES_P): {
            b = make_shared<ModifiesPConstraintBuilder>();
            break;
        }
        case (QPSTokenType::MODIFIES_S): {
            b = make_shared<ModifiesSConstraintBuilder>();
            break;
        }
        case (QPSTokenType::CALLS): {
            b = make_shared<CallsConstraintBuilder>();
            break;
        }
        case (QPSTokenType::CALLS_T): {
            b = make_shared<CallsTConstraintBuilder>();
            break;
        }
        case (QPSTokenType::NEXT): {
            NextConstraintBuilder b;
            b.addConstraintClause(r, qo);
            return b.build();
        }
        case (QPSTokenType::NEXT_T): {
            NextTConstraintBuilder b;
            b.addConstraintClause(r, qo);
            return b.build();
        }
        case (QPSTokenType::AFFECTS): {
            AffectsConstraintBuilder b;
            b.addConstraintClause(r, qo);
            return b.build();
        }
        default: {
            throw std::invalid_argument("Invalid relationship constraint token");
        }
    }
    b->buildRelationConstraint(r, std::move(qo));
    return b->build();

}
