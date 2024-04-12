//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_USESSCONSTRAINT_H
#define SPA_USESSCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "pkb/apis/QueryPkb.h"


class UsesSConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
protected:
    Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) override;
    Table getTable(QueryPkbVirtual &pkb) override;
//    Table getFullTable(QueryPkbVirtual &pkb) override;
    std::vector<std::string> getDefaultHeaders() override;
public:
    UsesSConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<EntityReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::size_t hash() const override;

};


#endif //SPA_USESSCONSTRAINT_H
