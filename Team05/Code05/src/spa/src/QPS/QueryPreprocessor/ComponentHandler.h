//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_COMPONENTHANDLER_H
#define SPA_COMPONENTHANDLER_H

#include "QueryComponent.h"
#include <string>
#include <iostream>
#include "ComponentEnum.h"
#include <stdexcept>

class ComponentHandler {

protected:
    std::shared_ptr<ComponentHandler> nextHandler;
public:
    ComponentHandler() : nextHandler(nullptr) {};
    ComponentEnum componentType;
    virtual void handle(std::string&) = 0;
    void addNextHandler(std::shared_ptr<ComponentHandler> handler) {
        nextHandler = handler;
    };
};

#endif //SPA_COMPONENTHANDLER_H
