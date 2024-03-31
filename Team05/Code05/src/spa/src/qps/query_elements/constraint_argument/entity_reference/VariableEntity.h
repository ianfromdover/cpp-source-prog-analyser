//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_VARIABLEENTITY_H
#define SPA_VARIABLEENTITY_H

#include "../../Entity.h"
#include "EntityReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class VariableEntity : public Entity, public EntityReference {
public:
    explicit VariableEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_VARIABLEENTITY_H
