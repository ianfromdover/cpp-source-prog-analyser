//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_PARENTTCONSTRAINTBUILDER_H
#define SPA_PARENTTCONSTRAINTBUILDER_H

#include "qps/query_builder/constrain_builder/ConstraintBuilderTemplate.h"
#include "RelationshipConstraintBuilderTemplate.h"

class ParentTConstraintBuilder : public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};

#endif //SPA_PARENTTCONSTRAINTBUILDER_H
