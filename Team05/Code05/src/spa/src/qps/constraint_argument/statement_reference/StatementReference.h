//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_STATEMENTREFERENCE_H
#define SPA_STATEMENTREFERENCE_H

#include "qps/query_elements/constraint_argument/ConstraintArgument.h"
#include "qps/query_elements/Entity.h"
#include "utilSpa/SpaTypes.h"

class StatementReference : public ConstraintArgument {
public:
    std::string getReferenceType() override;
};

#endif //SPA_STATEMENTREFERENCE_H
