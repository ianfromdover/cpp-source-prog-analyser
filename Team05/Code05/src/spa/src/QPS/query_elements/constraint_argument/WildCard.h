//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_WILDCARD_H
#define SPA_WILDCARD_H

#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "entity_reference/EntityReference.h"

class WildCard : public ConstraintArgument {
public:
    std::string getEntityType() override;
    std::string getReferenceType() override;
    std::string getArgumentValue() override;
};


#endif //SPA_WILDCARD_H
