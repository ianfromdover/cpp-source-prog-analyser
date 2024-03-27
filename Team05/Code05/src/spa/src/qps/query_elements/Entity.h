//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ENTITY_H
#define SPA_ENTITY_H
#include <utility>

#include "Returnable.h"

class Entity : public Returnable {
protected:
    std::string identifier;
public:
    virtual std::string getReturnType() = 0;
    virtual std::string getEntityType() = 0;
    virtual Table getEntityTable(QueryPkbVirtual &pkb) = 0;
    virtual std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual &pkb) = 0;
    std::string getIdentifier() {
        return identifier;
    }
};

#endif //SPA_ENTITY_H
