//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_QUERYPKB_H
#define SPA_QUERYPKB_H

#include "QueryPKBVirtual.h"

class QueryPKBVirtual;

class QueryPKB : public QueryPKBVirtual {
private:
    std::shared_ptr<PKBStorage> pkb;
public:
    explicit QueryPKB(std::shared_ptr<PKBStorage> p);

//    std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) override;
    std::vector<std::vector<std::string>> getRead();
    std::vector<std::vector<std::string>> getCallStmt();
    std::vector<std::vector<std::string>> getIf();
    std::vector<std::vector<std::string>> getWhile();
    std::vector<std::vector<std::string>> getPrint();
    std::vector<std::vector<std::string>> getStatement();
    std::vector<std::vector<std::string>> getProcedure();
    std::vector<std::vector<std::string>> getVar();
    std::vector<std::vector<std::string>> getConst();
    std::vector<std::vector<std::string>> getFollows();
    std::vector<std::vector<std::string>> getFollowsT();
    std::vector<std::vector<std::string>> getParent();
    std::vector<std::vector<std::string>> getParentT();
    std::vector<std::vector<std::string>> getUses();
    std::vector<std::vector<std::string>> getModifies();
    std::vector<std::vector<std::string>> getPatternAsgn();
};


#endif //SPA_QUERYPKB_H
