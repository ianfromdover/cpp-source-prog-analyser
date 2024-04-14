//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_IFPATTERNCONSTRAINT_H
#define SPA_IFPATTERNCONSTRAINT_H

#include "PatternConstraint.h"
#include "qps/query_elements/constraint_argument/expression_reference/ExpressionReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"

class IfPatternConstraint : public PatternConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    std::shared_ptr<IfEntity> constraintIdentifier;
public:
    IfPatternConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<IfEntity>);
    std::string getConstraintType() override;
    std::shared_ptr<Entity> getPatternConstraintIdentifier() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    std::size_t hash() const override;
protected:
    Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) override;
    Table getTable(QueryPkbVirtual &pkb) override;
    vector<string> getDefaultHeaders() override;
//    Table getFullTable(QueryPkbVirtual &pkb) override;
};


#endif //SPA_IFPATTERNCONSTRAINT_H
