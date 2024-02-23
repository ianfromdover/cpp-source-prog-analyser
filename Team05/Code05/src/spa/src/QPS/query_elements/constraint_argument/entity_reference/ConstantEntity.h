//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_CONSTANTENTITY_H
#define SPA_CONSTANTENTITY_H

#include "../../Entity.h"
#include "EntityReference.h"

class ConstantEntity : public Entity, public EntityReference  {
public:
    explicit ConstantEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
};


#endif //SPA_CONSTANTENTITY_H
