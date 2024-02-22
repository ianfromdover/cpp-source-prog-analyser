//
// Created by tohzh on 10/2/2024.
//

#include "NoDeclarationRule.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

#include <map>
#include <algorithm>
#include <iterator>

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

