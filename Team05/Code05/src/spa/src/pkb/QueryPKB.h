#pragma once
#define SPA_QUERYPKB_H

#include <utilSpa/SpaTypes.h>
#include <qps/query_elements/constraint/ParentTConstraint.h>
#include <memory>
#include <utility>
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "PKBStorage.h"

// The interface between PKB and QPS
class QueryPKB {
private:
    std::shared_ptr<PKBStorage> pkb;
public:
    QueryPKB() = default;
    QueryPKB(std::shared_ptr<PKBStorage> p);
    ~QueryPKB();

    vector<StmtNo> getChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> getSiblings(StmtNo child);

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    vector<shared_ptr<ConstraintArgument>> getContraintArgs();

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c);
    // IntResult for now

    shared_ptr<QueryResult> queryParentTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryFollowsTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryUsesTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryModifiesTable(vector<shared_ptr<ConstraintArgument>> argList);
};
