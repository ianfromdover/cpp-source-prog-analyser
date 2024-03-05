//
// Created by tohzh on 17/2/2024.
//

#include "ConstraintArgCreator.h"


std::shared_ptr<ConstraintArgument> ConstraintArgCreator::buildArg(QPSTokenType::QPSTypeInfo type, QPSTokenType::QPSTypeInfo ref,
                                                                   std::string identifier, std::shared_ptr<QueryObject> qo) {
    switch (type) {
        case QPSTokenType::QUOTED_IDENT:
            return ConstraintArgCreator::createQuotedIdentity(identifier);
        case QPSTokenType::EXPR:
            return ConstraintArgCreator::createExpression(identifier);
            break;
        case QPSTokenType::EXPR_WILDCARD:
            return ConstraintArgCreator::createExpressionWithWildcard(identifier);
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
        case QPSTokenType::STMT1:
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
        case QPSTokenType::SYNONYM:
            return dynamic_pointer_cast<ConstraintArgument>(qo->getEntityInDeclaration(identifier));
        default:
            throw std::invalid_argument( "invalid constraint argument flag" );
    }
}

// ref is only used to distinguish what type of wildcard is the constraint argument.
std::shared_ptr<ConstraintArgument> ConstraintArgCreator::buildArgFromToken(QPSToken& token, QPSTokenType::QPSTypeInfo ref, shared_ptr<QueryObject> qo) {
    std::string identifier = token.getLexeme();
    auto x=  buildArg(token.getType().getInfo(), ref, identifier, qo);
    return x;
}

std::shared_ptr<Expression> ConstraintArgCreator::createExpression(std::string s) {
    return std::make_shared<Expression>(s);
}

std::shared_ptr<ExpressionWithWildcard> ConstraintArgCreator::createExpressionWithWildcard(std::string s) {
    return std::make_shared<ExpressionWithWildcard>(s);
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

std::shared_ptr<QuotedIdentity> ConstraintArgCreator::createQuotedIdentity(std::string s) {
    return std::make_shared<QuotedIdentity>(s);
}

shared_ptr<Entity> ConstraintArgCreator::buildEntity(QPSTokenType::QPSTypeInfo type, string identifier) {
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
        case QPSTokenType::STMT1:
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


