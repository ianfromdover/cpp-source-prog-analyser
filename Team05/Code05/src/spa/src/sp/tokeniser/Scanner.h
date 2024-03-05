//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SCANNER_H
#define SPA_SCANNER_H
#include <iostream>
#include "sp/tokeniser/token/Token.h"
#include "sp/tokeniser/strategy/TokenStrategy.h"
#include "sp/tokeniser/strategy/SingleCharacterStrategy.h"
#include "sp/tokeniser/strategy/DoubleCharacterStrategy.h"
#include "sp/tokeniser/strategy/MultiCharacterStrategy.h"

class Scanner {
private:
    std::string source;
    std::shared_ptr<std::vector<std::shared_ptr<TokenStrategy>>> strategies;
    std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokens;

public:
    explicit Scanner(const std::string& source);
    std::shared_ptr<std::vector<std::shared_ptr<Token>>> scanTokens();
};


#endif //SPA_SCANNER_H
