//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_MULTICHARACTERSTRATEGY_H
#define SPA_MULTICHARACTERSTRATEGY_H

#include "TokenStrategy.h"

namespace qps {
    class MultiCharacterStrategy : public TokenStrategy {
    public:
        bool tokenize(char character, std::stringstream &stream, TokenList &tokens, bool &prevTokenIsKeyword) override;

        bool expectSynonymNext(const std::string &name, TokenList &tokens, bool &declarationStarted);

    private:
        std::string readWhile(std::stringstream &stream, const std::function<bool(char)> &condition);
    };
}
#endif //SPA_MULTICHARACTERSTRATEGY_H
