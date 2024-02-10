//
// Created by Alex on 7/2/2024.
//

#include "QueryEvaluator.h"
#include "qps/QueryEvaluator/QueryResult/StringResult.h"

std::shared_ptr<Formattable> QueryEvaluator::evaluate(QueryObject &) {
    //stub
    std::string s1 = "myVar1";
    std::string s2 = "myVar2";
    std::string s3 = "myVar3";
    std::vector<std::string> ls = {s1,s2,s3};
    StringResult res(ls);
    // end stub
    return std::make_shared<StringResult>(res);
}
