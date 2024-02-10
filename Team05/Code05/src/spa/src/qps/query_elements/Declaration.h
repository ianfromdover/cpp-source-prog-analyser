//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_DECLARATION_H
#define SPA_DECLARATION_H
#include "Entity.h"

class Declaration {
private:
    Entity* declarationEntity;

public:
    explicit Declaration(Entity* e) {
        declarationEntity = e;
    }
    Entity* getDeclarationEntity() {
        return declarationEntity;
    }
};


#endif //SPA_DECLARATION_H
