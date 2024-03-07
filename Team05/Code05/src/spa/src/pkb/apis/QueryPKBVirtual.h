//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_QUERYPKBVIRTUAL_H
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

    virtual std::vector<std::vector<std::string>> getCallByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getCallByProc(ProcName name) = 0;
    virtual std::vector<std::vector<std::string>> getCallTable() = 0;
    virtual std::vector<std::vector<std::string>> getProcByName(ProcName name) = 0;
    virtual std::vector<std::vector<std::string>> getProcTable() = 0;
    virtual std::vector<std::vector<std::string>> getReadByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getReadByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getReadTable() = 0;
    virtual std::vector<std::vector<std::string>> getIfByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getIfByVar(VarName var) = 0;
    virtual std::vector<std::vector<std::string>> getIfTable() = 0;
    virtual std::vector<std::vector<std::string>> getWhileByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getWhileByVar(string var) = 0;
    virtual std::vector<std::vector<std::string>> getWhileTable() = 0;
    virtual std::vector<std::vector<std::string>> getPrintByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getPrintByVar(string var) = 0;
    virtual std::vector<std::vector<std::string>> getPrintTable() = 0;
    virtual std::vector<std::vector<std::string>> getStmtByNum(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getStmtTable() = 0;
    virtual std::vector<std::vector<std::string>> getVarByName(string var) = 0;
    virtual std::vector<std::vector<std::string>> getVarTable() = 0;
    virtual std::vector<std::vector<std::string>> getConstByName(string var) = 0;
    virtual std::vector<std::vector<std::string>> getConstTable() = 0;
    virtual std::vector<std::vector<std::string>> getFollowsByBefore(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsByAfter(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTable() = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTByBefore(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTByAfter(int StmtNo) = 0;
    virtual std::vector<std::vector<std::string>> getFollowsTTable() = 0;
//    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0= 0;
    virtual std::vector<std::vector<std::string>> getRead() = 0;
    virtual std::vector<std::vector<std::string>> getCallStmt()= 0;
    virtual std::vector<std::vector<std::string>> getIf()= 0;
    virtual std::vector<std::vector<std::string>> getWhile()= 0;
    virtual std::vector<std::vector<std::string>> getPrint()= 0;
    virtual std::vector<std::vector<std::string>> getStatement()= 0;
    virtual std::vector<std::vector<std::string>> getProcedure()= 0;
    virtual std::vector<std::vector<std::string>> getVar()= 0;
    virtual std::vector<std::vector<std::string>> getConst()= 0;
    virtual std::vector<std::vector<std::string>> getFollows()= 0;
    virtual std::vector<std::vector<std::string>> getFollowsT()= 0;
    virtual std::vector<std::vector<std::string>> getParent()= 0;
    virtual std::vector<std::vector<std::string>> getParentT()= 0;
    virtual std::vector<std::vector<std::string>> getUses()= 0;
    virtual std::vector<std::vector<std::string>> getUsesP() = 0;
    virtual std::vector<std::vector<std::string>> getModifies()= 0;
    virtual std::vector<std::vector<std::string>> getModifiesP() = 0;
    virtual std::vector<std::vector<std::string>> getPatternAsgn() = 0;
    virtual std::vector<std::vector<std::string>> getCalls() = 0;
    virtual std::vector<std::vector<std::string>> getCallsT() = 0;
};

#endif //SPA_QUERYPKBVIRTUAL_H
