//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_FOLLOWSCONSTRAINT_H
#define SPA_FOLLOWSCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "StatementReference.h"

class FollowsConstraint : public RelationshipConstraint{
private:
    std::vector<ConstraintArgument> constraintArguments;
public:
    FollowsConstraint(class StatementReference&, class StatementReference&);
    std::string getConstraintType() override;
    std::vector<ConstraintArgument> getConstraintArguments() override;
};


#endif //SPA_FOLLOWSCONSTRAINT_H
