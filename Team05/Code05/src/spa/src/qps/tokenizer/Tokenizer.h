//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKENIZER_H
#define SPA_TOKENIZER_H


#include "QPSTokenList.h"
#include "QPSStrategyList.h"


class Tokenizer {
private:
    std::string source;
    std::shared_ptr<QPSTokenList> tokens;
    std::shared_ptr<QPSStrategyList> strategies;

public:
    Tokenizer(const std::string &source, std::shared_ptr<QPSStrategyList> &strategies,
              std::shared_ptr<QPSTokenList> &tokens);

    void tokenize();
};


#endif //SPA_TOKENIZER_H
