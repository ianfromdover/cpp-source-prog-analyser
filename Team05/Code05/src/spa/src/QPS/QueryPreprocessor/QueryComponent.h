//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYCOMPONENT_H
#define SPA_QUERYCOMPONENT_H

#include "QueryBuilder.h"
#include <string>
#include "ComponentEnum.h"

class QueryComponent {
public:
    ComponentEnum componentType;
    virtual void acceptBuilder(QueryBuilder *) = 0;
};


#endif //SPA_QUERYCOMPONENT_H
