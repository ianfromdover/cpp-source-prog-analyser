//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_USESPCONSTRAINTBUILDER_H
#define SPA_USESPCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class UsesPConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};

#endif //SPA_USESPCONSTRAINTBUILDER_H
