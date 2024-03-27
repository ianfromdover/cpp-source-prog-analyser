//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_ASSIGNPATTERNCONSTRAINT_H
#define SPA_ASSIGNPATTERNCONSTRAINT_H

#include "PatternConstraint.h"
#include "qps/query_elements/constraint_argument/expression_reference/ExpressionReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"

// can only do patterns on assignment for now
class AssignPatternConstraint : public PatternConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    std::shared_ptr<AssignEntity> constraintIdentifier;
public:
    AssignPatternConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<ExpressionReference> , std::shared_ptr<AssignEntity>);
    std::string getConstraintType() override;
    std::shared_ptr<Entity> getPatternConstraintIdentifier() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;
};


#endif //SPA_ASSIGNPATTERNCONSTRAINT_H
