#pragma once
#define SPA_QUERYPKBVIRTUAL_H

#include <memory>
#include "PKBStorage.h"
#include "common/SpaTypes.h"
//#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
//#include "qps/query_elements/Returnable.h"
//#include "qps/query_elements/constraint/Constraint.h"

class QueryPKBVirtual {
public:
//    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0 = 0= 0;
//    virtual std::vector<std::vector<std::string>> getRead() = 0 = 0;
//    virtual std::vector<std::vector<std::string>> getCallStmt() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getIf() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getWhile() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getPrint() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getStatement() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getProcedure() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getVar() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getConst() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getFollows() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getFollowsT() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getParent() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getParentT() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getUses() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getModifies() = 0= 0;
//    virtual std::vector<std::vector<std::string>> getPatternAsgn() = 0 = 0;
//    virtual std::vector<std::vector<std::string>> getCalls() = 0 = 0;
//    virtual std::vector<std::vector<std::string>> getCallsT() = 0 = 0;

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
//    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0= 0;
//    virtual std::vector<std::vector<std::string>> getRead() = 0;
//    virtual std::vector<std::vector<std::string>> getCallStmt()= 0;
//    virtual std::vector<std::vector<std::string>> getIf()= 0;
//    virtual std::vector<std::vector<std::string>> getWhile()= 0;
//    virtual std::vector<std::vector<std::string>> getPrint()= 0;
//    virtual std::vector<std::vector<std::string>> getStatement()= 0;
//    virtual std::vector<std::vector<std::string>> getProcedure()= 0;
//    virtual std::vector<std::vector<std::string>> getVar()= 0;
//    virtual std::vector<std::vector<std::string>> getConst()= 0;
//    virtual std::vector<std::vector<std::string>> getFollows()= 0;
//    virtual std::vector<std::vector<std::string>> getFollowsT()= 0;
//    virtual std::vector<std::vector<std::string>> getParent()= 0;
//    virtual std::vector<std::vector<std::string>> getParentT()= 0;
//    virtual std::vector<std::vector<std::string>> getUses()= 0;
//    virtual std::vector<std::vector<std::string>> getUsesP() = 0;
//    virtual std::vector<std::vector<std::string>> getModifies()= 0;
//    virtual std::vector<std::vector<std::string>> getModifiesP() = 0;
//    virtual std::vector<std::vector<std::string>> getPatternAsgn() = 0;
//    virtual std::vector<std::vector<std::string>> getCalls() = 0;
//    virtual std::vector<std::vector<std::string>> getCallsT() = 0;
};

