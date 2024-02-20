//
// Created by tohzh on 20/2/2024.
//

#ifndef SPA_EXPRESSIONWITHWILDCARD_H
#define SPA_EXPRESSIONWITHWILDCARD_H

#include "ExpressionReference.h"

class ExpressionWithWildcard : public ExpressionReference {
protected:
    std::string regularExpression;
public:
    explicit ExpressionWithWildcard(std::string);
    std::string getEntityType() override;
    std::string getArgumentValue() override;
    std::string toString() override;
};


#endif //SPA_EXPRESSIONWITHWILDCARD_H
