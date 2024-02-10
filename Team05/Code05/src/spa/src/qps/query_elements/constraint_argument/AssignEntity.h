//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ASSIGNENTITY_H
#define SPA_ASSIGNENTITY_H

#include "StatementReference.h"

class AssignEntity : public StatementReference, Entity {
public:
    std::string getReturnType() override;
    std::string getEntityType() override;
};


#endif //SPA_ASSIGNENTITY_H
