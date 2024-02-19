//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_TOKENSTRATEGY_H
#define SPA_TOKENSTRATEGY_H
#include <iostream>
#include <sstream>
#include <functional>
#include <cctype>
#include <map>
#include "Token.h"

class TokenStrategy {
public:
    virtual ~TokenStrategy() = default;
    virtual bool tokenize(char character, std::stringstream& stream,
                          std::shared_ptr<std::vector<std::shared_ptr<Token>>>&, bool& prevTokenIsKeyword) = 0;
    virtual void addToken(TokenType::TypeInfo typeInfo, const std::string &lexeme,
                           std::shared_ptr<std::vector<std::shared_ptr<Token>>> &tokens);
};


#endif //SPA_TOKENSTRATEGY_H
