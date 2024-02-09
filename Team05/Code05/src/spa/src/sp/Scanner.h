//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SCANNER_H
#define SPA_SCANNER_H
#include <iostream>
#include "TokenList.h"
#include "StrategyList.h"

class Scanner {
private:
    std::string source;
    StrategyList strategies;
    TokenList tokens;

public:
    Scanner(const std::string& source, StrategyList& strategies, TokenList& tokens);
    void scanTokens();
};


#endif //SPA_SCANNER_H
