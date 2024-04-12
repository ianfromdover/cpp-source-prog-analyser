//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSSINGLECHARACTERSTRATEGY_H
#define SPA_QPSSINGLECHARACTERSTRATEGY_H

#include "QPSTokenStrategy.h"
#include <unordered_set>

class QPSSingleCharacterStrategy : public QPSTokenStrategy {
public:
    QPSSingleCharacterStrategy() = default;

    bool tokenize(char character, std::stringstream &stream, QPSTokenList &tokens, bool &prevTokenIsKeyword) override;

  private:
    std::unordered_set<QPSTokenType::QPSTypeInfo> relationshipKeywords = {
        QPSTokenType::FOLLOWS,
        QPSTokenType::FOLLOWS_T,
        QPSTokenType::PARENT,
        QPSTokenType::PARENT_T,
        QPSTokenType::USES,
        QPSTokenType::MODIFIES,
        QPSTokenType::CALLS,
        QPSTokenType::CALLS_T,
        QPSTokenType::NEXT,
        QPSTokenType::NEXT_T,
        QPSTokenType::AFFECTS,
    };
};


#endif //SPA_QPSSINGLECHARACTERSTRATEGY_H
