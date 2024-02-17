//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H
#define SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H

#include "ConstraintBuilder.h"

class ConcretePatternConstraintBuilder : public ConstraintBuilder {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<ExpressionReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_CONCRETEPATTERNCONSTRAINTBUILDER_H
