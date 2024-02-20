//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_USESSCONSTRAINTBUILDER_H
#define SPA_USESSCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class UsesSConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_USESSCONSTRAINTBUILDER_H
