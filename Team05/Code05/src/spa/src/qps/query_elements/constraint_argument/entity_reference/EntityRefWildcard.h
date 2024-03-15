//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_ENTITYREFWILDCARD_H
#define SPA_ENTITYREFWILDCARD_H

#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "EntityReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class EntityRefWildcard : public EntityReference {
public:
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_ENTITYREFWILDCARD_H
