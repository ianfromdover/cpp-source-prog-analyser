//
// Created by Alex on 16/2/2024.
//

#include "IntermediateQuery.h"
#include "PatternClause.h"
#include "RelationshipClause.h"
#include "SelectClause.h"
#include "WithClause.h"
#include "qps/exceptions/QPSException.h"
#include <algorithm>
#include <stdexcept>

void IntermediateQuery::addClause(const std::shared_ptr<Clause> &clause) {
    clauses.push_back(clause);
}

bool IntermediateQuery::hasDeclarationClause() {
    return hasClauseType(Clause::ClauseType::DECLARATION);
}

bool IntermediateQuery::hasSelectClause() {
    return hasClauseType(Clause::ClauseType::SELECT);
}

bool IntermediateQuery::hasRelationshipClause() {
    return hasClauseType(Clause::ClauseType::RELATIONSHIP);
}

bool IntermediateQuery::hasPatternClause() {
    return hasClauseType(Clause::ClauseType::PATTERN);
}

bool IntermediateQuery::hasWithClause() {
  return hasClauseType(Clause::ClauseType::WITH);
}

bool IntermediateQuery::hasClauseType(Clause::ClauseType type) {
    return std::any_of(clauses.begin(), clauses.end(), [type](const std::shared_ptr<Clause> &clause) {
        return clause->getType() == type;
    });
}

void IntermediateQuery::processDeclarations() {
    std::vector<std::shared_ptr<DeclarationClause>> declarationClauses;
    for (const std::shared_ptr<Clause> &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            declarationClauses.push_back(std::dynamic_pointer_cast<DeclarationClause>(clause));
        }
    }

    for (const auto &declarationCl: declarationClauses) {
        for (const auto &kvp: declarationCl->getAllDeclarations()) {
            addDeclaration(kvp.first, kvp.second);
        }
    }
}

void IntermediateQuery::addDeclaration(QPSTokenType::QPSTypeInfo type, const std::string &synonym) {
    if (typeSynonymMap->find(type) == typeSynonymMap->end()) {
        typeSynonymMap->insert(std::make_pair(type, std::vector<std::string>()));
    }
    typeSynonymMap->at(type).push_back(synonym);
    synonymTypeMap->insert(std::make_pair(synonym, type));
}

std::map<std::string, QPSTokenType::QPSTypeInfo> IntermediateQuery::getSynonymTypeMap() {
    return *synonymTypeMap;
}

std::shared_ptr<SelectClause> IntermediateQuery::getSelectClause() {
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::SELECT) {
            return std::dynamic_pointer_cast<SelectClause>(clause);
        }
    }
    throw QPSException("No select clause found");
}

std::shared_ptr<RelationshipClause> IntermediateQuery::getRelationshipClause() {
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::RELATIONSHIP) {
            return std::dynamic_pointer_cast<RelationshipClause>(clause);
        }
    }
    throw QPSException("No relationship clause found");
}

std::shared_ptr<PatternClause> IntermediateQuery::getPatternClause() {
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            return std::dynamic_pointer_cast<PatternClause>(clause);
        }
    }
    throw QPSException("No pattern clause found");
}

std::vector<std::shared_ptr<RelationshipClause>> IntermediateQuery::getAllRelationshipClauses() {
    std::vector<std::shared_ptr<RelationshipClause>> relationshipClauses;
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::RELATIONSHIP) {
            auto rClause = std::dynamic_pointer_cast<RelationshipClause>(clause);
            relationshipClauses.push_back(rClause);
        }
    }
    return relationshipClauses;
}

std::vector<std::shared_ptr<PatternClause>> IntermediateQuery::getAllPatternClauses() {
    std::vector<std::shared_ptr<PatternClause>> patternClauses;
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            auto pClause = std::dynamic_pointer_cast<PatternClause>(clause);
            patternClauses.push_back(pClause);
        }
    }
    return patternClauses;
}

std::vector<std::shared_ptr<WithClause>> IntermediateQuery::getAllWithClauses() {
    std::vector<std::shared_ptr<WithClause>> withClauses;
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::WITH) {
            auto wClause = std::dynamic_pointer_cast<WithClause>(clause);
            withClauses.push_back(wClause);
        }
    }
    return withClauses;
}


