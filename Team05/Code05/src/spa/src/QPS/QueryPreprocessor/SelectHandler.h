//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_SELECTHANDLER_H
#define SPA_SELECTHANDLER_H


#include "ComponentHandler.h"

class SelectHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(SELECT);
    void handle(std::string&);

};


#endif //SPA_SELECTHANDLER_H
