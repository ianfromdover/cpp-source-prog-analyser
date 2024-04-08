//
// Created by sjh_9 on 22/3/2024.
//

#ifndef SPA_NEXTCONSTRAINT_H
#define SPA_NEXTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "common/Column.h"

class NextConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    NextConstraint(std::shared_ptr<StatementReference>, std::shared_ptr<StatementReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;

    bool isStatementSynonym(std::string type);
};


#endif //SPA_NEXTCONSTRAINT_H
