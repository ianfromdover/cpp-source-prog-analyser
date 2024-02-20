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
#include "qps/query_elements/constraint/ConcretePatternConstraint.h"
#include <stdexcept>

class ConstraintBuilderTemplate {
protected:
    shared_ptr<Constraint> constraintClause;
    void reset();

    std::shared_ptr<ConstraintArgument> buildArg(QPSToken&, QPSTokenType::QPSTypeInfo);


public:
    std::shared_ptr<Constraint> build();

protected:
    std::shared_ptr<ExpressionReference> buildArgAsExpressionRef(QPSToken&, QPSTokenType::QPSTypeInfo);
    std::shared_ptr<StatementReference> buildArgAsStatementRef(QPSToken&, QPSTokenType::QPSTypeInfo);
    std::shared_ptr<EntityReference> buildArgAsEntityRef(QPSToken&, QPSTokenType::QPSTypeInfo);
};



#endif //SPA_CONSTRAINTBUILDERTEMPLATE_H
