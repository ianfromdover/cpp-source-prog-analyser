//
// Created by tohzh on 6/3/2024.
//

#ifndef SPA_CALLSTCONSTRAINTBUILDER_H
#define SPA_CALLSTCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilderTemplate.h"

class CallsTConstraintBuilder : public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_CALLSTCONSTRAINTBUILDER_H
