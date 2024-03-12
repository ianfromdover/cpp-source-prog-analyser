//
// Created by Alex on 15/2/2024.
//

#include "QPSTokenList.h"


void QPSTokenList::addToken(QPSTokenType::QPSTypeInfo typeInfo, const std::string &lexeme) {
    QPSTokenType tokenType(typeInfo);
    std::shared_ptr<QPSToken> token = std::make_shared<QPSToken>(tokenType, lexeme);
    tokens.push_back(token);
}

std::vector<std::shared_ptr<QPSToken>> &QPSTokenList::getTokens() {
    return tokens;
}

std::string QPSTokenList::toString() {
    std::string list;
    for (const auto &token: tokens) {
        list += (token->toString() + '\n');
    }
    return list;
}
