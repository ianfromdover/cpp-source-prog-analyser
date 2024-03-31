//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_TUPLE_H
#define SPA_TUPLE_H


#include "Returnable.h"
#include "Entity.h"

class Tuple : public Returnable {
public:
    std::vector<std::shared_ptr<Entity>> entityVector;
    void addEntityVector(std::shared_ptr<Entity>);
    std::string getReturnType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual &pkb) override;
};


#endif //SPA_TUPLE_H
