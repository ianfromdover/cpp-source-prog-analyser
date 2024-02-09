//
// Created by sjh_9 on 9/2/2024.
//

#include "TokenList.h"

void TokenList::addToken(TokenType::TypeInfo typeInfo, const std::string& lexeme) {
    TokenType tokenType(typeInfo);
    std::shared_ptr<Token> token = std::make_shared<Token>(tokenType, lexeme);
    tokens.push_back(token);
}

std::vector<std::shared_ptr<Token>>& TokenList::getTokens() {
    return tokens;
}

std::string TokenList::toString() {
    std::string list;
    for (const auto& token : tokens) {
        list += (token->toString() + '\n');
    }
    return list;
}

