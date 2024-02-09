//
// Created by Alex on 9/2/2024.
//


#include "catch.hpp"
#include "QPS/QueryPreprocessor/HandlerChain.h"

using namespace std;


TEST_CASE("2st Test") {

    HandlerChain handlerChain;
    handlerChain.handle("variable v,t,y,u,i,i;");
    REQUIRE(1 == 1);
}
