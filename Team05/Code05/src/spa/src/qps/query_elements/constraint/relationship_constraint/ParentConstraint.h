//
// Created by tohzh on 10/2/2024.
//

#ifndef SPA_PARENTCONSTRAINT_H
#define SPA_PARENTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"

class ParentConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
protected:
    Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) override;
    Table getTable(QueryPkbVirtual &pkb) override;
    std::vector<std::string> getDefaultHeaders() override;
//    Table getFullTable(QueryPkbVirtual &pkb) override;
public:
    ParentConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<StatementReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::size_t hash() const override;
};


#endif //SPA_PARENTCONSTRAINT_H
