//
// Created by Alex on 16/2/2024.
//

#include <algorithm>
#include <stdexcept>
#include "IntermediateQuery.h"
#include "SelectClause.h"
#include "RelationshipClause.h"
#include "PatternClause.h"


void IntermediateQuery::addClause(const std::shared_ptr<Clause>& clause) {
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
    return std::any_of(clauses.begin(), clauses.end(), [type](const std::shared_ptr<Clause>& clause) {
        return clause->getType() == type;
    });
}

void IntermediateQuery::processDeclarations() {
    std::vector<std::shared_ptr<qps::DeclarationClause>> declarationClauses;
    for (const std::shared_ptr<Clause>& clause : clauses) {
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            declarationClauses.push_back(std::dynamic_pointer_cast<qps::DeclarationClause>(clause));
        }
    }

    for (const auto& declarationCl : declarationClauses) {
        for (const auto& kvp : declarationCl->getAllDeclarations()) {
            addDeclaration(kvp.first, kvp.second);
        }
    }
}

void IntermediateQuery::addDeclaration(QPSTokenType::TypeInfo type, const std::string& synonym) {
    if (typeSynonymMap->find(type) == typeSynonymMap->end()) {
        typeSynonymMap->insert(std::make_pair(type, std::vector<std::string>()));
    }
    typeSynonymMap->at(type).push_back(synonym);
    synonymTypeMap->insert(std::make_pair(synonym, type));
}

std::map<std::string, QPSTokenType::TypeInfo> IntermediateQuery::getSynonymTypeMap() {
    return *synonymTypeMap;
}

qps::SelectClause IntermediateQuery::getSelectClause() {
    for (const auto& clause : clauses) {
        if (clause->getType() == Clause::ClauseType::SELECT) {
            return *std::dynamic_pointer_cast<qps::SelectClause>(clause);
        }
    }
    throw std::runtime_error("No relationship clause found");
}

qps::RelationshipClause IntermediateQuery::getRelationshipClause() {
    for (const auto& clause : clauses) {
        if (clause->getType() == Clause::ClauseType::RELATIONSHIP) {
            return *std::dynamic_pointer_cast<qps::RelationshipClause>(clause);
        }
    }
    throw std::runtime_error("No relationship clause found");
}

qps::PatternClause IntermediateQuery::getPatternClause() {
    for (const auto& clause : clauses) {
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            return *std::dynamic_pointer_cast<qps::PatternClause>(clause);
        }
    }
    throw std::runtime_error("No relationship clause found");
}


