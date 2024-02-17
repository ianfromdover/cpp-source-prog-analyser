//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_MODIFIESSCONSTRAINTBUILDER_H
#define SPA_MODIFIESSCONSTRAINTBUILDER_H


#include "ConstraintBuilder.h"

class ModifiesSConstraintBuilder : public ConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_MODIFIESSCONSTRAINTBUILDER_H
