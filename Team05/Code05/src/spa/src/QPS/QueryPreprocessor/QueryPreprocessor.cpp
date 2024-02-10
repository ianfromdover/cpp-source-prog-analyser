//
// Created by Alex on 7/2/2024.
//

#include "QueryPreprocessor.h"
#include "HandlerChain.h"

std::shared_ptr<QueryObject> QueryPreprocessor::processQuery(std::string & queryStr) {
    HandlerChain handler;
    std::vector<std::shared_ptr<QueryComponent>> components = handler.handle(queryStr);

    std::shared_ptr<QueryBuilder> builder = std::make_shared<QueryBuilder>();
    std::shared_ptr<QueryObject> query;
    for (const std::shared_ptr<QueryComponent>& component : components){
        component->acceptBuilder(builder);
    }

    query = builder->build();

    return query;

}
