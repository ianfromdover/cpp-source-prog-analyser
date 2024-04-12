//
// Created by tohzh on 6/3/2024.
//

#ifndef SPA_CALLSCONSTRAINT_H
#define SPA_CALLSCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "common/Column.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_projector/ResultTable.h"

class CallsConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
protected:
    Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) override;
    Table getTable(QueryPkbVirtual &pkb) override;
    std::vector<std::string> getDefaultHeaders() override;
//    Table getFullTable(QueryPkbVirtual &pkb) override;
public:
    CallsConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<EntityReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    std::size_t hash() const override;

};


#endif //SPA_CALLSCONSTRAINT_H
