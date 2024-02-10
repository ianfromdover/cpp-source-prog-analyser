//
// Created by Alex on 10/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINTCOMPONENT_H
#define SPA_RELATIONSHIPCONSTRAINTCOMPONENT_H


#include "QueryComponent.h"

class RelationshipConstraintComponent : public QueryComponent{
public:
    void acceptBuilder(QueryBuilder *) override;
    void setRelationshipType(std::string string);
    void addArgument(const std::string& string);
private:
    std::string relationshipType;
    std::vector<std::string> arguments;

};


#endif //SPA_RELATIONSHIPCONSTRAINTCOMPONENT_H
