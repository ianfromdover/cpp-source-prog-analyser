//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTBUILDER_H
#define SPA_CONSTRAINTBUILDER_H


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

class ConstraintBuilder {
protected:
    shared_ptr<Constraint> constraintClause;
    void reset();
    std::shared_ptr<Constraint> build();
    std::shared_ptr<ConstraintArgument> buildArg(qps::Token&, qps::TokenType::TypeInfo);
    virtual void addConstraintClause(shared_ptr<qps::RelationshipClause>) = 0;

protected:
    std::shared_ptr<ExpressionReference> buildArgAsExpressionRef(qps::Token&, qps::TokenType::TypeInfo);
    std::shared_ptr<StatementReference> buildArgAsStatementRef(qps::Token&, qps::TokenType::TypeInfo);
    std::shared_ptr<EntityReference> buildArgAsEntityRef(qps::Token&, qps::TokenType::TypeInfo);
public:
    std::shared_ptr<Constraint> buildConstraint(shared_ptr<qps::RelationshipClause>);
};


#endif //SPA_CONSTRAINTBUILDER_H
