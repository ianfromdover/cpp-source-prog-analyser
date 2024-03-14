//
// Created by tohzh on 21/2/2024.
//

#pragma once
#define SPA_QUERYPKBSTUB_H


#include "pkb/apis/QueryPKBVirtual.h"
#include "pkb/apis/PKBStorage.h"

class QueryPKBStub : public QueryPKBVirtual {
private:
    std::shared_ptr<PKBStorage> pkb;

public:
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
    std::vector<std::vector<std::string>> getUsesP();
    std::vector<std::vector<std::string>> getModifies();
    std::vector<std::vector<std::string>> getModifiesP();
    std::vector<std::vector<std::string>> getPatternAsgn();
    std::vector<std::vector<std::string>> getCalls();
    std::vector<std::vector<std::string>> getCallsT();

    void setRead(std::vector<std::vector<std::string>> t);
    void setCallStmt(std::vector<std::vector<std::string>> t);
    void setIf(std::vector<std::vector<std::string>> t);
    void setWhile(std::vector<std::vector<std::string>> t);
    void setPrint(std::vector<std::vector<std::string>> t);
    void setStatement(int ending);
    void setProcedure(std::vector<std::vector<std::string>> t);
    void setVar(std::vector<std::vector<std::string>> t);
    void setConst(std::vector<std::vector<std::string>> t);
    void setFollows(std::vector<std::vector<std::string>> t);
    void setFollowsT(std::vector<std::vector<std::string>> t);
    void setParent(std::vector<std::vector<std::string>> t);
    void setParentT(std::vector<std::vector<std::string>> t);
    void setUses(std::vector<std::vector<std::string>> t);
    void setUsesP(std::vector<std::vector<std::string>> t);
    void setModifies(std::vector<std::vector<std::string>> t);
    void setModifiesP(std::vector<std::vector<std::string>> t);
    void setPatternAsgn(std::vector<std::vector<std::string>> t);
    void setCalls(std::vector<std::vector<std::string>> t);
    void setCallsT(std::vector<std::vector<std::string>> t);

    // lack of implementation is causing errors, so implement duds for MS2 first.
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
    // TODO: add UsesP
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
