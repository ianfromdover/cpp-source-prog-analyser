//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTARGCREATOR_H
#define SPA_CONSTRAINTARGCREATOR_H

#include "qps/parser/RelationshipClause.h" // error when I include this inclusion, it has to be the first import (also for subsequent imports)
#include "../query_elements/constraint_argument/expression_reference/Expression.h"
#include "../query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "../query_elements/constraint_argument/entity_reference/VariableEntity.h"
#include "../query_elements/constraint_argument/entity_reference/ConstantEntity.h"
#include "../query_elements/constraint_argument/entity_reference/EntityRefWildcard.h"
#include "../query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "../query_elements/constraint_argument/statement_reference/ReadEntity.h"
#include "../query_elements/constraint_argument/statement_reference/PrintEntity.h"
#include "../query_elements/constraint_argument/statement_reference/AssignEntity.h"
#include "../query_elements/constraint_argument/statement_reference/CallEntity.h"
#include "../query_elements/constraint_argument/statement_reference/IfEntity.h"
#include "../query_elements/constraint_argument/statement_reference/WhileEntity.h"
#include "../query_elements/constraint_argument/statement_reference/IntegerArgument.h"
#include "../query_elements/constraint_argument/statement_reference/StatementRefWildcard.h"
#include "../query_elements/constraint_argument/expression_reference/ExpressionRefWildcard.h"
#include "../query_elements/constraint_argument/expression_reference/ExpressionWithWildcard.h"
#include "../query_elements/constraint_argument/entity_reference/QuotedIdentity.h"
#include "../query_elements/constraint_argument/with_reference/VariableWith.h"
#include "../query_elements/constraint_argument/with_reference/LiteralWith.h"
#include "../query_elements/QueryObject.h"
#include <memory>
#include <stdexcept>

class ConstraintArgCreator {
public:
    static std::shared_ptr<ConstraintArgument> buildArgFromToken(QPSToken&, QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);
    static std::shared_ptr<Expression> createExpression(std::string);
    static std::shared_ptr<ExpressionWithWildcard> createExpressionWithWildcard(std::string);
    static std::shared_ptr<ProcedureEntity> createProcedureEntity(std::string);
    static std::shared_ptr<VariableEntity> createVariableEntity(std::string);
    static std::shared_ptr<ConstantEntity> createConstantEntity(std::string);
    static std::shared_ptr<EntityRefWildcard> createEntityRefWildcard();
    static std::shared_ptr<StatementEntity> createStatementEntity(std::string);
    static std::shared_ptr<ReadEntity> createReadEntity(std::string);
    static std::shared_ptr<PrintEntity> createPrintEntity(std::string);
    static std::shared_ptr<AssignEntity> createAssignEntity(std::string);
    static std::shared_ptr<CallEntity> createCallEntity(std::string);
    static std::shared_ptr<IfEntity> createIfEntity(std::string);
    static std::shared_ptr<WhileEntity> createWhileEntity(std::string);
    static std::shared_ptr<IntegerArgument> createIntegerArgument(std::string);
    static std::shared_ptr<StatementRefWildcard> createStatementRefWildcard();
    static std::shared_ptr<ExpressionRefWildcard> createExpressionRefWildcard();
    static std::shared_ptr<QuotedIdentity> createQuotedIdentity(std::string);
    static shared_ptr<ConstraintArgument>buildArg(QPSTokenType::QPSTypeInfo type, QPSTokenType::QPSTypeInfo ref, string identifier, std::shared_ptr<QueryObject>);
    static shared_ptr<Entity> buildEntity(QPSTokenType::QPSTypeInfo type, string identifier);
    static shared_ptr<VariableWith> createVariableWith(std::string, QPSTokenType::QPSTypeInfo, std::shared_ptr<QueryObject>);
    static shared_ptr<LiteralWith> createIntegerWith(std::string);
};


#endif //SPA_CONSTRAINTARGCREATOR_H
