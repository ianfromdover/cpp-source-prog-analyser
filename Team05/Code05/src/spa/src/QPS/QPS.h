//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QPS_H
#define SPA_QPS_H

#include <vector>
#include <string>
#include "QueryPreprocessor/QueryPreprocessor.h"
#include "QueryEvaluator/QueryEvaluator.h"
#include "qps/QueryEvaluator/PKBStub.h"

class QPS {
public:
    QPS(PKBStub& stub){
        pkb = stub;
    }
    std::vector<std::string> evaluate(std::string);
    PKBStub pkb;
};


#endif //SPA_QPS_H
