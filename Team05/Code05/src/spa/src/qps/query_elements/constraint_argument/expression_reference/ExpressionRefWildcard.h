//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_EXPRESSIONREFWILDCARD_H
#define SPA_EXPRESSIONREFWILDCARD_H

#include "ExpressionReference.h"

class ExpressionRefWildcard : public ExpressionReference {
public:
    std::string getEntityType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;
};


#endif //SPA_EXPRESSIONREFWILDCARD_H
