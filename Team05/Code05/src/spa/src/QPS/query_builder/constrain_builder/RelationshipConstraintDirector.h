//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H
#define SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H

#include "ParentConstraintBuilder.h"
#include "ParentTConstraintBuilder.h"
#include "FollowsConstraintBuilder.h"
#include "FollowsTConstraintBuilder.h"
#include "ModifiesSConstraintBuilder.h"
#include "ModifiesPConstraintBuilder.h"
#include "UsesSConstraintBuilder.h"
#include "UsesPConstraintBuilder.h"

class RelationshipConstraintDirector {
public:
    static std::shared_ptr<Constraint> process(std::shared_ptr<RelationshipClause>);
};


#endif //SPA_RELATIONSHIPCONSTRAINTDIRECTOR_H
