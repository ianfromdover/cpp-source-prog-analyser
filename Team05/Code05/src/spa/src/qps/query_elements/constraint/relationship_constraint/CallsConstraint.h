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
    Table getTable(QueryPkbVirtual &pkb);
public:
    CallsConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<EntityReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;

    bool isStatementSynonym(std::string type);
    bool isEntitySynonym(std::string type);

    string &stripCharacters(string &str, const string &chars);
};


#endif //SPA_CALLSCONSTRAINT_H
