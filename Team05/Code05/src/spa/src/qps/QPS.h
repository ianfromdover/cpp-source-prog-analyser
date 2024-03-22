//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QPS_H
#define SPA_QPS_H

#include <vector>
#include <string>
#include "query_preprocessor/QueryPreprocessor.h"
#include "query_evaluator/QueryEvaluator.h"
#include "pkb/apis/QueryPkb.h"

class QPS {
public:
    QPS(std::shared_ptr<QueryPkbVirtual> pkbInstance): pkb(std::move(pkbInstance)) {};
    std::vector<std::string> evaluate(std::string);
    std::shared_ptr<QueryPkbVirtual> pkb;
};


#endif //SPA_QPS_H
