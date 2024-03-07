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

//    std::vector<std::vector<std::string>> getRead() override override;
//    std::vector<std::vector<std::string>> getCallStmt() override override;
//    std::vector<std::vector<std::string>> getIf() override override;
//    std::vector<std::vector<std::string>> getWhile() override override;
//    std::vector<std::vector<std::string>> getPrint() override override;
//    std::vector<std::vector<std::string>> getStatement() override override;
//    std::vector<std::vector<std::string>> getProcedure() override override;
//    std::vector<std::vector<std::string>> getVar() override override;
//    std::vector<std::vector<std::string>> getConst() override override;
//    std::vector<std::vector<std::string>> getFollows() override override;
//    std::vector<std::vector<std::string>> getFollowsT() override override;
//    std::vector<std::vector<std::string>> getParent() override override;
//    std::vector<std::vector<std::string>> getParentT() override override;
//    std::vector<std::vector<std::string>> getUses() override override;
//    std::vector<std::vector<std::string>> getModifies() override override;
//    std::vector<std::vector<std::string>> getPatternAsgn() override override;
//    std::vector<std::vector<std::string>> getCalls() override override;
//    std::vector<std::vector<std::string>> getCallsT() override override;

    // methods to convert to vec<vec<string>>
    template <typename A>
    std::vector<std::vector<std::string>> toVecVecStr(std::vector<A> vec);
    vector<vector<std::string>> toVecVecStr(vector<std::string> vec);
    // TODO: remove the following once confirmed that we don't need it
//    template <typename A, typename B>
//    vector<vector<std::string>> toVecVecStr(TwoSideMap<A, B> map) override;
//    vector<vector<std::string>> toVecVecStr(string element) override;

    // refactor get
    std::vector<std::vector<std::string>> getCallByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getCallByProc(ProcName name) override;
    std::vector<std::vector<std::string>> getCallTable() override;
    std::vector<std::vector<std::string>> getProcByName(ProcName name) override;
    std::vector<std::vector<std::string>> getProcTable() override;
    std::vector<std::vector<std::string>> getReadByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getReadByVar(VarName var) override;
    std::vector<std::vector<std::string>> getReadTable() override;
    std::vector<std::vector<std::string>> getIfByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getIfByVar(VarName var) override;
    std::vector<std::vector<std::string>> getIfTable() override;
    std::vector<std::vector<std::string>> getWhileByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getWhileByVar(string var) override;
    std::vector<std::vector<std::string>> getWhileTable() override;
    std::vector<std::vector<std::string>> getPrintByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getPrintByVar(string var) override;
    std::vector<std::vector<std::string>> getPrintTable() override;
    std::vector<std::vector<std::string>> getStmtByNum(int StmtNo) override;
    std::vector<std::vector<std::string>> getStmtTable() override;
    std::vector<std::vector<std::string>> getVarByName(string var) override;
    std::vector<std::vector<std::string>> getVarTable() override;
    std::vector<std::vector<std::string>> getConstByName(string var) override;
    std::vector<std::vector<std::string>> getConstTable() override;
    std::vector<std::vector<std::string>> getFollowsByBefore(int StmtNo) override;
    std::vector<std::vector<std::string>> getFollowsByAfter(int StmtNo) override;
    std::vector<std::vector<std::string>> getFollowsTable() override;
    std::vector<std::vector<std::string>> getFollowsTByBefore(int StmtNo) override;
    std::vector<std::vector<std::string>> getFollowsTByAfter(int StmtNo) override;
    std::vector<std::vector<std::string>> getFollowsTTable() override;
};


#endif //SPA_QUERYPKB_H
