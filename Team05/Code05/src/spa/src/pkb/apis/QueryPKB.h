//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_QUERYPKB_H
#define SPA_QUERYPKB_H

#include "QueryPKBVirtual.h"
#include "utilSpa/StringColumn.h"
#include "utilSpa/IntColumn.h"

class QueryPKB : public QueryPKBVirtual {
private:
    std::shared_ptr<PKBStorage> pkb;
public:
    explicit QueryPKB(std::shared_ptr<PKBStorage> p);
//
      pair<IntColumn, StringColumn> getRead();
//    pair<IntColumn, StringColumn> getCallStmt();
//    pair<IntColumn, StringColumn> getIf();
//    pair<IntColumn, StringColumn> getWhile();
//    pair<IntColumn, StringColumn> getPrint();
//    pair<IntColumn, IntColumn> getFinalStatementNo();
//    pair<StringColumn, StringColumn> getProcedure(std::string name);
//    pair<IntColumn, StringColumn> getVar();
//    pair<IntColumn, IntColumn> getConst();
//    pair<IntColumn, IntColumn> getFollows();
//    pair<IntColumn, IntColumn> getFollowsT();
//    pair<IntColumn, IntColumn> getParent();
//    pair<IntColumn, IntColumn> getParentT();
//    pair<IntColumn, StringColumn> getUses();
//    pair<IntColumn, StringColumn> getModifies();
//    pair<IntColumn, StringColumn> getPatternAsgn();
};


#endif //SPA_QUERYPKB_H
