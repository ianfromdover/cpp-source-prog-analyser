//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintBuilderTemplate.h"

void ConstraintBuilderTemplate::reset() {
    constraintClause.reset();
}

std::shared_ptr<Constraint> ConstraintBuilderTemplate::build() {
    return constraintClause;
}

std::shared_ptr<ConstraintArgument> ConstraintBuilderTemplate::buildArg(qps::Token & token, qps::TokenType::TypeInfo ref) {
    return ConstraintArgCreator::buildArgFromToken(token, ref);
}

std::shared_ptr<ExpressionReference> ConstraintBuilderTemplate::buildArgAsExpressionRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::EXPR_REF) {
        throw std::invalid_argument( "Not Expression reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<ExpressionReference>(buildArg(token, ref));
}

std::shared_ptr<StatementReference> ConstraintBuilderTemplate::buildArgAsStatementRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::STMT_REF) {
        throw std::invalid_argument( "Not Statement reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<StatementReference>(buildArg(token, ref));
}

std::shared_ptr<EntityReference> ConstraintBuilderTemplate::buildArgAsEntityRef(qps::Token& token, qps::TokenType::TypeInfo ref) {
    if (ref != qps::TokenType::ENT_REF) {
        throw std::invalid_argument( "Not Entity reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<EntityReference>(buildArg(token, ref));
}


