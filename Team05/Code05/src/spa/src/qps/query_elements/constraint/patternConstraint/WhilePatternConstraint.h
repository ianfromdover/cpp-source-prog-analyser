//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_WHILEPATTERNCONSTRAINT_H
#define SPA_WHILEPATTERNCONSTRAINT_H


#include "PatternConstraint.h"
#include "qps/query_elements/constraint_argument/expression_reference/ExpressionReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "qps/query_elements/constraint_argument/statement_reference/WhileEntity.h"

class WhilePatternConstraint : public PatternConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    std::shared_ptr<WhileEntity> constraintIdentifier;
    Table getTable(QueryPkbVirtual &pkb);
public:
    WhilePatternConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<WhileEntity>);
    std::string getConstraintType() override;
    std::shared_ptr<Entity> getPatternConstraintIdentifier() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPkbVirtual &) override;
};


#endif //SPA_WHILEPATTERNCONSTRAINT_H
