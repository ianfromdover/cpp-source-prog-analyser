//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_DECLARATIONHANDLER_H
#define SPA_DECLARATIONHANDLER_H


#include "ComponentHandler.h"
#include <vector>

class DeclarationHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(DECLARATION);
    void handle(std::string&) override;
private:
    void processEntity(std::string&);
    void processSynonyms(std::string);
    std::string entityType;
    std::vector<std::string> synonyms;
};


#endif //SPA_DECLARATIONHANDLER_H
