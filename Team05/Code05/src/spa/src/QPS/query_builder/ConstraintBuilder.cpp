//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintBuilder.h"

void ConstraintBuilder::reset() {
    arg1.reset();
    arg2.reset();
    constraintClause.reset();
}

std::shared_ptr<Constraint> ConstraintBuilder::build() {
    return constraintClause;
}

void ConstraintBuilder::buildFirstArg(qps::Token& token, qps::TokenType::TypeInfo ref) {
    arg1 = buildArg(token, ref);
}

void ConstraintBuilder::buildSecondArg(qps::Token& token, qps::TokenType::TypeInfo ref) {
    arg2 = buildArg(token, ref);
}

std::shared_ptr<ConstraintArgument> ConstraintBuilder::buildArg(qps::Token& token, qps::TokenType::TypeInfo ref) {
    std::string identifier = token.getLexeme();
    switch (token.getType().getInfo()) {
        case qps::TokenType::EXPR_SPEC:
            return ConstraintArgCreator::createExpressionSpec(identifier);
            break;
        case qps::TokenType::PROCEDURE:
            return ConstraintArgCreator::createProcedureEntity(identifier);
            break;
        case qps::TokenType::VARIABLE:
            return ConstraintArgCreator::createVariableEntity(identifier);
            break;
        case qps::TokenType::CONSTANT:
            return ConstraintArgCreator::createConstantEntity(identifier);
            break;
        case qps::TokenType::WILDCARD:
            // need to check what type of wild card
            if (ref == qps::TokenType::STMT_REF) {
                return ConstraintArgCreator::createEntityRefWildCard();
            } else {
                return ConstraintArgCreator::createStatementRefWildCard();
            }
            break;
        case qps::TokenType::STMT:
            return ConstraintArgCreator::createStatementEntity(identifier);
            break;
        case qps::TokenType::PRINT:
            return ConstraintArgCreator::createPrintEntity(identifier);
            break;
        case qps::TokenType::ASSIGN:
            return ConstraintArgCreator::createAssignEntity(identifier);
            break;
        case qps::TokenType::CALL:
            return ConstraintArgCreator::createCallEntity(identifier);
            break;
        case qps::TokenType::IF:
            return ConstraintArgCreator::createPrintEntity(identifier);
            break;
        case qps::TokenType::WHILE:
            return ConstraintArgCreator::createWhileEntity(identifier);
            break;
        case qps::TokenType::INTEGER:
            return ConstraintArgCreator::createIntegerArgument(identifier);
        default:
            throw std::invalid_argument( "invalid constraint argument flag" );
    }
}


void ConstraintBuilder::buildConstraint(qps::TokenType::TypeInfo relationType, qps::TokenType::TypeInfo arg1Ref, qps::TokenType::TypeInfo arg2Ref) {
    auto* v1 = (arg1Ref == qps::TokenType::STMT_REF)
            ? dynamic_pointer_cast<StatementReference>(arg1)
            : dynamic_pointer_cast<EntityReference>(arg1);
    if (relationType == qps::TokenType::TypeInfo::PARENT) {
        constraintClause = make_shared<ParentConstraint>(v1, arg2);
    }
}

std::shared_ptr<Constraint> ConstraintBuilder::buildConstraint(shared_ptr<qps::RelationshipClause> rsClause) {
    reset();
    buildFirstArg(rsClause->getFirstArg(), rsClause->getFirstReferenceType());
    buildSecondArg(rsClause->getSecondArg(), rsClause->getSecondReferenceType());
    buildConstraint(rsClause->getRelationshipType(), rsClause->getFirstReferenceType(), rsClause->getSecondReferenceType());
    return constraintClause;
}

