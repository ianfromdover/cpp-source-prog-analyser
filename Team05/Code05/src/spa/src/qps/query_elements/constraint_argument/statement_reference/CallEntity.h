//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_CALLENTITY_H
#define SPA_CALLENTITY_H


#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class CallEntity : public StatementReference, public Entity {
public:
    explicit CallEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_CALLENTITY_H
