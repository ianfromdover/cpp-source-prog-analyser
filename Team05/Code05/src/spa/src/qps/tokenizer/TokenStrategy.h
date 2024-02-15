//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKENSTRATEGY_H
#define SPA_TOKENSTRATEGY_H

#include <sstream>
#include <functional>
#include "TokenList.h"

namespace qps {
    class TokenStrategy {
    public:
        virtual ~TokenStrategy() = default;

        virtual bool
        tokenize(char character, std::stringstream &stream, TokenList &tokens, bool &prevTokenIsKeyword) = 0;
    };
}


#endif //SPA_TOKENSTRATEGY_H
