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

#endif //SPA_CONSTRAINTGROUPOPTIMIZER_H
