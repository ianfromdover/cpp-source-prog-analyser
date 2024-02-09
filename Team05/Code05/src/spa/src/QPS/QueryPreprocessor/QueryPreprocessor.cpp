//
// Created by Alex on 7/2/2024.
//

#include "QueryPreprocessor.h"
#include "HandlerChain.h"

void QueryPreprocessor::processQuery(std::string & queryStr) {
    HandlerChain handler;
    handler.handle(queryStr);

}
