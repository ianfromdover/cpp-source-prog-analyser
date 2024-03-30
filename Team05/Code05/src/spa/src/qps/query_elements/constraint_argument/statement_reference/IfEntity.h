//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_IFENTITY_H
#define SPA_IFENTITY_H


#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class IfEntity : public StatementReference, public  Entity {
public:
    explicit IfEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    Table getEntityTable(QueryPkbVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPkbVirtual & pkb) override;
};



#endif //SPA_IFENTITY_H
