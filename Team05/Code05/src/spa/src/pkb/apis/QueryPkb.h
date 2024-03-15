#pragma once
#define SPA_QUERYPKB_H

#include "QueryPkbVirtual.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class QueryPkbVirtual;

class QueryPkb : public QueryPkbVirtual {
private:
    std::shared_ptr<PkbStorage> pkb;
public:
    explicit QueryPkb(std::shared_ptr<PkbStorage> p);

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
    // TODO: add the other UsesP stuff
    std::vector<std::vector<std::string>> getUsesPTable() override;
    std::vector<std::vector<std::string>> getModifiesSByNum(StmtNo modifier) override;
    std::vector<std::vector<std::string>> getModifiesSByVar(VarName modified) override;
    std::vector<std::vector<std::string>> getModifiesSTable() override;
    std::vector<std::vector<std::string>> getModifiesPByProc(ProcName modifier) override;
    std::vector<std::vector<std::string>> getModifiesPByVar(VarName modified) override;
    std::vector<std::vector<std::string>> getModifiesPTable() override;
    std::vector<std::vector<std::string>> getPatternAsgnByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getPatternAsgnByLhs(std::string Lhs) override;
    std::vector<std::vector<std::string>> getPatternAsgnByRhs(std::string Rhs) override;
    std::vector<std::vector<std::string>> getPatternAsgnByLhsPartial(std::string LhsPartial) override;
    std::vector<std::vector<std::string>> getPatternAsgnByRhsPartial(std::string RhsPartial) override;
    std::vector<std::vector<std::string>> getPatternAsgnTable() override;
    std::vector<std::vector<std::string>> getPatternIfByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getPatternIfByVar(VarName var) override;
    std::vector<std::vector<std::string>> getPatternIfTable() override;
    std::vector<std::vector<std::string>> getPatternWhileByNum(StmtNo sNum) override;
    std::vector<std::vector<std::string>> getPatternWhileByVar(VarName var) override;
    std::vector<std::vector<std::string>> getPatternWhileTable() override;
    std::vector<std::vector<std::string>> getCallsByCaller(ProcName caller) override;
    std::vector<std::vector<std::string>> getCallsByCalled(ProcName called) override;
    std::vector<std::vector<std::string>> getCallsTable() override;
    std::vector<std::vector<std::string>> getCallsTByCaller(ProcName caller) override;
    std::vector<std::vector<std::string>> getCallsTByCalled(ProcName called) override;
    std::vector<std::vector<std::string>> getCallsTTable() override;
    std::vector<std::vector<std::string>> getNextByBefore(StmtNo before) override;
    std::vector<std::vector<std::string>> getNextByAfter(StmtNo after) override;
    std::vector<std::vector<std::string>> getNextTable() override;
    std::vector<std::vector<std::string>> getNextTByBefore(StmtNo before) override;
    std::vector<std::vector<std::string>> getNextTByAfter(StmtNo after) override;
    std::vector<std::vector<std::string>> getNextTTable() override;
    std::vector<std::vector<std::string>> getAffectsByBefore(StmtNo before) override;
    std::vector<std::vector<std::string>> getAffectsByAfter(StmtNo after) override;
    std::vector<std::vector<std::string>> getAffectsTable() override;
};
