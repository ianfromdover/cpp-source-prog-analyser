//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_STATEMENTENTITY_H
#define SPA_STATEMENTENTITY_H

#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class StatementEntity : public StatementReference, public  Entity {
public:
    explicit StatementEntity(std::string);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string getArgumentValue() override;
    std::string toString() override;
    std::string value;
//    std::pair<Column<std::string>, Column<std::string>> getPkbTable() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual & pkb) override;
};

#endif //SPA_STATEMENTENTITY_H
