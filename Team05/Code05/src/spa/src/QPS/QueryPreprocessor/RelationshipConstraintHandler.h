//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTHANDLER_H
#define SPA_RELATIONSHIPCONSTRAINTHANDLER_H


#include "ComponentHandler.h"

class RelationshipConstraintHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(RELATIONSHIP_CONSTRAINT);
    void handle(std::string&);


};


#endif //SPA_RELATIONSHIPCONSTRAINTHANDLER_H
