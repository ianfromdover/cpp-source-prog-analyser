//
// Created by tohzh on 21/2/2024.
//

#ifndef SPA_QUERYPKBSTUB_H
#define SPA_QUERYPKBSTUB_H


#include "pkb/apis/QueryPKBVirtual.h"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/QueryEvaluator/QueryResult/StringResult.h"
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"
#include "pkb/apis/PKBStorage.h"
#include "common/SpaTypes.h"

using table = std::vector<std::vector<std::string>>;

class QueryPKBStub : public QueryPKBVirtual {
private:
    vector<StmtNo> getChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> getSiblings(StmtNo child);
    std::shared_ptr<PKBStorage> pkb;
    table readTable;
    table callStmtTable;
    table ifTable;
    table whileTable;
    table printTable;
    table statementTable;
    table procedureTable;
    table varTable;
    table constTable;
    table followsTable;
    table followsTTable;
    table parentTable;
    table parentTTable;
    table usesTable;
    table usesPTable;
    table modifiesTable;
    table modifiesPTable;
    table assignTable;
    table callsTable;
    table callsTTable;

public:
    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    vector<shared_ptr<ConstraintArgument>> getContraintArgs();

//    std::shared_ptr<QueryResult> getResult(Returnable& r, std::shared_ptr<Constraint> c) override;

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
    void setCalls(std::vector<std::vector<std::string>> t);
    void setCallsT(std::vector<std::vector<std::string>> t);

    virtual std::vector<std::vector<std::string>> getCallByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getCallByProc(ProcName proc) = 0;
    virtual std::vector<std::vector<std::string>> getCallTable() = 0;
    virtual std::vector<std::vector<std::string>> getProcByName(ProcName proc) = 0;
    virtual std::vector<std::vector<std::string>> getProcTable() = 0;
    virtual std::vector<std::vector<std::string>> getReadByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getReadByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getReadTable() = 0;
    virtual std::vector<std::vector<std::string>> getIfByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getIfByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getIfTable() = 0;
    virtual std::vector<std::vector<std::string>> getWhileByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getWhileByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getWhileTable() = 0;
    virtual std::vector<std::vector<std::string>> getPrintByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getPrintByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getPrintTable() = 0;
    virtual std::vector<std::vector<std::string>> getStmtByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getStmtTable() = 0;
    virtual std::vector<std::vector<std::string>> getVarByName(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getVarTable() = 0;
    virtual std::vector<std::vector<std::string>> getConstByName(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getConstTable() = 0;
    virtual std::vector<std::vector<std::string>> getFollowsByBefore(StmtNo before) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsByAfter(StmtNo after) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTable() = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTByBefore(StmtNo before) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTByAfter(StmtNo after) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTTable() = 0;
    virtual std::vector<std::vector<std::string>> getParentByParent(StmtNo parent) = 0;
    virtual std::vector<std::vector<std::string>> getParentByChild(StmtNo child) = 0;
    virtual std::vector<std::vector<std::string>> getParentTable() = 0;
    virtual std::vector<std::vector<std::string>> getParentTByParent(StmtNo parent) = 0;
    virtual std::vector<std::vector<std::string>> getParentTByChild(StmtNo child) = 0;
    virtual std::vector<std::vector<std::string>> getParentTTable() = 0;
    virtual std::vector<std::vector<std::string>> getUsesSByNum(StmtNo user) = 0;
    virtual std::vector<std::vector<std::string>> getUsesSByVar(VarName used) = 0;
    virtual std::vector<std::vector<std::string>> getUsesSTable() = 0;
    // TODO: add UsesP
    virtual std::vector<std::vector<std::string>> getUsesPTable() = 0;
    virtual std::vector<std::vector<std::string>> getModifiesSByNum(StmtNo modifier) = 0;
    virtual std::vector<std::vector<std::string>> getModifiesSByVar(VarName modified) = 0;
    virtual std::vector<std::vector<std::string>> getModifiesSTable() = 0;
    virtual std::vector<std::vector<std::string>> getModifiesPByProc(ProcName modifier) = 0;
    virtual std::vector<std::vector<std::string>> getModifiesPByVar(VarName modified) = 0;
    virtual std::vector<std::vector<std::string>> getModifiesPTable() = 0;
    virtual std::vector<std::vector<std::string>> getPatternByNum(StmtNo sNum) = 0;
    virtual std::vector<std::vector<std::string>> getPatternByLhs(std::string Lhs) = 0;
    virtual std::vector<std::vector<std::string>> getPatternByRhs(std::string Rhs) = 0;
    virtual std::vector<std::vector<std::string>> getPatternByLhsPartial(std::string LhsPartial) = 0;
    virtual std::vector<std::vector<std::string>> getPatternByRhsPartial(std::string RhsPartial) = 0;
    virtual std::vector<std::vector<std::string>> getPatternTable() = 0;
    virtual std::vector<std::vector<std::string>> getCallsByCaller(ProcName caller) = 0;
    virtual std::vector<std::vector<std::string>> getCallsByCalled(ProcName called) = 0;
    virtual std::vector<std::vector<std::string>> getCallsTable() = 0;
    virtual std::vector<std::vector<std::string>> getCallsTByCaller(ProcName caller) = 0;
    virtual std::vector<std::vector<std::string>> getCallsTByCalled(ProcName called) = 0;
    virtual std::vector<std::vector<std::string>> getCallsTTable() = 0;
    virtual std::vector<std::vector<std::string>> getNextByBefore(StmtNo before) = 0;
    virtual std::vector<std::vector<std::string>> getNextByAfter(StmtNo after) = 0;
    virtual std::vector<std::vector<std::string>> getNextTable() = 0;
    virtual std::vector<std::vector<std::string>> getNextTByBefore(StmtNo before) = 0;
    virtual std::vector<std::vector<std::string>> getNextTByAfter(StmtNo after) = 0;
    virtual std::vector<std::vector<std::string>> getNextTTable() = 0;
    virtual std::vector<std::vector<std::string>> getAffectsByBefore(StmtNo before) = 0;
    virtual std::vector<std::vector<std::string>> getAffectsByAfter(StmtNo after) = 0;
    virtual std::vector<std::vector<std::string>> getAffectsTable() = 0;
};


#endif //SPA_QUERYPKBSTUB_H
