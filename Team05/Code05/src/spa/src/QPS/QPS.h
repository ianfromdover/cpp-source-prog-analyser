//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QPS_H
#define SPA_QPS_H

#include <vector>
#include <string>
#include "QueryPreprocessor/QueryPreprocessor.h"
#include "QueryEvaluator/QueryEvaluator.h"

class QPS {
public:
    std::vector<std::string> evaluate(std::string);
};


#endif //SPA_QPS_H
