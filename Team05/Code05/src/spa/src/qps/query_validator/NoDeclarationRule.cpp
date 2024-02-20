//
// Created by tohzh on 10/2/2024.
//

#include "NoDeclarationRule.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

#include <map>
#include <algorithm>
#include <iterator>

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
    std::vector<std::string> usedSyns;
    usedSyns.push_back(query.getSelectClause()->getAllSelect()[0]); // Assumed to only have one select element

    // find all used declarations in pattern and relationship clause
    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            std::shared_ptr<PatternClause> patternCl = std::dynamic_pointer_cast<PatternClause>(clause);
            if (patternCl->getFirstArgType() == QPSTokenType::QPSTypeInfo::SYNONYM){
                usedSyns.push_back(patternCl->getFirstArgValue());
            }
            // Expression Spec cannot be a synonym, no need to check
        }
        if (clause->getType() == Clause::ClauseType::RELATIONSHIP) {
            std::shared_ptr<RelationshipClause> relationshipCl = std::dynamic_pointer_cast<RelationshipClause>(clause);
            if (relationshipCl->getFirstArgType() == QPSTokenType::QPSTypeInfo::SYNONYM){
                usedSyns.push_back(relationshipCl->getFirstArg().getLexeme());
            }
            if (relationshipCl->getSecondArgType() == QPSTokenType::QPSTypeInfo::SYNONYM){
                usedSyns.push_back(relationshipCl->getSecondArg().getLexeme());
            }
        }
    }

    // construct a set of all declarations
    std::unordered_set<std::string> declarations;
    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            std::shared_ptr<DeclarationClause> declarationCl = std::dynamic_pointer_cast<DeclarationClause>(clause);
            for (const auto& syn : declarationCl->getAllDeclarations()) {
                declarations.insert(syn.second);
            }
        }
    }

    std::unordered_set<std::string> intersection;
    for (const auto& syn : usedSyns){
        if (declarations.find(syn) == declarations.end()){
            return VALIDATION_RULE_NO_DECLARATION;
        }
    }

    return "";
}

