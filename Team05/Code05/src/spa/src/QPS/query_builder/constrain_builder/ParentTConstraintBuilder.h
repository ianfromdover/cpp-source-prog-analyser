//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_PARENTTCONSTRAINTBUILDER_H
#define SPA_PARENTTCONSTRAINTBUILDER_H

#include "ConstraintBuilderTemplate.h"
#include "RelationshipConstraintBuilder.h"

class ParentTConstraintBuilder : public RelationshipConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>) override;
};

#endif //SPA_PARENTTCONSTRAINTBUILDER_H
