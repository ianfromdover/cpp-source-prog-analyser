//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_QUERYPKB_H
#define SPA_QUERYPKB_H

#include "QueryPKBVirtual.h"
#include "pkb/storage/base/TwoSideMap.hpp"

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

    // methods to convert to vec<vec<string>>
    template <typename A>
    std::vector<std::vector<std::string>> toVecVecStr(std::vector<A> vec);
    vector<vector<std::string>> toVecVecStr(vector<std::string> vec);
//    template <typename A, typename B>
//    vector<vector<std::string>> toVecVecStr(TwoSideMap<A, B> map);
//    vector<vector<std::string>> toVecVecStr(string element);

    // refactor get
    std::vector<std::vector<std::string>> getCallByProc(ProcName name);
    std::vector<std::vector<std::string>> getProc(StmtNo sNum);
    std::vector<std::vector<std::string>> getReadByNum(int StmtNo);
    std::vector<std::vector<std::string>> getReadByVar(VarName var);
    std::vector<std::vector<std::string>> getIfByNum(int StmtNo);
    std::vector<std::vector<std::string>> getIfByVar(VarName var);
    std::vector<std::vector<std::string>> getWhileByNum(int StmtNo);
    std::vector<std::vector<std::string>> getWhileByVar(string var);
    std::vector<std::vector<std::string>> getPrintByNum(int StmtNo);
    std::vector<std::vector<std::string>> getPrintByVar(string var);
    std::vector<std::vector<std::string>> getStmtByNum(int StmtNo);
    std::vector<std::vector<std::string>> getProcByName(string proc);
    std::vector<std::vector<std::string>> getVarByName(string var);
    std::vector<std::vector<std::string>> getConstByName(string var);
    std::vector<std::vector<std::string>> getFollowsByBefore(int StmtNo);
    std::vector<std::vector<std::string>> getFollowsByAfter(int StmtNo);
};


#endif //SPA_QUERYPKB_H
