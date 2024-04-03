//
// Created by tohzh on 20/3/2024.
//

#ifndef SPA_WITHCONSTRAINT_H
#define SPA_WITHCONSTRAINT_H


#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_elements/constraint_argument/with_reference/WithReference.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"
#include "common/StringUtils.h"

class WithConstraint : public Constraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    bool isVariable(std::string);
public:
    WithConstraint(std::shared_ptr<WithReference>, std::shared_ptr<WithReference>);
    std::string getConstraintClass() override;
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;

    std::vector<std::vector<std::string>> getRelationshipTable(QueryPkbVirtual &) override;
};


#endif //SPA_WITHCONSTRAINT_H
