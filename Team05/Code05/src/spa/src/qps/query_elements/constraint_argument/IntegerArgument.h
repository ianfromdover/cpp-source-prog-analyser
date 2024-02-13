//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_INTEGERARGUMENT_H
#define SPA_INTEGERARGUMENT_H

#include "StatementReference.h"

class IntegerArgument : public StatementReference {
public:
    explicit IntegerArgument(int a) : value(a) {};
    IntegerArgument() = default;
    std::string getEntityType() override;
    std::string getArgumentValue() override;
    int value;
};


#endif //SPA_INTEGERARGUMENT_H
