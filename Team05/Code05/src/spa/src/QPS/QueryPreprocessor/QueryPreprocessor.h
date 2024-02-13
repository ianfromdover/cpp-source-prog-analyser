//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYPREPROCESSOR_H
#define SPA_QUERYPREPROCESSOR_H

#include <string>
#include "qps/query_elements/QueryObject.h"

class QueryPreprocessor {
public:
    QueryPreprocessor() = default;
    std::shared_ptr<QueryObject> processQuery(std::string&);
};


#endif //SPA_QUERYPREPROCESSOR_H
