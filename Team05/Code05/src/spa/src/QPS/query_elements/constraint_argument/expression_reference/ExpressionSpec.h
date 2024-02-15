//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_EXPRESSIONSPEC_H
#define SPA_EXPRESSIONSPEC_H


#include "ExpressionReference.h"

class ExpressionSpec : public ExpressionReference {
protected:
    std::string regularExpression;
public:
    explicit ExpressionSpec(std::string);
    std::string getEntityType() override;
    std::string getArgumentValue() override;
};


#endif //SPA_EXPRESSIONSPEC_H
