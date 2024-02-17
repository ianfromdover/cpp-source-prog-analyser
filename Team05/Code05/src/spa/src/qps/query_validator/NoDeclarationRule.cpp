//
// Created by tohzh on 10/2/2024.
//

#include "NoDeclarationRule.h"
#include "qps/query_elements/constraint_argument/IntegerArgument.h"

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
    std::vector<std::shared_ptr<Entity>> declarations = qo.getDeclarations();
    std::map<std::string, int> declarationMap;
    bool ruleFollowed = true;

    // get all declaration entities into a map
    for (std::shared_ptr<Entity> declaration : declarations) {
        std::string declarationName = std::move(declaration->getIdentifier());
        declarationMap[declarationName] = 1;
    }

    //insert all constraint entities into a vector
    std::vector<std::shared_ptr<Constraint>> constraints = qo.getConstraints();
    std::vector<Entity*> constraintEntities;
    for (std::shared_ptr<Constraint> c : constraints) {
        std::vector<std::shared_ptr<ConstraintArgument>> args = std::move(c->getConstraintArguments());
        for (std::shared_ptr<ConstraintArgument> consArg : args) {
            if (dynamic_cast<IntegerArgument*>(consArg.get()) != nullptr) {
                //if consArg is an instance of Entity
                continue;
            }
            if (dynamic_cast<Entity*>(consArg.get()) != nullptr) {
                //if consArg is an instance of Entity
                ConstraintArgument* arg = consArg.get();
                constraintEntities.push_back(dynamic_cast<Entity*>(arg));
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

std::string NoDeclarationRule::validate(IntermediateQuery & query) {
    std::string selectSyn = query.getSelectClause().getAllSelect()[0]; // Assumed to only have one select element

    auto it = query.getSynonymTypeMap().find(selectSyn);
    if (it == query.getSynonymTypeMap().end()) {
        return VALIDATION_RULE_NO_DECLARATION;
    } else {
        if (it->second != TokenType::TypeInfo::ASSIGN) {
            return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
        }
    }
    return "";
}

