//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTHANDLER_H
#define SPA_RELATIONSHIPCONSTRAINTHANDLER_H


#include "ComponentHandler.h"
#include "../query_elements/constraint/RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"

class RelationshipConstraintHandler : public ComponentHandler{
public:
    ComponentEnum componentType = ComponentEnum(RELATIONSHIP_CONSTRAINT);
    std::shared_ptr<QueryComponent> handle(std::string&);
private:
    std::string relationshipConstraint;
    std::vector<std::string> arguments;

};


#endif //SPA_RELATIONSHIPCONSTRAINTHANDLER_H
