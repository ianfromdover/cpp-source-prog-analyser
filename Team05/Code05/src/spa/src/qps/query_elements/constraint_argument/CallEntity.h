//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_CALLENTITY_H
#define SPA_CALLENTITY_H


#include "StatementReference.h"

class CallEntity : public StatementReference, public Entity {
public:
    explicit CallEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
};


#endif //SPA_CALLENTITY_H
