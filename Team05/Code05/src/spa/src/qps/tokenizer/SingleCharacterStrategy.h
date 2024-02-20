//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_SINGLECHARACTERSTRATEGY_H
#define SPA_SINGLECHARACTERSTRATEGY_H

#include "TokenStrategy.h"

namespace qps {
    class SingleCharacterStrategy : public TokenStrategy {
    public:
        SingleCharacterStrategy() = default;

        bool tokenize(char character, std::stringstream &stream, TokenList &tokens, bool &prevTokenIsKeyword) override;
    };
}

#endif //SPA_SINGLECHARACTERSTRATEGY_H
