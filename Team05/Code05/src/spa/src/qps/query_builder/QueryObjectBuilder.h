//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_QUERYBUILDER_H
#define SPA_QUERYBUILDER_H

#include "ConstraintArgCreator.h"
#include "qps/parser/SelectClause.h"
#include "qps/parser/IntermediateQuery.h"
#include "qps/query_elements/QueryObject.h"
#include "constraint_builder/relationship_builders/RelationshipConstraintBuilderTemplate.h"
#include "constraint_builder/pattern_builders/AssignPatternConstraintBuilder.h"
#include "constraint_builder/relationship_builders/FollowsConstraintBuilder.h"
#include "constraint_builder/relationship_builders/FollowsTConstraintBuilder.h"
#include "constraint_builder/relationship_builders/ModifiesPConstraintBuilder.h"
#include "constraint_builder/relationship_builders/ModifiesSConstraintBuilder.h"
#include "constraint_builder/relationship_builders/ParentConstraintBuilder.h"
#include "constraint_builder/relationship_builders/ParentTConstraintBuilder.h"
#include "constraint_builder/relationship_builders/UsesPConstraintBuilder.h"
#include "constraint_builder/relationship_builders/UsesSConstraintBuilder.h"
#include "constraint_builder/relationship_builders/NextConstraintBuilder.h"
#include "constraint_builder/relationship_builders/NextTConstraintBuilder.h"
#include "constraint_builder/relationship_builders/AffectsConstraintBuilder.h"
#include "constraint_builder/RelationshipConstraintDirector.h"
#include "constraint_builder/PatternConstraintDirector.h"
#include "qps/query_elements/Boolean.h"


class QueryObjectBuilder {
private:
    std::shared_ptr<QueryObject> qo;
    std::shared_ptr<IntermediateQuery> intermediateObject;
    void reset();
    void setSingleRelationshipConstraint(std::shared_ptr<RelationshipClause>, shared_ptr<QueryObject>);
    void setSinglePatternClause(std::shared_ptr<PatternClause>, shared_ptr<QueryObject>);
    void setSingleSelectClause();
    void setAllRelationshipConstraint();
    void setAllPatternClauses();
    void setAllDeclarationClauses();
    std::shared_ptr<QueryObject> getQueryObjectRepresentation();
public:
    std::shared_ptr<QueryObject> build(shared_ptr<IntermediateQuery>);
};


#endif //SPA_QUERYBUILDER_H
