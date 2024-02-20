//
// Created by Alex on 15/2/2024.
//

#include "Tokenizer.h"

namespace qps {
    Tokenizer::Tokenizer(const std::string &source, std::shared_ptr<StrategyList>& strategies, std::shared_ptr<TokenList>& tokens) {
        this->source = source;
        this->strategies = strategies;
        this->tokens = tokens;
    }

    void Tokenizer::tokenize() {
        std::stringstream stream(this->source);
        char character;
        bool declarationStarted = false;
        while (stream.get(character)) {
            for (const auto &strategy: strategies->getStrategies()) {
                if (strategy->tokenize(character, stream, *tokens, declarationStarted)) {
                    break;
                }
            }
        }
        tokens->addToken(TokenType::END_OF_FILE, "EOF");
    }
}