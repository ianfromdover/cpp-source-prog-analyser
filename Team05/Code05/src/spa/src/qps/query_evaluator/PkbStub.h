//
// Created by Alex on 11/2/2024.
//

#pragma once
#define SPA_PKBSTUB_H

#include <memory>
#include <utility>
#include "qps/query_elements/Returnable.h"
#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_evaluator/query_result/StringResult.h"
#include "qps/query_evaluator/query_result/QueryResult.h"


// ai-gen start(gpt, 0, e)
// prompt: https://platform.openai.com/playground/p/ErjJuev6dMUJWh9xtwKTTNXx?model=gpt-4&mode=chat
class PkbStub {
private:
    std::shared_ptr<QueryResult> result;
public:
    PkbStub() = default;
    PkbStub(std::vector<std::string>& stringList)
            : result(std::make_shared<StringResult>(stringList)) {}

    std::shared_ptr<QueryResult> getResult(Returnable& r, Constraint& c){
        return result;
    }
};
// ai-gen end
