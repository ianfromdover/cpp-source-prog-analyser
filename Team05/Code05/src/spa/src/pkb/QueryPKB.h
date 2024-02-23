#pragma once
#define SPA_QUERYPKB_H

#include <utilSpa/SpaTypes.h>
#include <qps/query_elements/constraint/ParentTConstraint.h>
#include "QueryPKBVirtual.h"
#include <memory>
#include <utility>
#include <utilSpa/SpaTypes.h>
#include "PKBStorage.h"
#include "qps/query_elements/constraint/ParentTConstraint.h"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"

// The interface between PKB and QPS
class QueryPKB : public QueryPKBVirtual {
private:
    std::shared_ptr<PKBStorage> pkb;
public:
    QueryPKB() = default;
    QueryPKB(std::shared_ptr<PKBStorage> p);
    ~QueryPKB();

//    vector<StmtNo> getChildren(StmtNo parent);
//    StmtNo getParent(StmtNo child);
//    vector<StmtNo> getSiblings(StmtNo child);

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    vector<shared_ptr<ConstraintArgument>> getContraintArgs();

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c) override;
    // IntResult for now

    shared_ptr<QueryResult> queryParentTable(Returnable &r, vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryFollowsTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryUsesTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryModifiesSTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryModifiesPTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryParentTTable(vector<shared_ptr<ConstraintArgument>> argList);

    shared_ptr<QueryResult> queryFollowsTTable(vector<shared_ptr<ConstraintArgument>> argList);
};
