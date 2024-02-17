//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTBUILDER_H
#define SPA_RELATIONSHIPCONSTRAINTBUILDER_H

#include "ConstraintBuilderTemplate.h"

class RelationshipConstraintBuilder : public ConstraintBuilderTemplate {
private:
    virtual void addConstraintClause(shared_ptr<qps::RelationshipClause>) = 0;
public:
    std::shared_ptr<Constraint> buildRelationConstraint(shared_ptr<qps::RelationshipClause>);
};


#endif //SPA_RELATIONSHIPCONSTRAINTBUILDER_H
