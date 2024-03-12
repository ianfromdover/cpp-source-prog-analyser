//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_READENTITY_H
#define SPA_READENTITY_H


#include "StatementReference.h"
#include "pkb/apis/QueryPKBVirtual.h"

class ReadEntity : public StatementReference, public  Entity {
public:
    explicit ReadEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
};


#endif //SPA_READENTITY_H
