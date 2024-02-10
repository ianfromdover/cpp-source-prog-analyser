//
// Created by Alex on 8/2/2024.
//

#include "DeclarationComponent.h"

#include <utility>
#include <stdexcept>

void DeclarationComponent::addDeclaration(std::string type, const std::string& syn) {
    if (entityType.empty() || entityType == type){
        if (entityType.empty())
            entityType = std::move(type);
        synonyms.push_back(syn);
    } else {
        throw std::runtime_error("wrong type!");
    }
}

void DeclarationComponent::acceptBuilder(std::shared_ptr<QueryBuilder> builder) {
    for (const std::string& s : synonyms){
        builder->addDeclaration(entityType, s);
    }
}
