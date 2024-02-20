//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKENIZER_H
#define SPA_TOKENIZER_H


#include "TokenList.h"
#include "StrategyList.h"

namespace qps {
    class Tokenizer {
    private:
        std::string source;
        std::shared_ptr<TokenList> tokens;
        std::shared_ptr<StrategyList> strategies;

    public:
        Tokenizer(const std::string &source, std::shared_ptr<StrategyList>& strategies, std::shared_ptr<TokenList>& tokens);

        void tokenize();
    };
}


#endif //SPA_TOKENIZER_H
