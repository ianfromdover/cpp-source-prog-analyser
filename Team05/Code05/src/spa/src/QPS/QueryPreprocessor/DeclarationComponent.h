//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_DECLARATIONCOMPONENT_H
#define SPA_DECLARATIONCOMPONENT_H

#include <unordered_set>

#include "QueryComponent.h"

class DeclarationComponent : public QueryComponent{
public:
    void acceptBuilder(QueryBuilder *) override;
private:
    std::unordered_set<Declaration> declarations;
};


#endif //SPA_DECLARATIONCOMPONENT_H
