//
// Created by tohzh on 20/3/2024.
//

#ifndef SPA_WITHREFERENCE_H
#define SPA_WITHREFERENCE_H

#include "qps/query_elements/constraint_argument/ConstraintArgument.h"
#include "common/SpaTypes.h"
#include "qps/query_elements/QueryObject.h"

class WithReference : public ConstraintArgument {
public:
    std::string getReferenceType() override;
    virtual void setVariable(std::shared_ptr<QueryObject>) = 0;
};


#endif //SPA_WITHREFERENCE_H
