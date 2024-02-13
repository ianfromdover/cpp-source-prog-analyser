//
// Created by Alex on 11/2/2024.
//

#ifndef SPA_PKBSTUB_H
#define SPA_PKBSTUB_H

#include <memory>
#include <utility>
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "qps/query_elements/Returnable.h"
#include "qps/query_elements/constraint/Constraint.h"
#include "qps/QueryEvaluator/QueryResult/StringResult.h"


// ai-gen start(gpt, 0, e)
// prompt: https://platform.openai.com/playground/p/ErjJuev6dMUJWh9xtwKTTNXx?model=gpt-4&mode=chat
class PKBStub {
private:
    std::shared_ptr<QueryResult> result;
public:
    PKBStub() = default;
    PKBStub(std::vector<std::string>& stringList)
            : result(std::make_shared<StringResult>(stringList)) {}

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c){
        return result;
    }
};
// ai-gen end

#endif //SPA_PKBSTUB_H
