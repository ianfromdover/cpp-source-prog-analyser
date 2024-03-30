//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ASSIGNENTITY_H
#define SPA_ASSIGNENTITY_H

#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class AssignEntity : public StatementReference, public Entity {
public:
    explicit AssignEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_ASSIGNENTITY_H
