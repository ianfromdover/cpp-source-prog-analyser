//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTARGCREATOR_H
#define SPA_CONSTRAINTARGCREATOR_H

#include "qps/parser/RelationshipClause.h" // error when I include this inclusion, it has to be the first import (also for subsequent imports)
#include "../query_elements/constraint_argument/expression_reference/ExpressionSpec.h"
#include "../query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "../query_elements/constraint_argument/entity_reference/VariableEntity.h"
#include "../query_elements/constraint_argument/entity_reference/ConstantEntity.h"
#include "../query_elements/constraint_argument/entity_reference/EntityRefWildCard.h"
#include "../query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "../query_elements/constraint_argument/statement_reference/ReadEntity.h"
#include "../query_elements/constraint_argument/statement_reference/PrintEntity.h"
#include "../query_elements/constraint_argument/statement_reference/AssignEntity.h"
#include "../query_elements/constraint_argument/statement_reference/CallEntity.h"
#include "../query_elements/constraint_argument/statement_reference/IfEntity.h"
#include "../query_elements/constraint_argument/statement_reference/WhileEntity.h"
#include "../query_elements/constraint_argument/statement_reference/IntegerArgument.h"
#include "../query_elements/constraint_argument/statement_reference/StatementRefWildCard.h"
#include <memory>
#include <stdexcept>

class ConstraintArgCreator {
public:
//    static std::shared_ptr<ConstraintArgument> buildArgFromToken(qps::Token&, qps::TokenType::TypeInfo);
//    static std::shared_ptr<ConstraintArgument> buildArg(qps::TokenType, qps::TokenType::TypeInfo, std::string);
    static std::shared_ptr<ConstraintArgument> buildArg(qps::Token&, qps::TokenType::TypeInfo);
    static std::shared_ptr<ExpressionSpec> createExpressionSpec(std::string);
    static std::shared_ptr<ProcedureEntity> createProcedureEntity(std::string);
    static std::shared_ptr<VariableEntity> createVariableEntity(std::string);
    static std::shared_ptr<ConstantEntity> createConstantEntity(std::string);
    static std::shared_ptr<EntityRefWildCard> createEntityRefWildCard();
    static std::shared_ptr<StatementEntity> createStatementEntity(std::string);
    static std::shared_ptr<ReadEntity> createReadEntity(std::string);
    static std::shared_ptr<PrintEntity> createPrintEntity(std::string);
    static std::shared_ptr<AssignEntity> createAssignEntity(std::string);
    static std::shared_ptr<CallEntity> createCallEntity(std::string);
    static std::shared_ptr<IfEntity> createIfEntity(std::string);
    static std::shared_ptr<WhileEntity> createWhileEntity(std::string);
    static std::shared_ptr<IntegerArgument> createIntegerArgument(std::string);
    static std::shared_ptr<StatementRefWildCard> createStatementRefWildCard();
};


#endif //SPA_CONSTRAINTARGCREATOR_H
