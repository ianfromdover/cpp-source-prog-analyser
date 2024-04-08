//
// Created by yewme on 6/4/2024.
//

#ifndef SPA_CONSTRAINTGROUPOPTIMIZER_H
#define SPA_CONSTRAINTGROUPOPTIMIZER_H

#include "../QueryOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/RelationshipConstraint.h"

class ConstraintGroupOptimizer : public QueryOptimizer {
private:
    // Custom hash function for vectors of strings
    struct VectorHash {
        std::size_t operator()(const std::vector<std::string>& vec) const {
            std::size_t hash = 0;
            for (const auto& str : vec) {
                hash ^= std::hash<std::string>()(str) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    // Custom comparator for vectors of strings
    struct VectorEqual {
        bool operator()(const std::vector<std::string>& lhs, const std::vector<std::string>& rhs) const {
            return lhs == rhs;
        }
    };

    std::vector<std::string> extractSynonyms(const std::shared_ptr<Constraint>& constraint) {
        std::vector<std::string> synonyms;
        auto arguments = constraint->getConstraintArguments();
        for (const auto& arg : arguments) {
            synonyms.push_back(arg->getArgumentValue()[0]);
        }
        return synonyms;
    }

    std::unordered_map<std::vector<std::string>, std::vector<std::shared_ptr<Constraint>>>::iterator
    findMatchingKey(const std::vector<std::string>& synonyms) {
        for (auto iter = synonymMap.begin(); iter != synonymMap.end(); ++iter) {
            const auto& key = iter->first;
            for (const auto& synonym : synonyms) {
                if (std::find(key.begin(), key.end(), synonym) != key.end()) {
                    return iter;
                }
            }
        }
        return synonymMap.end();
    }

    // Define unordered_map using custom hash function and comparator
    std::unordered_map<std::vector<std::string>, std::vector<std::shared_ptr<Constraint>>, VectorHash, VectorEqual> synonymMap;

public:
//    void optimize(QueryObject& queryObject) override {
//        for (const auto& constraint : queryObject.getConstraints()) {
//            auto synonyms = extractSynonyms(constraint);
//            auto iter = findMatchingKey(synonyms);
//            if (iter != synonymMap.end()) {
//                // Update existing key
//                auto updatedKey = iter->first;
//                for (const auto& synonym : synonyms) {
//                    if (std::find(updatedKey.begin(), updatedKey.end(), synonym) == updatedKey.end()) {
//                        updatedKey.push_back(synonym);
//                    }
//                }
//
//                // Move the constraints to the new key
//                auto& constraints = synonymMap[updatedKey]; // Get reference to the vector of constraints
//                constraints.insert(constraints.end(), iter->second.begin(), iter->second.end()); // Move constraints
//
//                // Erase the old key
//                synonymMap.erase(iter);
//            } else {
//                // Create new key
//                synonymMap[synonyms].push_back(constraint);
//            }
//        }
//    }

    void optimize(QueryObject& queryObject) override {
        for (const auto& constraint : queryObject.getConstraints()) {
            auto synonyms = extractSynonyms(constraint);
            auto iter = findMatchingKey(synonyms);
            if (iter != synonymMap.end()) {
                // Update existing key
                if (iter != synonymMap.end()) {
                    // Create a new key by appending the new synonyms
                    auto updatedKey = iter->first;
                    updatedKey.insert(updatedKey.end(), synonyms.begin(), synonyms.end());
                    // TODO: replace with the stuff below but it is buggy
//                    for (const auto& synonym : synonyms) {
//                        if (std::find(updatedKey.begin(), updatedKey.end(), synonym) == updatedKey.end()) {
//                            updatedKey.push_back(synonym);
//                        }
//                    }

                    // Move the constraints to the new key
                    synonymMap[updatedKey] = std::move(iter->second);

                    // Erase the old key
                    synonymMap.erase(iter);
                }
            } else {
                // Create new key
                synonymMap[synonyms].push_back(constraint);
            }
        }
    }

    std::unordered_map<std::vector<std::string>, std::vector<std::shared_ptr<Constraint>>, VectorHash, VectorEqual> getSynonymMap() {
        return synonymMap;
    }
};

#endif //SPA_CONSTRAINTGROUPOPTIMIZER_H
