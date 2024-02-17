//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTHANDLER_H
#define SPA_RELATIONSHIPCONSTRAINTHANDLER_H


#include "ComponentHandler.h"
#include "RelationshipConstraintComponent.h"


class RelationshipConstraintHandler : public ComponentHandler{
public:
    RelationshipConstraintHandler() {
        component = std::make_shared<RelationshipConstraintComponent>();
        componentType = ComponentEnum(RELATIONSHIP_CONSTRAINT);
    }
    ComponentEnum componentType;
    std::shared_ptr<QueryComponent> handle(std::string&);
private:
    std::string relationshipConstraint;
    std::vector<std::string> arguments;
    std::shared_ptr<RelationshipConstraintComponent> component;

};


#endif //SPA_RELATIONSHIPCONSTRAINTHANDLER_H
