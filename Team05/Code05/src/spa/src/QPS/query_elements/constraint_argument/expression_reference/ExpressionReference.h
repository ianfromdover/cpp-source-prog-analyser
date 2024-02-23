//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_EXPRESSIONREFERENCE_H
#define SPA_EXPRESSIONREFERENCE_H

#include "../ConstraintArgument.h"
#include "utilSpa/SpaTypes.h"

class ExpressionReference : public ConstraintArgument  {
public:
    std::string getReferenceType() override;
};


#endif //SPA_EXPRESSIONREFERENCE_H
