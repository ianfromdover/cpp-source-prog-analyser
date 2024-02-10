//
// Created by Alex on 10/2/2024.
//

#include "SelectComponent.h"


void SelectComponent::setSynonym(std::string string) {
    this->selectedSyn=string;
}

void SelectComponent::acceptBuilder(std::shared_ptr<QueryBuilder> builder) {
    builder->addReturnType(selectedSyn);
}
