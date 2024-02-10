//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINT_H
#define SPA_RELATIONSHIPCONSTRAINT_H

#include "Constraint.h"

class RelationshipConstraint : public Constraint {
public:
    std::string getConstraintClass() override;

};


#endif //SPA_RELATIONSHIPCONSTRAINT_H
