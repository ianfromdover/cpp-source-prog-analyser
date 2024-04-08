//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintBuilderTemplate.h"

#include <utility>

void ConstraintBuilderTemplate::reset() {
    constraintClause.reset();
}

std::shared_ptr<Constraint> ConstraintBuilderTemplate::build() {
    return constraintClause;
}

std::shared_ptr<ConstraintArgument> ConstraintBuilderTemplate::buildArg(QPSToken & token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    auto x = ConstraintArgCreator::buildArgFromToken(token, ref, std::move(qo));
    return x;
}

std::shared_ptr<ExpressionReference> ConstraintBuilderTemplate::buildArgAsExpressionRef(QPSToken& token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    if (ref != QPSTokenType::EXPR_REF) {
        throw std::invalid_argument( "Not Expression reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<ExpressionReference>(buildArg(token, ref, std::move(qo)));
}

std::shared_ptr<StatementReference> ConstraintBuilderTemplate::buildArgAsStatementRef(QPSToken& token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    if (ref != QPSTokenType::STMT_REF) {
        throw std::invalid_argument( "Not Statement reference, is " + to_string(ref) );
    }
    return dynamic_pointer_cast<StatementReference>(buildArg(token, ref, std::move(qo)));
}

std::shared_ptr<EntityReference> ConstraintBuilderTemplate::buildArgAsEntityRef(QPSToken& token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    if (ref != QPSTokenType::ENT_REF) {
        throw std::invalid_argument( "Not Entity reference, is " + to_string(ref) );
    }
    auto x = dynamic_pointer_cast<EntityReference>(buildArg(token, ref, std::move(qo)));
    return x;
}

std::shared_ptr<WithReference> ConstraintBuilderTemplate::buildArgAsWithRef(QPSToken& token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    if (ref != QPSTokenType::WITH_REF) {
        throw std::invalid_argument( "Not With reference, is " + to_string(ref) );
    }
    auto x = dynamic_pointer_cast<WithReference>(buildArg(token, ref, std::move(qo)));
    return x;
}


