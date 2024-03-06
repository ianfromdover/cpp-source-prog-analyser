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
