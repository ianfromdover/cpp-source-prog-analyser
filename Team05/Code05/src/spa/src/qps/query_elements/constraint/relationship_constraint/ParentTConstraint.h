//
// Created by tohzh on 10/2/2024.
//

#ifndef SPA_PARENTTCONSTRAINT_H
#define SPA_PARENTTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"

class ParentTConstraint :public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    Table getTable(QueryPkbVirtual &pkb);
public:
    ParentTConstraint(std::shared_ptr<ConstraintArgument>, std::shared_ptr<ConstraintArgument>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;

    bool isStatementSynonym(string type);
};


#endif //SPA_PARENTTCONSTRAINT_H
