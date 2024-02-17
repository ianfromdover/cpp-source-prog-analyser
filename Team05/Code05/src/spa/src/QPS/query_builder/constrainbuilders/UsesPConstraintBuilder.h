//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_USESPCONSTRAINTBUILDER_H
#define SPA_USESPCONSTRAINTBUILDER_H

#include "ConstraintBuilder.h"

class UsesPConstraintBuilder : public ConstraintBuilder {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_USESPCONSTRAINTBUILDER_H
