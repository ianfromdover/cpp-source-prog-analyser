//
// Created by tohzh on 6/3/2024.
//

#ifndef SPA_CALLSTCONSTRAINT_H
#define SPA_CALLSTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "utilSpa/Column.h"
#include "pkb/constraintTablesNew/FollowsTableNew.h"
#include "pkb/apis/QueryPKB.h"
#include "qps/QueryProjector/ResultTable/ResultTable.h"

class CallsTConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    CallsTConstraint(std::shared_ptr<EntityReference>, std::shared_ptr<EntityReference>);
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;

    bool isStatementSynonym(std::string type);
    bool isEntitySynonym(std::string type);

    string &stripCharacters(string &str, const string &chars);
};


#endif //SPA_CALLSTCONSTRAINT_H
