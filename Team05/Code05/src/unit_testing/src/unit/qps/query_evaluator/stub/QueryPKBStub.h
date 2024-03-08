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

class QueryPKBStub : public QueryPKBVirtual {

    std::shared_ptr<PKBStorage> pkb;

    std::vector<std::vector<std::string>> getRead() override;
    std::vector<std::vector<std::string>> getCallStmt() override;
    std::vector<std::vector<std::string>> getIf() override;
    std::vector<std::vector<std::string>> getWhile() override;
    std::vector<std::vector<std::string>> getPrint() override;
    std::vector<std::vector<std::string>> getStatement() override;
    std::vector<std::vector<std::string>> getProcedure() override;
    std::vector<std::vector<std::string>> getVar() override;
    std::vector<std::vector<std::string>> getConst() override;
    std::vector<std::vector<std::string>> getFollows() override;
    std::vector<std::vector<std::string>> getFollowsT() override;
    std::vector<std::vector<std::string>> getParent() override;
    std::vector<std::vector<std::string>> getParentT() override;
    std::vector<std::vector<std::string>> getUses() override;
    std::vector<std::vector<std::string>> getModifies() override;
    std::vector<std::vector<std::string>> getPatternAsgn() override;


};


#endif //SPA_QUERYPKBSTUB_H
