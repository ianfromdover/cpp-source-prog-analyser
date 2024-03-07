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
    std::vector<std::vector<std::string>> getCallByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getCallByProc(ProcName proc) override;
    std::vector<std::vector<std::string>> getCallTable() override;
    std::vector<std::vector<std::string>> getProcByName(ProcName proc) override;
    std::vector<std::vector<std::string>> getProcTable() override;
    std::vector<std::vector<std::string>> getReadByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getReadByVar(VarName var) override;
    std::vector<std::vector<std::string>> getReadTable() override;
    std::vector<std::vector<std::string>> getIfByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getIfByVar(VarName var) override;
    std::vector<std::vector<std::string>> getIfTable() override;
    std::vector<std::vector<std::string>> getWhileByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getWhileByVar(VarName var) override;
    std::vector<std::vector<std::string>> getWhileTable() override;
    std::vector<std::vector<std::string>> getPrintByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getPrintByVar(VarName var) override;
    std::vector<std::vector<std::string>> getPrintTable() override;
    std::vector<std::vector<std::string>> getStmtByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getStmtTable() override;
    std::vector<std::vector<std::string>> getVarByName(VarName var) override;
    std::vector<std::vector<std::string>> getVarTable() override;
    std::vector<std::vector<std::string>> getConstByName(VarName var) override;
    std::vector<std::vector<std::string>> getConstTable() override;
    std::vector<std::vector<std::string>> getFollowsByBefore(StmtNo before) override;
    std::vector<std::vector<std::string>> getFollowsByAfter(StmtNo after) override;
    std::vector<std::vector<std::string>> getFollowsTable() override;
    std::vector<std::vector<std::string>> getFollowsTByBefore(StmtNo before) override;
    std::vector<std::vector<std::string>> getFollowsTByAfter(StmtNo after) override;
    std::vector<std::vector<std::string>> getFollowsTTable() override;
    std::vector<std::vector<std::string>> getParentByParent(StmtNo parent) override;
    std::vector<std::vector<std::string>> getParentByChild(StmtNo child) override;
    std::vector<std::vector<std::string>> getParentTable() override;
    std::vector<std::vector<std::string>> getParentTByParent(StmtNo parent) override;
    std::vector<std::vector<std::string>> getParentTByChild(StmtNo child) override;
    std::vector<std::vector<std::string>> getParentTTable() override;
    std::vector<std::vector<std::string>> getUsesSByNum(StmtNo user) override;
    std::vector<std::vector<std::string>> getUsesSByVar(VarName used) override;
    std::vector<std::vector<std::string>> getUsesSTable() override;
    std::vector<std::vector<std::string>> getModifiesSByNum(StmtNo modifier) override;
    std::vector<std::vector<std::string>> getModifiesSByVar(VarName modified) override;
    std::vector<std::vector<std::string>> getModifiesSTable() override;
};


#endif //SPA_QUERYPKB_H
