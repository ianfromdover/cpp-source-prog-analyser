//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_STATEMENTREFWILDCARD_H
#define SPA_STATEMENTREFWILDCARD_H

#include "StatementReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class StatementRefWildcard : public StatementReference {
public:
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual & pkb) override;

};



#endif //SPA_STATEMENTREFWILDCARD_H
