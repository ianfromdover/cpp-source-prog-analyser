//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SOURCEPROCESSOR_H
#define SPA_SOURCEPROCESSOR_H

#include "TokenList.h"
#include "StrategyList.h"
#include "Scanner.h"

class SourceProcessor {
private:
    StrategyList* strategies = new StrategyList();
    TokenList* tokens = new TokenList();
public:
    SourceProcessor() = default;
    void runScanner(std::string source);
};


#endif //SPA_SOURCEPROCESSOR_H
