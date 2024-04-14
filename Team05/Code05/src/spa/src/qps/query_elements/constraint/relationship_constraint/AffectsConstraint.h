//
// Created by sjh_9 on 1/4/2024.
//

#ifndef SPA_AFFECTSCONSTRAINT_H
#define SPA_AFFECTSCONSTRAINT_H



#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "common/Column.h"

class AffectsConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
protected:
    Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) override;
    Table getTable(QueryPkbVirtual &pkb) override;
    std::vector<std::string> getDefaultHeaders() override;
//    Table getFullTable(QueryPkbVirtual &pkb) override;
public:
    AffectsConstraint(std::shared_ptr<StatementReference>, std::shared_ptr<StatementReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    Table generateCartesianProductTable(const vector<string> &table);
    vector<string> getDistinctColumnByIndex(const Table &entityTable, int index);
    std::size_t hash() const override;
    Table getAffectsTable(QueryPkbVirtual &pkb);

};


#endif //SPA_AFFECTSCONSTRAINT_H
