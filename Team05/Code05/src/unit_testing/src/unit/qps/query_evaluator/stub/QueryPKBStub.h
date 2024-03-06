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

    vector<StmtNo> getChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> getSiblings(StmtNo child);
    std::shared_ptr<PKBStorage> pkb;

    bool getFollows(StmtNo before, StmtNo after);
    bool getParent(StmtNo parent, StmtNo child);

    vector<shared_ptr<ConstraintArgument>> getContraintArgs();

//    std::shared_ptr<QueryResult> getResult(Returnable& r, std::shared_ptr<Constraint> c) override;

};


#endif //SPA_QUERYPKBSTUB_H
