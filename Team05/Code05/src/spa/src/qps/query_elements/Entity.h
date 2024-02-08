//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ENTITY_H
#define SPA_ENTITY_H
#include "Returnable.h"

class Entity : public Returnable {
public:
    virtual std::string getEntityType() = 0;
};

#endif //SPA_ENTITY_H
