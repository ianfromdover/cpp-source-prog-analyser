//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_PATTERNCONSTRAINT_H
#define PROJECT_PATTERNCONSTRAINT_H

#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/AssignEntity.h"
#include "qps/QueryProjector/ResultTable/ResultTable.h"
#include "qps/query_builder/ConstraintArgCreator.h"
#include <utility>

class PatternConstraint : public Constraint {
protected:
    std::string& stripCharacters(std::string& str, const std::string& chars);
public:
    std::string getConstraintClass() override;
    virtual std::shared_ptr<Entity> getPatternConstraintIdentifier() = 0;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;
};

#endif //PROJECT_PATTERNCONSTRAINT_H
