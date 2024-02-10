//
// Created by Alex on 8/2/2024.
//

#include <memory>
#include <regex>
#include "RelationshipConstraintHandler.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "RelationshipConstraintComponent.h"

std::shared_ptr<QueryComponent> RelationshipConstraintHandler::handle(std::string& str) {
    std::cout << "Relationship handler: " << str << std::endl;

    std::regex regexPattern(R"(^\s*such\s+that\s+(Parent|Parent\*)\s*\(\s*([a-zA-Z][a-zA-Z0-9]*)\s*?,\s*([a-zA-Z][a-zA-Z0-9]*)\s*\)$)");

    std::sregex_iterator iterator(str.begin(), str.end(), regexPattern);
    std::sregex_iterator end;
    std::smatch matches;
    if (std::regex_search(str, matches, regexPattern)) {
        std::cout << "Handled by RelationshipConstraint Handler: " << str << std::endl;
        if (matches[1].matched && matches[2].matched && matches[3].matched) {
            relationshipConstraint = matches[1];
            arguments.push_back(matches[2]);
            arguments.push_back(matches[3]);

            std::shared_ptr<RelationshipConstraintComponent> component(new RelationshipConstraintComponent);
            component->setRelationshipType(matches[1]);
            component->addArgument(matches[2]);
            component->addArgument(matches[3]);

            return component;
        }
        else throw std::runtime_error("BUG::RelationshipConstraintHandler matching regex but not matching required groups");
    } else {
        if (nextHandler) return nextHandler->handle(str);
        else throw std::runtime_error("no handlers able to process" + str);
    }
}


