//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintArgCreator.h"

std::shared_ptr<ConstraintArgument> ConstraintArgCreator::buildArg(QPSTokenType::QPSTypeInfo type, QPSTokenType::TypeInfo ref,
                                                                   std::string identifier) {
    switch (type) {
        case QPSTokenType::EXPR_REF:
            return ConstraintArgCreator::createExpressionSpec(identifier);
            break;
        case QPSTokenType::PROCEDURE:
            return ConstraintArgCreator::createProcedureEntity(identifier);
            break;
        case QPSTokenType::VARIABLE:
            return ConstraintArgCreator::createVariableEntity(identifier);
            break;
        case QPSTokenType::CONSTANT:
            return ConstraintArgCreator::createConstantEntity(identifier);
            break;
        case QPSTokenType::WILDCARD:
            // need to check what type of wild card
            if (ref == QPSTokenType::ENT_REF) {
                return ConstraintArgCreator::createEntityRefWildCard();
            } else if (ref == QPSTokenType::STMT_REF) {
                return ConstraintArgCreator::createStatementRefWildCard();
            } else {
                return ConstraintArgCreator::createExpressionRefWildCard();
            }
            break;
        case QPSTokenType::STMT:
            return ConstraintArgCreator::createStatementEntity(identifier);
            break;
        case QPSTokenType::PRINT:
            return ConstraintArgCreator::createPrintEntity(identifier);
            break;
        case QPSTokenType::ASSIGN:
            return ConstraintArgCreator::createAssignEntity(identifier);
            break;
        case QPSTokenType::CALL:
            return ConstraintArgCreator::createCallEntity(identifier);
            break;
        case QPSTokenType::IF:
            return ConstraintArgCreator::createIfEntity(identifier);
            break;
        case QPSTokenType::READ:
            return ConstraintArgCreator::createReadEntity(identifier);
            break;
        case QPSTokenType::WHILE:
            return ConstraintArgCreator::createWhileEntity(identifier);
            break;
        case QPSTokenType::INTEGER:
            return ConstraintArgCreator::createIntegerArgument(identifier);
        default:
            throw std::invalid_argument( "invalid constraint argument flag" );
    }
}

// ref is only used to distinguish what type of wildcard is the constraint argument.
std::shared_ptr<ConstraintArgument> ConstraintArgCreator::buildArgFromToken(QPSToken& token, QPSTokenType::TypeInfo ref) {
    std::string identifier = token.getLexeme();
    return buildArg(token.getType().getInfo(), ref, identifier);
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

shared_ptr<Entity> ConstraintArgCreator::buildEntity(QPSTokenType::TypeInfo type, string identifier) {
    switch (type) {
        case QPSTokenType::PROCEDURE:
            return ConstraintArgCreator::createProcedureEntity(identifier);
            break;
        case QPSTokenType::VARIABLE:
            return ConstraintArgCreator::createVariableEntity(identifier);
            break;
        case QPSTokenType::CONSTANT:
            return ConstraintArgCreator::createConstantEntity(identifier);
            break;
        case QPSTokenType::STMT:
            return ConstraintArgCreator::createStatementEntity(identifier);
            break;
        case QPSTokenType::PRINT:
            return ConstraintArgCreator::createPrintEntity(identifier);
            break;
        case QPSTokenType::ASSIGN:
            return ConstraintArgCreator::createAssignEntity(identifier);
            break;
        case QPSTokenType::CALL:
            return ConstraintArgCreator::createCallEntity(identifier);
            break;
        case QPSTokenType::IF:
            return ConstraintArgCreator::createIfEntity(identifier);
            break;
        case QPSTokenType::READ:
            return ConstraintArgCreator::createReadEntity(identifier);
            break;
        case QPSTokenType::WHILE:
            return ConstraintArgCreator::createWhileEntity(identifier);
            break;
        default:
            throw std::invalid_argument( "invalid entity flag" );
    }
}
