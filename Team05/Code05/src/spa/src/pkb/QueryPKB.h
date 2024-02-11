#pragma once
#define SPA_QUERYPKB_H

#include <utilSpa/spaTypes.h>

// The interface between PKB and QPS
class QueryPKB {
private:
public:
    QueryPKB(); // TODO: Instantiate in TestWrapper
    ~QueryPKB();

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);
};
