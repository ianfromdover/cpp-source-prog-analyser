//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_STATEMENTENTITY_H
#define SPA_STATEMENTENTITY_H

#include "StatementReference.h"

class StatementEntity : public StatementReference, public  Entity {
public:
    explicit StatementEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
};

#endif //SPA_STATEMENTENTITY_H
