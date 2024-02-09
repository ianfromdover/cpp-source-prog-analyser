//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_DECLARATIONHANDLER_H
#define SPA_DECLARATIONHANDLER_H


#include "ComponentHandler.h"
#include "DeclarationComponent.h"
#include <vector>

class DeclarationHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(DECLARATION);
    std::shared_ptr<QueryComponent> handle(std::string&) override;
private:
    void parseDeclaration(std::string &s);
    std::shared_ptr<DeclarationComponent> createComponent();
    std::string entityType;
    std::vector<std::string> synonyms;
};


#endif //SPA_DECLARATIONHANDLER_H
