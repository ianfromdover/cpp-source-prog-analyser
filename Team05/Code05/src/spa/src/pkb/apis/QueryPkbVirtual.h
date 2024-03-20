#pragma once
#define SPA_QUERYPKBVIRTUAL_H

#include "PkbStorage.h"
#include "common/SpaTypes.h"
//#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
//#include "qps/query_elements/Returnable.h"
//#include "qps/query_elements/constraint/Constraint.h"

class QueryPkbVirtual {
public:
//    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0 = 0= 0;
//    virtual Table getRead() = 0 = 0;
//    virtual Table getCallStmt() = 0= 0;
//    virtual Table getIf() = 0= 0;
//    virtual Table getWhile() = 0= 0;
//    virtual Table getPrint() = 0= 0;
//    virtual Table getStatement() = 0= 0;
//    virtual Table getProcedure() = 0= 0;
//    virtual Table getVar() = 0= 0;
//    virtual Table getConst() = 0= 0;
//    virtual Table getFollows() = 0= 0;
//    virtual Table getFollowsT() = 0= 0;
//    virtual Table getParent() = 0= 0;
//    virtual Table getParentT() = 0= 0;
//    virtual Table getUses() = 0= 0;
//    virtual Table getModifies() = 0= 0;
//    virtual Table getPatternAsgn() = 0 = 0;
//    virtual Table getCalls() = 0 = 0;
//    virtual Table getCallsT() = 0 = 0;

    virtual Table getCallByNum(StmtNo sNum) = 0;
    virtual Table getCallByProc(ProcName proc) = 0;
    virtual Table getCallTable() = 0;
    virtual Table getProcByName(ProcName proc) = 0;
    virtual Table getProcTable() = 0;
    virtual Table getReadByNum(StmtNo sNum) = 0;
    virtual Table getReadByVar(VarName var) = 0;
    virtual Table getReadTable() = 0;
    virtual Table getIfByNum(StmtNo sNum) = 0;
    virtual Table getIfByVar(VarName var) = 0;
    virtual Table getIfStmts() = 0;
    virtual Table getIfTable() = 0;
    virtual Table getWhileByNum(StmtNo sNum) = 0;
    virtual Table getWhileByVar(VarName var) = 0;
    virtual Table getWhileTable() = 0;
    virtual Table getPrintByNum(StmtNo sNum) = 0;
    virtual Table getPrintByVar(VarName var) = 0;
    virtual Table getPrintTable() = 0;
    virtual Table getStmtByNum(StmtNo sNum) = 0;
    virtual Table getStmtTable() = 0;
    virtual Table getVars() = 0;
    virtual Table getVarTable() = 0;
    virtual Table getConstByName(VarName var) = 0;
    virtual Table getConsts() = 0;
    virtual Table getConstTable() = 0;
    virtual Table getFollowsByBefore(StmtNo before) = 0;
    virtual Table getFollowsByAfter(StmtNo after) = 0;
    virtual Table getFollowsTable() = 0;
    virtual Table getFollowsTByBefore(StmtNo before) = 0;
    virtual Table getFollowsTByAfter(StmtNo after) = 0;
    virtual Table getFollowsTTable() = 0;
    virtual Table getParentByParent(StmtNo parent) = 0;
    virtual Table getParentByChild(StmtNo child) = 0;
    virtual Table getParentTable() = 0;
    virtual Table getParentTByParent(StmtNo parent) = 0;
    virtual Table getParentTByChild(StmtNo child) = 0;
    virtual Table getParentTTable() = 0;
    virtual Table getUsesSByNum(StmtNo user) = 0;
    virtual Table getUsesSByVar(VarName used) = 0;
    virtual Table getUsesSTable() = 0;
    // TODO: add UsesP
    virtual Table getUsesPTable() = 0;
    virtual Table getModifiesSByNum(StmtNo modifier) = 0;
    virtual Table getModifiesSByVar(VarName modified) = 0;
    virtual Table getModifiesSTable() = 0;
    virtual Table getModifiesPByProc(ProcName modifier) = 0;
    virtual Table getModifiesPByVar(VarName modified) = 0;
    virtual Table getModifiesPTable() = 0;
    virtual Table getPatternAsgnByNum(StmtNo sNum) = 0;
    virtual Table getPatternAsgnByLhs(std::string Lhs) = 0;
    virtual Table getPatternAsgnByRhs(std::string Rhs) = 0;
    virtual Table getPatternAsgnByLhsPartial(std::string LhsPartial) = 0;
    virtual Table getPatternAsgnByRhsPartial(std::string RhsPartial) = 0;
    virtual Table getPatternAsgnTable() = 0;
    virtual Table getPatternIfByNum(StmtNo sNum) = 0;
    virtual Table getPatternIfByVar(VarName var) = 0;
    virtual Table getPatternIfTable() = 0;
    virtual Table getPatternWhileByNum(StmtNo sNum) = 0;
    virtual Table getPatternWhileByVar(VarName var) = 0;
    virtual Table getWhileStmts() = 0;
    virtual Table getPatternWhileTable() = 0;
    virtual Table getCallsByCaller(ProcName caller) = 0;
    virtual Table getCallsByCalled(ProcName called) = 0;
    virtual Table getCallsTable() = 0;
    virtual Table getCallsTByCaller(ProcName caller) = 0;
    virtual Table getCallsTByCalled(ProcName called) = 0;
    virtual Table getCallsTTable() = 0;
    virtual Table getNextByBefore(StmtNo before) = 0;
    virtual Table getNextByAfter(StmtNo after) = 0;
    virtual Table getNextTable() = 0;
    virtual Table getNextTByBefore(StmtNo before) = 0;
    virtual Table getNextTByAfter(StmtNo after) = 0;
    virtual Table getNextTTable() = 0;
    virtual Table getAffectsByBefore(StmtNo before) = 0;
    virtual Table getAffectsByAfter(StmtNo after) = 0;
    virtual Table getAffectsTable() = 0;
//    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0= 0;
//    virtual Table getRead() = 0;
//    virtual Table getCallStmt()= 0;
//    virtual Table getIf()= 0;
//    virtual Table getWhile()= 0;
//    virtual Table getPrint()= 0;
//    virtual Table getStatement()= 0;
//    virtual Table getProcedure()= 0;
//    virtual Table getVar()= 0;
//    virtual Table getConst()= 0;
//    virtual Table getFollows()= 0;
//    virtual Table getFollowsT()= 0;
//    virtual Table getParent()= 0;
//    virtual Table getParentT()= 0;
//    virtual Table getUses()= 0;
//    virtual Table getUsesP() = 0;
//    virtual Table getModifies()= 0;
//    virtual Table getModifiesP() = 0;
//    virtual Table getPatternAsgn() = 0;
//    virtual Table getCalls() = 0;
//    virtual Table getCallsT() = 0;
};

