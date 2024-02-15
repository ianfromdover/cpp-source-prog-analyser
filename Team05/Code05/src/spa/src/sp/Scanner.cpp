//
// Created by sjh_9 on 9/2/2024.
//

#include "Scanner.h"

Scanner::Scanner(const std::string& source, std::shared_ptr<std::vector<std::shared_ptr<TokenStrategy>>>& strategies,
        std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) {
    this->source = source;
    this->tokens = tokens;
    this->strategies=strategies;
}

void Scanner::scanTokens() {
    std::stringstream stream(this->source);
    char character;
    bool prevTokenIsKeyword = false;
    populateStrategies();
    while (stream.get(character)) {
        for (auto &strategy: *strategies) {
            if (strategy->tokenize(character, stream, tokens, prevTokenIsKeyword)) {
                break;
            }
        }
    }
    (*strategies).back()->addToken(TokenType::END_OF_FILE, "EOF", tokens);
}

void Scanner::populateStrategies() {
    strategies->push_back(std::make_shared<SingleCharacterStrategy>());
    strategies->push_back(std::make_shared<DoubleCharacterStrategy>());
    strategies->push_back(std::make_shared<MultiCharacterStrategy>());
}