//
// Created by yewme on 26/3/2024.
//

#ifndef SPA_DUPLICATEREMOVALOPTIMIZER_H
#define SPA_DUPLICATEREMOVALOPTIMIZER_H

#include "../QueryOptimizer.h"
#include "qps/query_elements/constraint/RelationshipConstraint.h"

class DuplicateRemovalOptimizer : public QueryOptimizer {
public:
    void optimize(QueryObject& queryObject) override {
        std::unordered_set<std::size_t> hashSet; // Store hash values

        // Temporary vector to store unique constraints
        std::vector<std::shared_ptr<Constraint>> uniqueConstraints;

        std::vector<std::shared_ptr<Constraint>> constraints = queryObject.getConstraints();

        for (const auto& constraint : constraints) {
            std::size_t hashValue = constraint->hash(); // Calculate hash value

            // Check if the hash value already exists
            if (hashSet.find(hashValue) == hashSet.end()) {
                // Hash value doesn't exist, add it to the set
                hashSet.insert(hashValue);
                // Add the constraint to the unique vector
                uniqueConstraints.push_back(constraint);
            } else {
                // Hash value already exists, skip adding the constraint
                // (effectively removing the duplicate)
            }
        }

        // Remove all constraints from the queryObject
        queryObject.removeConstraints();

        // Replace the original vector with the unique vector
        for (const auto& constraint : uniqueConstraints) {
            queryObject.addConstraint(constraint);
        }
    }

};

#endif //SPA_DUPLICATEREMOVALOPTIMIZER_H
