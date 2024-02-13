//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_TOKENLIST_H
#define SPA_TOKENLIST_H
#include <iostream>
#include <vector>
#include "Token.h"
#include "TokenType.h"

class TokenList {
private:
    std::vector<std::shared_ptr<Token>> tokens;
public:
    TokenList() = default;
    void addToken(TokenType::TypeInfo typeInfo, const std::string& lexeme);
    std::vector<std::shared_ptr<Token>>& getTokens();
    std::string toString();
};


#endif //SPA_TOKENLIST_H
