//
// Created by tohzh on 6/3/2024.
//

#ifndef SPA_CALLSCONSTRAINTBUILDER_H
#define SPA_CALLSCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class CallsConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_CALLSCONSTRAINTBUILDER_H
