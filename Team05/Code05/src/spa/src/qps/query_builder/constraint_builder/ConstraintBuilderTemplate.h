//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTBUILDERTEMPLATE_H
#define SPA_CONSTRAINTBUILDERTEMPLATE_H

#include "qps/query_builder/ConstraintArgCreator.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/ParentConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/ParentTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/UsesSConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/UsesPConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/ModifiesSConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/ModifiesPConstraint.h"
#include "qps/query_elements/constraint/patternConstraint/AssignPatternConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/NextConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/NextTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/AffectsConstraint.h"

#include <stdexcept>

class ConstraintBuilderTemplate {
protected:
    shared_ptr<Constraint> constraintClause;
    void reset();
    std::shared_ptr<ConstraintArgument> buildArg(QPSToken&, QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);

public:
    std::shared_ptr<Constraint> build();

protected:
    std::shared_ptr<ExpressionReference> buildArgAsExpressionRef(QPSToken&, QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);
    std::shared_ptr<StatementReference> buildArgAsStatementRef(QPSToken&, QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);
    std::shared_ptr<EntityReference> buildArgAsEntityRef(QPSToken&, QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);

    shared_ptr<WithReference>
    buildArgAsWithRef(QPSToken &token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo);
};



#endif //SPA_CONSTRAINTBUILDERTEMPLATE_H
