//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_FOLLOWSCONSTRAINTBUILDER_H
#define SPA_FOLLOWSCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class FollowsConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>) override;
};


#endif //SPA_FOLLOWSCONSTRAINTBUILDER_H
