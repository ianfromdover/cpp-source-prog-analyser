//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_PROCEDUREENTITY_H
#define SPA_PROCEDUREENTITY_H

#include "../../Entity.h"
#include "EntityReference.h"
#include "pkb/apis/QueryPkbVirtual.h"


class ProcedureEntity : public Entity, public EntityReference  {
public:
    explicit ProcedureEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_PROCEDUREENTITY_H
