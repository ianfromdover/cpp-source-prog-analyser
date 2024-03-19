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

    std::vector<std::vector<std::string>> getRead() override;
    std::vector<std::vector<std::string>> getCallStmt() override;
    std::vector<std::vector<std::string>> getIf() override;
    std::vector<std::vector<std::string>> getWhile() override;
    std::vector<std::vector<std::string>> getPrint() override;
    std::vector<std::vector<std::string>> getStatement() override;
    std::vector<std::vector<std::string>> getProcedure() override;
    std::vector<std::vector<std::string>> getVar() override;
    std::vector<std::vector<std::string>> getConst() override;
    std::vector<std::vector<std::string>> getFollows() override;
    std::vector<std::vector<std::string>> getFollowsT() override;
    std::vector<std::vector<std::string>> getParent() override;
    std::vector<std::vector<std::string>> getParentT() override;
    std::vector<std::vector<std::string>> getUses() override;
    std::vector<std::vector<std::string>> getUsesP() override;
    std::vector<std::vector<std::string>> getModifies() override;
    std::vector<std::vector<std::string>> getModifiesP() override;
    std::vector<std::vector<std::string>> getPatternAsgn() override;
    std::vector<std::vector<std::string>> getCalls() override;
    std::vector<std::vector<std::string>> getCallsT() override;
    std::vector<std::vector<std::string>> getNext() override;
};


#endif //SPA_QUERYPKB_H
