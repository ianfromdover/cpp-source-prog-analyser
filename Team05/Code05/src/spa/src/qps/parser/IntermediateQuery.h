//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_INTERMEDIATEQUERY_H
#define SPA_INTERMEDIATEQUERY_H


#include <vector>
#include <memory>
#include <map>
#include "Clause.h"
#include "DeclarationClause.h"
#include "SelectClause.h"
#include "RelationshipClause.h"
#include "PatternClause.h"


class IntermediateQuery {
public:
    IntermediateQuery() = default;

    std::vector<std::shared_ptr<Clause>> clauses;

    void addClause(const std::shared_ptr<Clause> &clause);

    bool hasDeclarationClause();
    bool hasSelectClause();
    bool hasRelationshipClause();
    bool hasPatternClause();

    std::shared_ptr<SelectClause> getSelectClause();
    std::shared_ptr<RelationshipClause> getRelationshipClause();
    std::shared_ptr<PatternClause> getPatternClause();
    std::vector<std::shared_ptr<RelationshipClause>> getAllRelationshipClauses();
    std::vector<std::shared_ptr<PatternClause>> getAllPatternClauses();
    void processDeclarations();


    std::map<std::string, QPSTokenType::QPSTypeInfo> getSynonymTypeMap();

    bool operator==(const IntermediateQuery &other) const {
        return clauses == other.clauses;
    }

    std::string toString() {
        std::string result = "IntermediateQuery: ";
        for (const auto &clause : clauses) {
            result += clause->toString() + " ";
        }
        return result;
    }

private:
    bool hasClauseType(Clause::ClauseType type);

    std::shared_ptr<std::map<QPSTokenType::QPSTypeInfo, std::vector<std::string>>> typeSynonymMap = std::make_shared<std::map<QPSTokenType::QPSTypeInfo, std::vector<std::string>>>();

    std::shared_ptr<std::map<std::string, QPSTokenType::QPSTypeInfo>> synonymTypeMap = std::make_shared<std::map<std::string, QPSTokenType::QPSTypeInfo>>();

    void addDeclaration(QPSTokenType::QPSTypeInfo type, const std::string &synonym);

};


#endif //SPA_INTERMEDIATEQUERY_H
