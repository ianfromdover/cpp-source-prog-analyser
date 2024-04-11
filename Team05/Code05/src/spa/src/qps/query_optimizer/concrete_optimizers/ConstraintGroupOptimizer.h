//
// Created by yewme on 6/4/2024.
//

#ifndef SPA_CONSTRAINTGROUPOPTIMIZER_H
#define SPA_CONSTRAINTGROUPOPTIMIZER_H

#include "../QueryOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/RelationshipConstraint.h"

class ConstraintGroupOptimizer : public QueryOptimizer {
private:

    std::unordered_map<std::string, int> synonymMap;
    std::vector<std::vector<std::shared_ptr<Constraint>>> constraintGroups;

    std::vector<std::string> extractSynonyms(const std::shared_ptr<Constraint>& constraint) {
        std::vector<std::string> synonyms;
        auto arguments = constraint->getConstraintArguments();
        for (const auto& arg : arguments) {
            synonyms.push_back(arg->getArgumentValue()[0]);
        }
        return synonyms;
    }

    bool synonymFound(std::vector<std::string> synonyms) {
        bool result = false;
        for (auto syn : synonyms) {
            if (synonymMap.find(syn) != synonymMap.end()) {
                result = true;
            }
        }
        return result;
    }

public:

    void optimize(QueryObject& queryObject) override {
        int index = 0;
        for (const auto& constraint : queryObject.getConstraints()) {
            // Extract synonyms from the constraint
            std::vector<std::string> synonyms = extractSynonyms(constraint);

            if (synonymFound(synonyms)) {
                for (const auto& syn : synonyms) {
                    synonymMap.insert({syn, synonymMap[syn]});
                }
                // Resize constraintGroups if necessary
                if (synonymMap[synonyms[0]] >= constraintGroups.size()) {
                    constraintGroups.resize(synonymMap[synonyms[0]] + 1);
                }
                constraintGroups[synonymMap[synonyms[0]]].push_back(constraint);
            } else {
                for (const auto& syn : synonyms) {
                    synonymMap.insert({syn, index});
                }
                // Resize constraintGroups if necessary
                if (index >= constraintGroups.size()) {
                    constraintGroups.resize(index + 1);
                }
                constraintGroups[index].push_back(constraint);
                index++;
            }
        }


        queryObject.removeConstraints();

        for (auto groups : constraintGroups) {
            for (auto constraint : groups) {
                queryObject.addConstraint(constraint);
            }
        }
    }

    std::unordered_map<std::string, int> getSynonymMap() {
        return synonymMap;
    }

    std::vector<std::vector<std::shared_ptr<Constraint>>> getConstraintGroups() {
        return constraintGroups;
    }

};

// TODO: create group clause function which will be able to group the clauses
// create a vec<vec<constraints>>, each time there is no match of the synonym
// keep a hashset of <index, synonyms> then if the synonyms is present in the
// oh no need, just keep the hashset of stuff so that each entry just points to one index, then the index will be the index of the constraint vector
// eg Follows(s1, s2) then key-value pair will be <s1, 0> and <s2, 0> then if Parent<s2, s3> then it will be grouped in the same index as the first one (index 0)
// if new synonym found, increase the index field by one then assign the synonyms to the new index

#endif //SPA_CONSTRAINTGROUPOPTIMIZER_H
