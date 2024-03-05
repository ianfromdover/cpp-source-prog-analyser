//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSSINGLECHARACTERSTRATEGY_H
#define SPA_QPSSINGLECHARACTERSTRATEGY_H

#include "QPSTokenStrategy.h"


class QPSSingleCharacterStrategy : public QPSTokenStrategy {
public:
    QPSSingleCharacterStrategy() = default;

    bool tokenize(char character, std::stringstream &stream, QPSTokenList &tokens, bool &prevTokenIsKeyword) override;
};


#endif //SPA_QPSSINGLECHARACTERSTRATEGY_H
