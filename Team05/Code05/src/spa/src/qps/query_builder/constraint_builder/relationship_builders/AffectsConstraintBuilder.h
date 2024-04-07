//
// Created by sjh_9 on 1/4/2024.
//

#ifndef SPA_AFFECTSCONSTRAINTBUILDER_H
#define SPA_AFFECTSCONSTRAINTBUILDER_H


#include "RelationshipConstraintBuilderTemplate.h"

class AffectsConstraintBuilder: public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_AFFECTSCONSTRAINTBUILDER_H
