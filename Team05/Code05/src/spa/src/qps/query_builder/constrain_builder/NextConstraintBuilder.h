//
// Created by sjh_9 on 22/3/2024.
//

#ifndef SPA_NEXTCONSTRAINTBUILDER_H
#define SPA_NEXTCONSTRAINTBUILDER_H

#include "RelationshipConstraintBuilder.h"

class NextConstraintBuilder: public RelationshipConstraintBuilder {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_NEXTCONSTRAINTBUILDER_H
