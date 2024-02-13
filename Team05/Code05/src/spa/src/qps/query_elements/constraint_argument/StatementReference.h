//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_STATEMENTREFERENCE_H
#define SPA_STATEMENTREFERENCE_H

#include "ConstraintArgument.h"
#include "../Entity.h"
#include "utilSpa/SpaTypes.h"

class StatementReference : public ConstraintArgument {
public:
    std::string getReferenceType() override;
    std::string getArgumentValue() override;
};

#endif //SPA_STATEMENTREFERENCE_H
