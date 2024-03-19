//
// Created by tohzh on 21/2/2024.
//

#pragma once
#define SPA_QUERYPKBSTUB_H


#include "pkb/apis/QueryPkbVirtual.h"
#include "pkb/apis/PkbStorage.h"

class QueryPkbStub : public QueryPkbVirtual {
private:
    Table table;

public:
    void setRead(Table t);
    void setCallStmt(Table t);
    void setIf(Table t);
    void setWhile(Table t);
    void setPrint(Table t);
    void setStatement(int ending);
    void setProcedure(Table t);
    void setVar(Table t);
    void setConst(Table t);
    void setFollows(Table t);
    void setFollowsT(Table t);
    void setParent(Table t);
    void setParentT(Table t);
    void setUses(Table t);
    void setUsesP(Table t);
    void setModifies(Table t);
    void setModifiesP(Table t);
    void setPatternAsgn(Table t);
    void setCalls(Table t);
    void setCallsT(Table t);

    // lack of implementation is causing errors, so implement duds for MS2 first.
    Table getCallByNum(StmtNo sNum) override;
    Table getCallByProc(ProcName proc) override;
    Table getCallTable() override;
    Table getProcByName(ProcName proc) override;
    Table getProcTable() override;
    Table getReadByNum(StmtNo sNum) override;
    Table getReadByVar(VarName var) override;
    Table getReadTable() override;
    Table getIfByNum(StmtNo sNum) override;
    Table getIfByVar(VarName var) override;
    Table getIfTable() override;
    Table getWhileByNum(StmtNo sNum) override;
    Table getWhileByVar(VarName var) override;
    Table getWhileTable() override;
    Table getPrintByNum(StmtNo sNum) override;
    Table getPrintByVar(VarName var) override;
    Table getPrintTable() override;
    Table getStmtByNum(StmtNo sNum) override;
    Table getStmtTable() override;
    Table getVarByName(VarName var) override;
    Table getVarTable() override;
    Table getConstByName(VarName var) override;
    Table getConstTable() override;
    Table getFollowsByBefore(StmtNo before) override;
    Table getFollowsByAfter(StmtNo after) override;
    Table getFollowsTable() override;
    Table getFollowsTByBefore(StmtNo before) override;
    Table getFollowsTByAfter(StmtNo after) override;
    Table getFollowsTTable() override;
    Table getParentByParent(StmtNo parent) override;
    Table getParentByChild(StmtNo child) override;
    Table getParentTable() override;
    Table getParentTByParent(StmtNo parent) override;
    Table getParentTByChild(StmtNo child) override;
    Table getParentTTable() override;
    Table getUsesSByNum(StmtNo user) override;
    Table getUsesSByVar(VarName used) override;
    Table getUsesSTable() override;
    // TODO: add UsesP
    Table getUsesPTable() override;
    Table getModifiesSByNum(StmtNo modifier) override;
    Table getModifiesSByVar(VarName modified) override;
    Table getModifiesSTable() override;
    Table getModifiesPByProc(ProcName modifier) override;
    Table getModifiesPByVar(VarName modified) override;
    Table getModifiesPTable() override;
    Table getPatternAsgnByNum(StmtNo sNum) override;
    Table getPatternAsgnByLhs(std::string Lhs) override;
    Table getPatternAsgnByRhs(std::string Rhs) override;
    Table getPatternAsgnByLhsPartial(std::string LhsPartial) override;
    Table getPatternAsgnByRhsPartial(std::string RhsPartial) override;
    Table getPatternAsgnTable() override;
    Table getPatternIfByNum(StmtNo sNum) override;
    Table getPatternIfByVar(VarName var) override;
    Table getPatternIfTable() override;
    Table getPatternWhileByNum(StmtNo sNum) override;
    Table getPatternWhileByVar(VarName var) override;
    Table getPatternWhileTable() override;
    Table getCallsByCaller(ProcName caller) override;
    Table getCallsByCalled(ProcName called) override;
    Table getCallsTable() override;
    Table getCallsTByCaller(ProcName caller) override;
    Table getCallsTByCalled(ProcName called) override;
    Table getCallsTTable() override;
    Table getNextByBefore(StmtNo before) override;
    Table getNextByAfter(StmtNo after) override;
    Table getNextTable() override;
    Table getNextTByBefore(StmtNo before) override;
    Table getNextTByAfter(StmtNo after) override;
    Table getNextTTable() override;
    Table getAffectsByBefore(StmtNo before) override;
    Table getAffectsByAfter(StmtNo after) override;
    Table getAffectsTable() override;
};
