//
// Created by sjh_9 on 1/4/2024.
//

#ifndef SPA_NEXTTCONSTRAINT_H
#define SPA_NEXTTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "common/Column.h"

class NextTConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    NextTConstraint(std::shared_ptr<StatementReference>, std::shared_ptr<StatementReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;

    bool isStatementSynonym(std::string type);

    std::vector<std::string> getDistinctColumnByIndex(const vector<vector<Str>> &entityTable, int index);
};

#endif //SPA_NEXTTCONSTRAINT_H
