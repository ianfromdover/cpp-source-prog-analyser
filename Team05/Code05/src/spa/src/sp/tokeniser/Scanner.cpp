//
// Created by sjh_9 on 9/2/2024.
//

#include "Scanner.h"

Scanner::Scanner(const std::string& source) {
    this->source = source;
    this->tokens = std::make_shared<std::vector<std::shared_ptr<Token>>>();
    auto strategyVector = std::vector<std::shared_ptr<TokenStrategy>>{
            std::make_shared<SingleCharacterStrategy>(),
            std::make_shared<DoubleCharacterStrategy>(),
            std::make_shared<MultiCharacterStrategy>()
    };
    this->strategies =  std::make_shared<std::vector<std::shared_ptr<TokenStrategy>>>(strategyVector);
}

std::shared_ptr<std::vector<std::shared_ptr<Token>>> Scanner::scanTokens() {
    std::stringstream stream(this->source);
    char character;
    bool prevTokenIsKeyword = false;
    while (stream.get(character)) {
        for (auto &strategy: *strategies) {
            if (strategy->tokenize(character, stream, tokens, prevTokenIsKeyword)) {
                break;
            }
        }
    }
    (*strategies).back()->addToken(TokenType::END_OF_FILE, "EOF", tokens);
    return tokens;
}