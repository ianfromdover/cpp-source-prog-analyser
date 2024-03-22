//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_USESSCONSTRAINTBUILDER_H
#define SPA_USESSCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilderTemplate.h"

class UsesSConstraintBuilder : public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<EntityReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};

#endif //SPA_USESSCONSTRAINTBUILDER_H
