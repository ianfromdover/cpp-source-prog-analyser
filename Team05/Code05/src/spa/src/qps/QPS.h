//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QPS_H
#define SPA_QPS_H

#include <vector>
#include <string>
#include "QueryPreprocessor/QueryPreprocessor.h"
#include "QueryEvaluator/QueryEvaluator.h"
#include "pkb/QueryPKB.h"

class QPS {
public:
    QPS(std::shared_ptr<QueryPKBVirtual> pkbInstance): pkb(std::move(pkbInstance)) {};
    std::vector<std::string> evaluate(std::string);
    std::shared_ptr<QueryPKBVirtual> pkb;
};


#endif //SPA_QPS_H
