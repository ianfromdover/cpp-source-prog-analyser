//
// Created by Alex on 10/2/2024.
//

#include "RelationshipConstraintComponent.h"

#include <utility>

void RelationshipConstraintComponent::setRelationshipType(std::string string) {
    this->relationshipType=std::move(string);
}

void RelationshipConstraintComponent::addArgument(const std::string& string) {
    this->arguments.push_back(string);

}

void RelationshipConstraintComponent::acceptBuilder(QueryBuilder *) {

}
