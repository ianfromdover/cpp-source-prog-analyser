//
// Created by Alex on 16/2/2024.
//

#include <algorithm>
#include <stdexcept>
#include "IntermediateQuery.h"
#include "SelectClause.h"
#include "RelationshipClause.h"
#include "PatternClause.h"
#include "qps/Exceptions/QpsException.h"


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
    throw QpsException("No select clause found");
}

std::shared_ptr<RelationshipClause> IntermediateQuery::getRelationshipClause() {
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::RELATIONSHIP) {
            return std::dynamic_pointer_cast<RelationshipClause>(clause);
        }
    }
    throw QpsException("No relationship clause found");
}

std::shared_ptr<PatternClause> IntermediateQuery::getPatternClause() {
    for (const auto &clause: clauses) {
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            return std::dynamic_pointer_cast<PatternClause>(clause);
        }
    }
    throw QpsException("No pattern clause found");
}


