//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_SELECTHANDLER_H
#define SPA_SELECTHANDLER_H


#include "ComponentHandler.h"

class SelectHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(SELECT);
    std::shared_ptr<QueryComponent> handle(std::string&) override;
};


#endif //SPA_SELECTHANDLER_H
