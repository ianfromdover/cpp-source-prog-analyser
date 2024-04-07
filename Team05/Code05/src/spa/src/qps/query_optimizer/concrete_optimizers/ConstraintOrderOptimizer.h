//
// Created by yewme on 29/3/2024.
//

#ifndef SPA_CONSTRAINTORDEROPTIMIZER_H
#define SPA_CONSTRAINTORDEROPTIMIZER_H

#include "../QueryOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/RelationshipConstraint.h"

class ConstraintOrderOptimizer : public QueryOptimizer {
public:
    void optimize(QueryObject& queryObject) override {
        std::vector<std::shared_ptr<Constraint>> constraints = queryObject.getConstraints();
        for (shared_ptr<Constraint> constraint : constraints) {
            assignScore(constraint);
        }
        // Sort constraints based on priority
        std::sort(constraints.begin(), constraints.end(), [](const auto& a, const auto& b) {
            // Sort in descending order of priority
            return a->priority > b->priority;
        });

        queryObject.removeConstraints();

        // Update the queryObject with sorted constraints
        for (shared_ptr<Constraint> constraint : constraints) {
            queryObject.addConstraint(constraint);
        }
    }

    static void assignScore(shared_ptr<Constraint>& constraint) {
        // Assign score based on constraint class
        std::vector<std::string> priorityClasses = {CONSTRAINT_TYPE_FOLLOWS, CONSTRAINT_TYPE_FOLLOWST,
                                                    CONSTRAINT_TYPE_PARENT, CONSTRAINT_TYPE_PARENTT,
                                                    CONSTRAINT_TYPE_USESS, CONSTRAINT_TYPE_USESP,
                                                    CONSTRAINT_TYPE_MODIFIESS, CONSTRAINT_TYPE_MODIFIESP};
        if (std::find(priorityClasses.begin(), priorityClasses.end(), constraint->getConstraintType()) != priorityClasses.end()) {
            constraint->priority += 10;
        }
        // The rest of the constraint classes are not priority, just don't add the score

        // TODO: assign score based on return type, but how to access the return type of the QueryObject?
//        std::vector<std::string> priorityReturnables = {};
//        if (std::find(priorityReturnables.begin(), priorityReturnables.end(), "test") != priorityReturnables.end()) {
//            constraint->priority += 10;
//        }

        // Assign score based on arguments
        std::vector<std::string> priorityTypes = {TYPE_INTEGER, TYPE_CONSTANT, TYPE_EXPRESSION, TYPE_PROCEDURE};
        auto arguments = constraint->getConstraintArguments();
        for (const auto& argument : arguments) {
            if (std::find(priorityTypes.begin(), priorityTypes.end(), argument->getEntityType()) != priorityTypes.end()) {
                constraint->priority += 1;
            }
        }
    }

};

#endif //SPA_CONSTRAINTORDEROPTIMIZER_H
