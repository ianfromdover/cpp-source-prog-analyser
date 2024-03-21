//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTBUILDERTEMPLATE_H
#define SPA_RELATIONSHIPCONSTRAINTBUILDERTEMPLATE_H

#include "qps/query_builder/constrain_builder/ConstraintBuilderTemplate.h"

class RelationshipConstraintBuilderTemplate : public ConstraintBuilderTemplate {
private:
    virtual void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) = 0;
public:
    std::shared_ptr<Constraint> buildRelationConstraint(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>);
};


#endif //SPA_RELATIONSHIPCONSTRAINTBUILDERTEMPLATE_H
