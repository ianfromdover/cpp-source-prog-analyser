//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINT_H
#define SPA_RELATIONSHIPCONSTRAINT_H

#include "qps/query_elements/constraint/Constraint.h"
#include "common/Column.h"

class RelationshipConstraint : public Constraint {
public:
    std::string getConstraintClass() override;
    Table getRelationshipTable(QueryPkbVirtual &) override;
};


#endif //SPA_RELATIONSHIPCONSTRAINT_H
