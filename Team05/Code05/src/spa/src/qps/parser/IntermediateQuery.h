//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_INTERMEDIATEQUERY_H
#define SPA_INTERMEDIATEQUERY_H


#include <vector>
#include <memory>
#include "Clause.h"

class IntermediateQuery {

public:
    IntermediateQuery() = default;
    std::vector<std::shared_ptr<Clause>> clauses;
    void addClause(const std::shared_ptr<Clause>& clause);

    bool hasDeclarationClause();
    bool hasSelectClause();

};


#endif //SPA_INTERMEDIATEQUERY_H
