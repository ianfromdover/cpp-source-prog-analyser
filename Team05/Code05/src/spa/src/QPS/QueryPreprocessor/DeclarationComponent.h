//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_DECLARATIONCOMPONENT_H
#define SPA_DECLARATIONCOMPONENT_H

#include <vector>

#include "QueryComponent.h"

class DeclarationComponent : public QueryComponent{
public:
    void acceptBuilder(std::shared_ptr<QueryBuilder>) override;
    void addDeclaration(std::string entityType, const std::string& synonym);
private:
    std::string entityType;
    std::vector<std::string> synonyms;
};


#endif //SPA_DECLARATIONCOMPONENT_H
