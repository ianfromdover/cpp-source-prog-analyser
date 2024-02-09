//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_DECLARATIONCOMPONENT_H
#define SPA_DECLARATIONCOMPONENT_H

#include <vector>

#include "QueryComponent.h"
#include "../query_elements/Declaration.h"

class DeclarationComponent : public QueryComponent{
public:
    void acceptBuilder(QueryBuilder *) override;
    void addDeclaration(Declaration&);
private:
    std::vector<Declaration> declarations;
};


#endif //SPA_DECLARATIONCOMPONENT_H
