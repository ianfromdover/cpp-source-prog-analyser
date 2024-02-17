//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H
#define SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"
#include "qps/parser/PatternClause.h"

class ConcretePatternConstraintBuilder : public ConstraintBuilderTemplate {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<ExpressionReference> arg2;
    shared_ptr<AssignEntity> syn;
    void addPatternClause(std::shared_ptr<qps::PatternClause>);
public:
    shared_ptr<ConcretePatternConstraint> buildPatternConstraint(std::shared_ptr<qps::PatternClause>);
};

#endif //SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H
