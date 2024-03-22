//
// Created by tohzh on 16/3/2024.
//

#ifndef SPA_PATTERNCONSTRAINTBUILDERTEMPLATE_H
#define SPA_PATTERNCONSTRAINTBUILDERTEMPLATE_H

#include "../ConstraintBuilderTemplate.h"
#include "qps/parser/PatternClause.h"

class PatternConstraintBuilderTemplate : public ConstraintBuilderTemplate {
private:
    virtual void addConstraintClause(shared_ptr<PatternClause>, shared_ptr<QueryObject>) = 0;
public:
    std::shared_ptr<Constraint> buildRelationConstraint(shared_ptr<PatternClause>, shared_ptr<QueryObject>);
};

#endif //SPA_PATTERNCONSTRAINTBUILDERTEMPLATE_H
