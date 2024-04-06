//
// Created by tohzh on 5/4/2024.
//

#ifndef SPA_WITHCONSTRAINTBUILDERTEMPLATE_H
#define SPA_WITHCONSTRAINTBUILDERTEMPLATE_H

#include "../ConstraintBuilderTemplate.h"
#include "qps/parser/WithClause.h"
#include "qps/query_elements/constraint/with_constraint/WithConstraint.h"

class WithConstraintBuilderTemplate : public ConstraintBuilderTemplate{
private:
    virtual void addConstraintClause(shared_ptr<WithClause>, shared_ptr<QueryObject>) = 0;
    void setNotAttribute(shared_ptr<WithClause>);
public:
    std::shared_ptr<Constraint> buildWithConstraint(shared_ptr<WithClause>, shared_ptr<QueryObject>);
};


#endif //SPA_WITHCONSTRAINTBUILDERTEMPLATE_H
