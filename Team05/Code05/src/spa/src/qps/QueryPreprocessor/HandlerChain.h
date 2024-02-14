//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_HANDLERCHAIN_H
#define SPA_HANDLERCHAIN_H


#include "ComponentHandler.h"
#include "DeclarationHandler.h"
#include "SelectHandler.h"
#include "RelationshipConstraintHandler.h"

class HandlerChain {
private:

    std::shared_ptr<ComponentHandler> handlerChain;
public:
    HandlerChain() {
        std::shared_ptr<ComponentHandler> declarationHandler = std::make_shared<DeclarationHandler>();
        std::shared_ptr<ComponentHandler> selectHandler = std::make_shared<SelectHandler>();
        std::shared_ptr<ComponentHandler> relationshipHandler = std::make_shared<RelationshipConstraintHandler>();

        handlerChain = declarationHandler;
        declarationHandler->addNextHandler(selectHandler);
        selectHandler->addNextHandler(relationshipHandler);
    }
    std::vector<std::shared_ptr<QueryComponent>> handle(std::string);
private:
    std::vector<std::string> tryConvert(std::string str);
};


#endif //SPA_HANDLERCHAIN_H
