//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_INTEGERARGUMENT_H
#define SPA_INTEGERARGUMENT_H

#include "StatementReference.h"
#include "pkb/apis/QueryPKBVirtual.h"

class IntegerArgument : public StatementReference {
public:
    explicit IntegerArgument(int a) : value(a) {};
    IntegerArgument() = default;
    std::string getEntityType() override;
    std::string getArgumentValue() override;
    int value;
    std::string toString() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
};


#endif //SPA_INTEGERARGUMENT_H
