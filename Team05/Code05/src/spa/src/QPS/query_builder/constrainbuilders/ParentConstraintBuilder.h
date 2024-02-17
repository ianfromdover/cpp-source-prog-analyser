//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_PARENTCONSTRAINTBUILDER_H
#define SPA_PARENTCONSTRAINTBUILDER_H

#include "ConstraintBuilder.h"

class ParentConstraintBuilder : public ConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<qps::RelationshipClause>) override;
};

#endif //SPA_PARENTCONSTRAINTBUILDER_H
