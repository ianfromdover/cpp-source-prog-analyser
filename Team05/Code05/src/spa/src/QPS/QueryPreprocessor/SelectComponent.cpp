//
// Created by Alex on 10/2/2024.
//

#include "SelectComponent.h"

void SelectComponent::acceptBuilder(QueryBuilder *) {

}

void SelectComponent::setSynonym(std::string string) {
    this->selectedSyn=string;
}
