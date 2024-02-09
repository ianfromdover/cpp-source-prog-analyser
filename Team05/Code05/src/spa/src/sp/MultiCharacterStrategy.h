//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_MULTICHARACTERSTRATEGY_H
#define SPA_MULTICHARACTERSTRATEGY_H
#include "TokenStrategy.h"

class MultiCharacterStrategy : public TokenStrategy {
public:
    bool tokenize(char character, std::stringstream& stream, TokenList& tokens, bool& prevTokenIsKeyword) override;
private:
    bool isKeyword(const std::string& name, TokenList& tokens, bool& prevTokenIsKeyword);
    std::string readWhile(std::stringstream& stream, const std::function<bool(char)>& condition);
};



#endif //SPA_MULTICHARACTERSTRATEGY_H
