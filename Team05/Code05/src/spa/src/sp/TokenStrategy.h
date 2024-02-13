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
#include "TokenList.h"

class TokenStrategy {
public:
    virtual ~TokenStrategy() = default;
    virtual bool tokenize(char character, std::stringstream& stream, TokenList& tokens, bool& prevTokenIsKeyword) = 0;
};


#endif //SPA_TOKENSTRATEGY_H
