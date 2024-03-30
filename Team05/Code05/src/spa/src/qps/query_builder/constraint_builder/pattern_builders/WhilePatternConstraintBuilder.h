//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_WHILEPATTERNCONSTRAINTBUILDER_H
#define SPA_WHILEPATTERNCONSTRAINTBUILDER_H

#include "PatternConstraintBuilderTemplate.h"
#include "qps/parser/PatternClause.h"
#include "qps/query_elements/constraint/patternConstraint/WhilePatternConstraint.h"

class WhilePatternConstraintBuilder : public PatternConstraintBuilderTemplate {
private:
    shared_ptr<EntityReference> arg1;
    shared_ptr<ExpressionReference> arg2;
    shared_ptr<WhileEntity> syn;
    void addPatternClause(std::shared_ptr<PatternClause>, shared_ptr<QueryObject>);
public:
    void addConstraintClause(shared_ptr<PatternClause>, shared_ptr<QueryObject>);
};


#endif //SPA_WHILEPATTERNCONSTRAINTBUILDER_H
