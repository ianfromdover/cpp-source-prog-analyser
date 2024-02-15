//
// Created by Alex on 16/2/2024.
//

#include "IntermediateQuery.h"

void IntermediateQuery::addClause(const std::shared_ptr<Clause>& clause) {
    clauses.push_back(clause);
}
