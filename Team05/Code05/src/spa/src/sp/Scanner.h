//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SCANNER_H
#define SPA_SCANNER_H
#include <iostream>
#include "Token.h"
#include "TokenStrategy.h"
#include "SingleCharacterStrategy.h"
#include "DoubleCharacterStrategy.h"
#include "MultiCharacterStrategy.h"

class Scanner {
private:
    std::string source;
    std::shared_ptr<std::vector<std::shared_ptr<TokenStrategy>>> strategies;
    std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokens;
    void populateStrategies();

public:
    Scanner(const std::string& source, std::shared_ptr<std::vector<std::shared_ptr<TokenStrategy>>>& strategies,
            std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens);
    void scanTokens();
};


#endif //SPA_SCANNER_H
