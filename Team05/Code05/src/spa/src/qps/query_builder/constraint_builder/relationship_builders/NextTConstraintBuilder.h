//
// Created by sjh_9 on 1/4/2024.
//

#ifndef SPA_NEXTTCONSTRAINTBUILDER_H
#define SPA_NEXTTCONSTRAINTBUILDER_H


#include "RelationshipConstraintBuilderTemplate.h"

class NextTConstraintBuilder: public RelationshipConstraintBuilderTemplate {
private:
    shared_ptr<StatementReference> arg1;
    shared_ptr<StatementReference> arg2;
public:
    void addConstraintClause(shared_ptr<RelationshipClause>, shared_ptr<QueryObject>) override;
};


#endif //SPA_NEXTTCONSTRAINTBUILDER_H
