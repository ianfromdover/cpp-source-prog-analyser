//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_EXPRESSIONREFERENCE_H
#define SPA_EXPRESSIONREFERENCE_H

#include "../ConstraintArgument.h"
#include "common/SpaTypes.h"
#include "pkb/apis/QueryPKBVirtual.h"

class ExpressionReference : public ConstraintArgument  {
public:
    std::string getReferenceType() override;
    std::vector<std::vector<std::string>> getRawTable(QueryPKBVirtual & pkb) override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
};


#endif //SPA_EXPRESSIONREFERENCE_H
