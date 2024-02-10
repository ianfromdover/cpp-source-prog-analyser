//
// Created by Alex on 8/2/2024.
//

#include "DeclarationComponent.h"

#include <utility>
#include <stdexcept>

void DeclarationComponent::acceptBuilder(QueryBuilder *builderPtr) {
}

void DeclarationComponent::addDeclaration(std::string type, const std::string& syn) {
    if (entityType.empty() || entityType == type){
        if (entityType.empty())
            entityType = std::move(type);
        synonyms.push_back(syn);
    } else {
        throw std::runtime_error("wrong type!");
    }
}
