//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKENLIST_H
#define SPA_TOKENLIST_H


#include <memory>
#include <vector>
#include "Token.h"
#include "TokenType.h"

namespace qps {
    class TokenList {
    private:
        std::vector<std::shared_ptr<Token>> tokens;
    public:
        TokenList() = default;

        void addToken(TokenType::TypeInfo typeInfo, const std::string &lexeme);

        std::vector<std::shared_ptr<Token>> &getTokens();

        std::string toString();
    };
}


#endif //SPA_TOKENLIST_H
