//
// Created by tohzh on 21/2/2024.
//

#ifndef SPA_QUERYPKBVIRTUAL_H
#define SPA_QUERYPKBVIRTUAL_H

#include <memory>
#include "PKBStorage.h"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "qps/query_elements/Returnable.h"
#include "qps/query_elements/constraint/Constraint.h"

class QueryPKBVirtual {
public:
    virtual std::shared_ptr<QueryResult> getResult(Returnable&, std::shared_ptr<Constraint>) = 0;
};

#endif //SPA_QUERYPKBVIRTUAL_H
