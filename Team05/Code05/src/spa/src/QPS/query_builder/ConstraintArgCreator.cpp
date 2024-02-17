//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintArgCreator.h"


std::shared_ptr<ConstraintArgument> ConstraintArgCreator::buildArg(qps::Token& token, qps::TokenType::TypeInfo ref) {
    std::string identifier = token.getLexeme();
    switch (token.getType().getInfo()) {
        case qps::TokenType::EXPR_REF:
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
            if (ref == qps::TokenType::ENT_REF) {
                return ConstraintArgCreator::createEntityRefWildCard();
            } else if (ref == qps::TokenType::STMT_REF) {
                return ConstraintArgCreator::createStatementRefWildCard();
            } else {
                return ConstraintArgCreator::createExpressionRefWildCard();
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
            return ConstraintArgCreator::createIfEntity(identifier);
            break;
        case qps::TokenType::READ:
            return ConstraintArgCreator::createReadEntity(identifier);
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

std::shared_ptr<ExpressionSpec> ConstraintArgCreator::createExpressionSpec(std::string s) {
    return std::make_shared<ExpressionSpec>(s);
}

std::shared_ptr<ProcedureEntity> ConstraintArgCreator::createProcedureEntity(std::string s) {
    return std::make_shared<ProcedureEntity>(s);
}

std::shared_ptr<VariableEntity> ConstraintArgCreator::createVariableEntity(std::string s) {
    return std::make_shared<VariableEntity>(s);
}

std::shared_ptr<ConstantEntity> ConstraintArgCreator::createConstantEntity(std::string s) {
    return std::make_shared<ConstantEntity>(s);
}

std::shared_ptr<EntityRefWildCard> ConstraintArgCreator::createEntityRefWildCard() {
    return std::make_shared<EntityRefWildCard>();
}

std::shared_ptr<StatementEntity> ConstraintArgCreator::createStatementEntity(std::string s) {
    return std::make_shared<StatementEntity>(s);
}

std::shared_ptr<ReadEntity> ConstraintArgCreator::createReadEntity(std::string s) {
    return std::make_shared<ReadEntity>(s);
}

std::shared_ptr<PrintEntity> ConstraintArgCreator::createPrintEntity(std::string s) {
    return std::make_shared<PrintEntity>(s);
}

std::shared_ptr<AssignEntity> ConstraintArgCreator::createAssignEntity(std::string s) {
    return std::make_shared<AssignEntity>(s);
}

std::shared_ptr<CallEntity> ConstraintArgCreator::createCallEntity(std::string s) {
    return std::make_shared<CallEntity>(s);
}

std::shared_ptr<IfEntity> ConstraintArgCreator::createIfEntity(std::string s) {
    return std::make_shared<IfEntity>(s);
}

std::shared_ptr<WhileEntity> ConstraintArgCreator::createWhileEntity(std::string s) {
    return std::make_shared<WhileEntity>(s);
}

std::shared_ptr<IntegerArgument> ConstraintArgCreator::createIntegerArgument(std::string s) {
    int num = stoi(s);
    return std::make_shared<IntegerArgument>(num);
}

std::shared_ptr<StatementRefWildCard> ConstraintArgCreator::createStatementRefWildCard() {
    return std::make_shared<StatementRefWildCard>();
}

std::shared_ptr<ExpressionRefWildcard> ConstraintArgCreator::createExpressionRefWildCard() {
    return std::make_shared<ExpressionRefWildcard>();
}