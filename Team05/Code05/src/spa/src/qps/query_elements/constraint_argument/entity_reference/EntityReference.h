//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_ENTITYREFERENCE_H
#define SPA_ENTITYREFERENCE_H

#include "../ConstraintArgument.h"
#include "qps/query_elements/Entity.h"
#include "common/SpaTypes.h"

class EntityReference : public ConstraintArgument {
public:
    std::string getReferenceType() override;
};


#endif //SPA_ENTITYREFERENCE_H
