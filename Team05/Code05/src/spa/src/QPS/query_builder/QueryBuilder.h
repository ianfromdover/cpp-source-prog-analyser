//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_QUERYBUILDER_H
#define SPA_QUERYBUILDER_H

#include "qps/query_builder/constrain_builder//RelationshipConstraintBuilder.h"
#include "ConstraintArgCreator.h"
#include "../query_elements/QueryObject.h"
#include "constrain_builder/ConcretePatternConstraintBuilder.h"
#include "constrain_builder/FollowsConstraintBuilder.h"
#include "constrain_builder/FollowsTConstraintBuilder.h"
#include "constrain_builder/ModifiesPConstraintBuilder.h"
#include "constrain_builder/ModifiesSConstraintBuilder.h"
#include "constrain_builder/ParentConstraintBuilder.h"
#include "constrain_builder/ParentTConstraintBuilder.h"
#include "constrain_builder/UsesPConstraintBuilder.h"
#include "constrain_builder/UsesSConstraintBuilder.h"
#include "qps/parser/SelectClause.h"
#include "qps/parser/IntermediateQuery.h"
#include "constrain_builder/RelationshipConstraintDirector.h"

class QueryBuilder {
private:
    std::shared_ptr<QueryObject> qo;
    std::shared_ptr<IntermediateQuery> intermediateObject;
    void reset();
    void setSingleRelationshipConstraint(std::shared_ptr<qps::RelationshipClause>);
    void setSinglePatternClause(std::shared_ptr<qps::PatternClause>);
    void setSingleSelectClause();
    void setAllRelationshipConstraint();
    void setAllPatternClauses();
    void setAllDeclarationClauses();
    std::shared_ptr<QueryObject> getQueryObjectRepresentation();
public:
    std::shared_ptr<QueryObject> build(shared_ptr<IntermediateQuery>);
};


#endif //SPA_QUERYBUILDER_H
