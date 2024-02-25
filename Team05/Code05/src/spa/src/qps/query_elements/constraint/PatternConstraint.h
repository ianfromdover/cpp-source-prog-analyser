//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_PATTERNCONSTRAINT_H
#define PROJECT_PATTERNCONSTRAINT_H

#include "qps/query_elements/constraint/Constraint.h"
#include "../constraint_argument/statement_reference/AssignEntity.h"

class PatternConstraint : public Constraint {
public:
    std::string getConstraintClass() override;
    virtual std::shared_ptr<AssignEntity> getPatternConstraintIdentifier() = 0;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKB &) override;
};

#endif //PROJECT_PATTERNCONSTRAINT_H
