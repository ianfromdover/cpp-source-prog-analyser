//
// Created by tohzh on 10/2/2024.
//

#include "NoDeclarationRule.h"

#include <map>

std::string NoDeclarationRule::validate(QueryObject& qo) {
    bool followsRule = followsNoDeclaration(qo);
    if (followsRule) {
        return "";
    } else {
        return VALIDATION_RULE_NO_DECLARATION;
    }
}

bool NoDeclarationRule::followsNoDeclaration(QueryObject& qo) {
    std::vector<Entity*> declarations = qo.getDeclarations();
    std::map<std::string, int> declarationMap;
    bool ruleFollowed = true;

    // get all declaration entities into a map
    for (Entity* declaration : declarations) {
        std::string declarationName = std::move(declaration->getIdentifier());
        declarationMap[declarationName] = 1;
    }

    //insert all constraint entities into a vector
    std::vector<Constraint*> constraints = qo.getConstraints();
    std::vector<Entity*> constraintEntities;
    for (Constraint* c : constraints) {
        std::vector<ConstraintArgument*> args = std::move(c->getConstraintArguments());
        for (ConstraintArgument* consArg : args) {
            if (dynamic_cast<Entity*>(consArg) != nullptr) {
                //if consArg is an instance of Entity
                constraintEntities.push_back(dynamic_cast<Entity*>(consArg));
            }
        }
    }

    //check all constraintEntities are declared in the map
    for (Entity* entity: constraintEntities) {
        if (!declarationMap.count(entity->getIdentifier())) {
            ruleFollowed = false;
            break;
        }
    }

    return ruleFollowed;
}

