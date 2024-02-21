//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_DECLARATIONCLAUSE_H
#define SPA_DECLARATIONCLAUSE_H

#include <map>
#include <vector>
#include "Clause.h"
#include "qps/tokenizer/QPSTokenType.h"


class DeclarationClause : public Clause {
public:
    DeclarationClause() : Clause(ClauseType::DECLARATION) {}

    std::map<QPSTokenType, std::vector<std::string>> declarationMap;

    void addDeclaration(const QPSTokenType &, const std::string &);

    std::vector<std::pair<QPSTokenType::QPSTypeInfo, std::string>> getAllDeclarations();
};


#endif //SPA_DECLARATIONCLAUSE_H
