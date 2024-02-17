//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_FOLLOWSTCONSTRAINTBUILDER_H
#define SPA_FOLLOWSTCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class FollowsTConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};


#endif //SPA_FOLLOWSTCONSTRAINTBUILDER_H
