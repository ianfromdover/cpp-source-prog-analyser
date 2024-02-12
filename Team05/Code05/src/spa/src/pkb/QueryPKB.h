#pragma once
#define SPA_QUERYPKB_H

#include <utilSpa/spaTypes.h>
#include <qps/query_elements/constraint/ParentTConstraint.h>
#include <memory>
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"

// The interface between PKB and QPS
class QueryPKB {
private:
public:
    QueryPKB(); // TODO: Instantiate in TestWrapper
    ~QueryPKB();

    vector<StmtNo> getChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> getSiblings(StmtNo child);

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    std::vector<ConstraintArgument*> getContraintArgs();

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c);
    // IntResult for now
};
