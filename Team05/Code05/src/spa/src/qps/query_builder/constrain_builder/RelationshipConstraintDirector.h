//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H
#define SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H

#include "qps/query_builder/constrain_builder/relationship_builders/ParentConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/ParentTConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/FollowsConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/FollowsTConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/ModifiesSConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/ModifiesPConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/UsesSConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/UsesPConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/CallsConstraintBuilder.h"
#include "qps/query_builder/constrain_builder/relationship_builders/CallsTConstraintBuilder.h"

class RelationshipConstraintDirector {
public:
    static std::shared_ptr<Constraint> process(std::shared_ptr<RelationshipClause>, shared_ptr<QueryObject>);
};


#endif //SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H
