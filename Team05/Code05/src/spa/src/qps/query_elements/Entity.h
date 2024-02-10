//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ENTITY_H
#define SPA_ENTITY_H
#include <utility>

#include "Returnable.h"

class Entity : public Returnable {
private:
    std::string identifier;
public:
    virtual std::string getReturnType() = 0;
    virtual std::string getEntityType() = 0;
    void setIdentifier(std::string s) {
        identifier = std::move(s);
    }
    std::string getIdentifier() {
        return identifier;
    }
};

#endif //SPA_ENTITY_H
