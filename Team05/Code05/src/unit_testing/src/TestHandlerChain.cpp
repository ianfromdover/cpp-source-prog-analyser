//
// Created by Alex on 9/2/2024.
//


#include "catch.hpp"
#include "QPS/QueryPreprocessor/HandlerChain.h"

using namespace std;


TEST_CASE("Valid PQL Syntax") {

    HandlerChain handlerChain;
    handlerChain.handle("stmt a,b;Select a such that Parent (w, a)");
    handlerChain.handle("stmt a,b;Select a such that Parent* (w,a)");
}
