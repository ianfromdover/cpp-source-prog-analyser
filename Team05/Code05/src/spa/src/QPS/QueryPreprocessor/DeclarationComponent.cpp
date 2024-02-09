//
// Created by Alex on 8/2/2024.
//

#include "DeclarationComponent.h"

void DeclarationComponent::acceptBuilder(QueryBuilder *builderPtr) {
    Declaration d;
    builderPtr->addDeclaration(d);
}

