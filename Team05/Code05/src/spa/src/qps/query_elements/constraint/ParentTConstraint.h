//
// Created by tohzh on 10/2/2024.
//

#ifndef SPA_PARENTTCONSTRAINT_H
#define SPA_PARENTTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/StatementReference.h"

class ParentTConstraint :public RelationshipConstraint {
private:
    std::vector<ConstraintArgument*> constraintArguments;
public:
    ParentTConstraint(class StatementReference*, class StatementReference*);
    std::string getConstraintType() override;
    std::vector<ConstraintArgument*> getConstraintArguments() override;
};


#endif //SPA_PARENTTCONSTRAINT_H
