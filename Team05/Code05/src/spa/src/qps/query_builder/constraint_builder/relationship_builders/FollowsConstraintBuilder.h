//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_FOLLOWSCONSTRAINTBUILDER_H
#define SPA_FOLLOWSCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilderTemplate.h"

class FollowsConstraintBuilder : public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_FOLLOWSCONSTRAINTBUILDER_H
