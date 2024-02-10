//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_SELECTHANDLER_H
#define SPA_SELECTHANDLER_H


#include "ComponentHandler.h"
#include "SelectComponent.h"

class SelectHandler : public ComponentHandler{
public:
    SelectHandler() {
        component = std::make_shared<SelectComponent>();
    }
    ComponentEnum componentType = ComponentEnum(SELECT);
    std::shared_ptr<QueryComponent> handle(std::string&) override;
private:
    std::shared_ptr<SelectComponent> component;
};


#endif //SPA_SELECTHANDLER_H
