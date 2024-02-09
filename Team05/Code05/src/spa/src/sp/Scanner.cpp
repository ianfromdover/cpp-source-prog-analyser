//
// Created by sjh_9 on 9/2/2024.
//

#include "Scanner.h"

Scanner::Scanner(const std::string& source, StrategyList& strategies, TokenList& tokens) {
    this->source = source;
    this->strategies = strategies;
    this->tokens = tokens;
}

void Scanner::scanTokens() {
    std::stringstream stream(this->source);
    char character;
    bool prevTokenIsKeyword = false;
    while (stream.get(character)) {
        for (const auto& strategy : strategies.getStrategies()) {
            if (strategy->tokenize(character, stream, tokens, prevTokenIsKeyword)) {
                break;
            }
        }
    }
}