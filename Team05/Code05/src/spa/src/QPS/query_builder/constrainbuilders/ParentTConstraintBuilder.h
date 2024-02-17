//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_PARENTTCONSTRAINTBUILDER_H
#define SPA_PARENTTCONSTRAINTBUILDER_H


#include "ConstraintBuilder.h"

class ParentTConstraintBuilder : public ConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_PARENTTCONSTRAINTBUILDER_H
