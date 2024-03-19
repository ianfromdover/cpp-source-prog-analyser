//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_PRINTENTITY_H
#define SPA_PRINTENTITY_H


#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class PrintEntity : public StatementReference, public Entity {
public:
    explicit PrintEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_PRINTENTITY_H
