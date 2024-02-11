//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_FOLLOWSTCONSTRAINT_H
#define SPA_FOLLOWSTCONSTRAINT_H


#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/StatementReference.h"

class FollowsTConstraint : public RelationshipConstraint{
private:
    std::vector<ConstraintArgument*> constraintArguments;
public:
    FollowsTConstraint(class StatementReference*, class StatementReference*);
    std::string getConstraintType() override;
    std::vector<ConstraintArgument*> getConstraintArguments() override;
};



#endif //SPA_FOLLOWSTCONSTRAINT_H
