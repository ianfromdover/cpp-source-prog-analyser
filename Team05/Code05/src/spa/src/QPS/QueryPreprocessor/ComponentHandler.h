//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_COMPONENTHANDLER_H
#define SPA_COMPONENTHANDLER_H

#include "QueryComponent.h"
#include <string>
#include "ComponentEnum.h"

class ComponentHandler {
    public:
    ComponentEnum componentType;
    QueryComponent handle(std::string);
    void addNextHandler(ComponentHandler);
};

#endif //SPA_COMPONENTHANDLER_H
