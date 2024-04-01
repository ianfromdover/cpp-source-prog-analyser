//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTBUILDERTEMPLATE_H
#define SPA_CONSTRAINTBUILDERTEMPLATE_H

#include "qps/query_builder/ConstraintArgCreator.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint/ParentConstraint.h"
#include "qps/query_elements/constraint/ParentTConstraint.h"
#include "qps/query_elements/constraint/UsesSConstraint.h"
#include "qps/query_elements/constraint/UsesPConstraint.h"
#include "qps/query_elements/constraint/ModifiesSConstraint.h"
#include "qps/query_elements/constraint/ModifiesPConstraint.h"
#include "qps/query_elements/constraint/AssignPatternConstraint.h"
#include "qps/query_elements/constraint/CallsConstraint.h"
#include "qps/query_elements/constraint/CallsTConstraint.h"
#include "qps/query_elements/constraint/NextConstraint.h"
#include "qps/query_elements/constraint/NextTConstraint.h"
#include "qps/query_elements/constraint/AffectsConstraint.h"
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
};



#endif //SPA_CONSTRAINTBUILDERTEMPLATE_H
