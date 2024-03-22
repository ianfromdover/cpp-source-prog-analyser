//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_ASSIGNPATTERNCONSTRAINTBUILDER_H
#define SPA_ASSIGNPATTERNCONSTRAINTBUILDER_H

#include "PatternConstraintBuilderTemplate.h"
#include "qps/parser/PatternClause.h"

class AssignPatternConstraintBuilder : public PatternConstraintBuilderTemplate {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<ExpressionReference> arg2;
    shared_ptr<AssignEntity> syn;
    void addPatternClause(std::shared_ptr<PatternClause>, shared_ptr<QueryObject>);
public:
    void addConstraintClause(shared_ptr<PatternClause>, shared_ptr<QueryObject>);
};

#endif //SPA_ASSIGNPATTERNCONSTRAINTBUILDER_H
