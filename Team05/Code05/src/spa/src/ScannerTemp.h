//
// Created by sjh_9 on 8/2/2024.
//

#ifndef SPA_SCANNERTEMP_H
#define SPA_SCANNERTEMP_H

#include <iostream>
#include <vector>
#include "Token.h"
#include "TokenType.h"

class ScannerTemp {
private:
    std::string source;
    std::vector<std::shared_ptr<Token>> tokenList;

public:
    explicit ScannerTemp(const std::string& source);
    void scanTokens();
    void addToken(TokenType::TypeInfo typeInfo, const std::string& lexeme);
    bool isKeyword(const std::string &name, bool prevTokenIsKeyword);
};


#endif //SPA_SCANNERTEMP_H
