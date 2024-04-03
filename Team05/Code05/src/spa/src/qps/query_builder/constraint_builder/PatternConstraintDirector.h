//
// Created by tohzh on 16/3/2024.
//

#ifndef SPA_PATTERNCONSTRAINTDIRECTOR_H
#define SPA_PATTERNCONSTRAINTDIRECTOR_H

#include "qps/query_builder/constraint_builder/pattern_builders/AssignPatternConstraintBuilder.h"
#include "qps/query_builder/constraint_builder/pattern_builders/IfPatternConstraintBuilder.h"
#include "qps/query_builder/constraint_builder/pattern_builders/WhilePatternConstraintBuilder.h"

class PatternConstraintDirector : public ConstraintBuilderTemplate {
private:
    static QPSTokenType::QPSTypeInfo getPatternType(shared_ptr<PatternClause> r, shared_ptr<QueryObject> qo);
public:
    static shared_ptr<Constraint> process(shared_ptr<PatternClause> r, shared_ptr<QueryObject> qo);
};

#endif //SPA_PATTERNCONSTRAINTDIRECTOR_H
