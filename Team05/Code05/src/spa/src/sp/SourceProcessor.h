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
    StrategyList strategies;
    TokenList tokens;
public:
    SourceProcessor() = default;
    void runScanner(const std::string& source);
    void runRelationExtractor();
};


#endif //SPA_SOURCEPROCESSOR_H
