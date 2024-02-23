//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSMULTICHARACTERSTRATEGY_H
#define SPA_QPSMULTICHARACTERSTRATEGY_H

#include "QPSTokenStrategy.h"


class QPSMultiCharacterStrategy : public QPSTokenStrategy {
public:
    bool tokenize(char character, std::stringstream &stream, QPSTokenList &tokens, bool &prevTokenIsKeyword) override;

    bool expectSynonymNext(const std::string &name, QPSTokenList &tokens);

private:
    std::string readWhile(std::stringstream &stream, const std::function<bool(char)> &condition);
    bool starAllowed(const std::string& );
};

#endif //SPA_QPSMULTICHARACTERSTRATEGY_H
