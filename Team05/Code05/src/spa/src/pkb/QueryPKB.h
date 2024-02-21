#pragma once
#define SPA_QUERYPKB_H

#include <utilSpa/SpaTypes.h>
#include <qps/query_elements/constraint/ParentTConstraint.h>
#include "QueryPKBVirtual.h"

// The interface between PKB and QPS
class QueryPKB : public QueryPKBVirtual {
private:
public:
    QueryPKB() = default;
    QueryPKB(std::shared_ptr<PKBStorage> p);
    ~QueryPKB();

    vector<StmtNo> getChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> getSiblings(StmtNo child);
    std::shared_ptr<PKBStorage> pkb;

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    vector<shared_ptr<ConstraintArgument>> getContraintArgs();

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c) override;
    // IntResult for now
};
