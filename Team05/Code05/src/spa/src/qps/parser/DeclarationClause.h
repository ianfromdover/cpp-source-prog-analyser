//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_DECLARATIONCLAUSE_H
#define SPA_DECLARATIONCLAUSE_H

#include <map>
#include <vector>
#include "Clause.h"
#include "qps/tokenizer/TokenType.h"

namespace qps {
    class DeclarationClause : public Clause {
    public:
        DeclarationClause() : Clause(ClauseType::DECLARATION) {}

        std::map<TokenType, std::vector<std::string>> declarationMap;

        void addDeclaration(const TokenType &, const std::string &);

        std::vector<std::pair<TokenType::TypeInfo, std::string>> getAllDeclarations();
    };
}


#endif //SPA_DECLARATIONCLAUSE_H
