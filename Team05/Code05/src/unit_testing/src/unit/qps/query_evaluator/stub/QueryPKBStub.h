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
};


#endif //SPA_QUERYPKBSTUB_H
