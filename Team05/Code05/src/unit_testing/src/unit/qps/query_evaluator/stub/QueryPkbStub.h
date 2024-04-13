//
// Created by tohzh on 21/2/2024.
//

#pragma once
#define SPA_QUERYPKBSTUB_H


#include "pkb/apis/QueryPkbVirtual.h"
#include "pkb/apis/PkbStorage.h"

class QueryPkbStub : public QueryPkbVirtual {
private:
    Table emptyTable;
    Table callTable;
    Table readTable;
    Table ifTable;
    Table whileTable;
    Table printTable;
    Table statementTable;
    Table procedureTable;
    Table varTable;
    Table constTable;
    Table followsTable;
    Table followsTTable;
    Table parentTable;
    Table parentTTable;
    Table usesSTable;
    Table usesPTable;
    Table modifiesSTable;
    Table modifiesPTable;
    Table patternAsgnTable;
    Table patternWhileTable;
    Table patternIfTable;
    Table callsTable;
    Table callsTTable;
    Table nextTable;
    Table nextTTable;
    Table affectsTable;

public:
    void setRead(Table t);
    void setCallStmt(Table t);
    void setIf(Table t);
    void setWhile(Table t);
    void setPrint(Table t);
    void setStatement(int ending);
    void setStatement(std::vector<std::vector<std::string>> t);
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
    void setPatternWhile(std::vector<std::vector<std::string>> t);
    void setPatternIf(std::vector<std::vector<std::string>> t);
    void setCalls(std::vector<std::vector<std::string>> t);
    void setCallsT(std::vector<std::vector<std::string>> t);

    bool checkAffects(StmtNo affector, StmtNo affected) override;
    bool checkNextT(StmtNo before, StmtNo after) override;
    bool resetAffects() override;
    bool resetNextT() override;
    // entities --------------------------------------------------------------
    Table getCallTable() override;
    Table getCallAllStmts() override;
    Table getCallAllProcs() override;
    Table getCallProcsByStmt(StmtNo sNum) override;
    Table getCallStmtsByProc(ProcName proc) override;

    Table getConstTable() override;
    Table getConstAllStmts() override;
    Table getConstAllValues() override;
    Table getConstStmtsByVal(StmtNo sNum) override;
    Table getConstValuesByStmt(StmtNo sNum) override;

    Table getIfTable() override;
    Table getIfAllStmts() override;
    Table getIfAllVars() override;
    Table getIfVarsByStmt(StmtNo sNum) override;
    Table getIfStmtsByVar(VarName var) override;

    Table getPrintTable() override;
    Table getPrintAllStmts() override;
    Table getPrintAllVars() override;
    Table getPrintVarsByStmt(StmtNo sNum) override;
    Table getPrintStmtsByVar(VarName var) override;

    Table getProcTable() override;
    // should i add a containsProc method? for with clause

    Table getReadTable() override;
    Table getReadAllStmts() override;
    Table getReadAllVars() override;
    Table getReadVarsByStmt(StmtNo sNum) override;
    Table getReadStmtsByVar(VarName var) override;

    Table getStmtTable() override;
    // should i add a containsStmt method? for with clause

    Table getVarTable() override;
    Table getVarAllStmts() override;
    Table getVarAllVars() override;
    Table getVarVarsByStmt(StmtNo sNum) override;
    Table getVarStmtsByVar(VarName var) override;

    Table getWhileTable() override;
    Table getWhileAllStmts() override;
    Table getWhileAllVars() override;
    Table getWhileVarsByStmt(StmtNo sNum) override;
    Table getWhileStmtsByVar(VarName var) override;

    // relations --------------------------------------------------------------

    Table getCallsTable() override;
    Table getCallsAllCallers() override;
    Table getCallsAllCalled() override;
    Table getCallsCalledByCaller(ProcName caller) override;
    Table getCallsCallerByCalled(ProcName called) override;

    Table getCallsTTable() override;
    Table getCallsTAllCallers() override;
    Table getCallsTAllCalled() override;
    Table getCallsTCalledByCaller(ProcName caller) override;
    Table getCallsTCallerByCalled(ProcName called) override;

    Table getFollowsTable() override;
    Table getFollowsAllBefore() override;
    Table getFollowsAllAfter() override;
    Table getFollowsAfterByBefore(StmtNo before) override;
    Table getFollowsBeforeByAfter(StmtNo after) override;

    Table getFollowsTTable() override;
    Table getFollowsTAllBefore() override;
    Table getFollowsTAllAfter() override;
    Table getFollowsTAfterByBefore(StmtNo before) override;
    Table getFollowsTBeforeByAfter(StmtNo after) override;

    Table getModifiesPTable() override;
    Table getModifiesPAllProcs() override;
    Table getModifiesPAllVars() override;
    Table getModifiesPVarsByProc(ProcName modifier) override;
    Table getModifiesPProcsByVar(VarName modified) override;
    bool isModifiesP(ProcName p, VarName v) override;

    Table getModifiesSTable() override;
    Table getModifiesSAllStmts() override;
    Table getModifiesSAllVars() override;
    Table getModifiesSVarsByStmt(StmtNo modifier) override;
    Table getModifiesSStmtsByVar(VarName modified) override;

    Table getNextTable() override;
    Table getNextAllBefore() override;
    Table getNextAllAfter() override;
    Table getNextAfterByBefore(StmtNo before) override;
    Table getNextBeforeByAfter(StmtNo after) override;

    Table getParentTable() override;
    Table getParentAllChildren() override;
    Table getParentAllParents() override;
    Table getParentChildByParent(StmtNo parent) override;
    Table getParentParentByChild(StmtNo child) override;

    Table getParentTTable() override;
    Table getParentTAllChildren() override;
    Table getParentTAllParents() override;
    Table getParentTChildByParent(StmtNo parent) override;
    Table getParentTParentByChild(StmtNo child) override;

    Table getPatternAsgnTable() override;
    Table getPatternAsgnByStmt(StmtNo sNum) override;
    Table getPatternAsgnByLhs(VarName Lhs) override;
    Table getPatternAsgnByRhs(std::string Rhs) override;
    bool isAsgn(StmtNo sNum) override;

    Table getPatternIfTable() override;
    Table getPatternIfAllStmts() override;
    Table getPatternIfAllVars() override;
    Table getPatternIfVarsByStmt(StmtNo sNum) override;
    Table getPatternIfStmtsByVar(VarName var) override;

    Table getPatternWhileTable() override;
    Table getPatternWhileAllStmts() override;
    Table getPatternWhileAllVars() override;
    Table getPatternWhileVarsByStmt(StmtNo sNum) override;
    Table getPatternWhileStmtsByVar(VarName var) override;

    Table getUsesPTable() override;
    Table getUsesPAllProcs() override;
    Table getUsesPAllVars() override;
    Table getUsesPVarsByProc(ProcName user) override;
    Table getUsesPProcsByVar(VarName used) override;

    Table getUsesSTable() override;
    Table getUsesSAllStmts() override;
    Table getUsesSAllVars() override;
    Table getUsesSVarsByStmt(StmtNo user) override;
    Table getUsesSStmtsByVar(VarName used) override;
};
