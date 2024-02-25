//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_CONCRETEPATTERNCONSTRAINT_H
#define SPA_CONCRETEPATTERNCONSTRAINT_H

#include "PatternConstraint.h"
#include "../constraint_argument/expression_reference/ExpressionReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"

// can only do patterns on assignment for now
class ConcretePatternConstraint : public PatternConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    std::shared_ptr<AssignEntity> constraintIdentifier;
public:
    ConcretePatternConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<ExpressionReference> , std::shared_ptr<AssignEntity>);
    std::string getConstraintType() override;
    std::shared_ptr<AssignEntity> getPatternConstraintIdentifier() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;
};


#endif //SPA_CONCRETEPATTERNCONSTRAINT_H
