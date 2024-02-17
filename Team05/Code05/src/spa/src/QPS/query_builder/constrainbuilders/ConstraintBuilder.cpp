//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintBuilder.h"

#include <utility>

void ConstraintBuilder::reset() {
    constraintClause.reset();
}

std::shared_ptr<Constraint> ConstraintBuilder::build() {
    return constraintClause;
}

std::shared_ptr<Constraint> ConstraintBuilder::buildConstraint(shared_ptr<qps::RelationshipClause> rsClause) {
    this->reset();
    this->addConstraintClause(std::move(rsClause));
    return this->build();
}

std::shared_ptr<ConstraintArgument> ConstraintBuilder::buildArg(qps::Token & token, qps::TokenType::TypeInfo ref) {
    return ConstraintArgCreator::buildArg(token, ref);
}

std::shared_ptr<ExpressionReference> ConstraintBuilder::buildArgAsExpressionRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::EXPR_SPEC) {
        throw std::invalid_argument( "Not Expression reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<ExpressionReference>(buildArg(token, ref));
}

std::shared_ptr<StatementReference> ConstraintBuilder::buildArgAsStatementRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::STMT_REF) {
        throw std::invalid_argument( "Not Statement reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<StatementReference>(buildArg(token, ref));
}

std::shared_ptr<EntityReference> ConstraintBuilder::buildArgAsEntityRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::ENT_REF) {
        throw std::invalid_argument( "Not Entity reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<EntityReference>(buildArg(token, ref));
}

