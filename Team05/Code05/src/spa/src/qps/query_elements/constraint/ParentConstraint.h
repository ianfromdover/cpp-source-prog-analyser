//
// Created by tohzh on 10/2/2024.
//

#ifndef SPA_PARENTCONSTRAINT_H
#define SPA_PARENTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/StatementReference.h"

class ParentConstraint : public RelationshipConstraint {
private:
    std::vector<ConstraintArgument*> constraintArguments;
public:
    ParentConstraint(class StatementReference*, class StatementReference*);
    std::string getConstraintType() override;
    std::vector<ConstraintArgument*> getConstraintArguments() override;
};


#endif //SPA_PARENTCONSTRAINT_H
