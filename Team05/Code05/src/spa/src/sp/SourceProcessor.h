//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SOURCEPROCESSOR_H
#define SPA_SOURCEPROCESSOR_H

#include "TokenList.h"
#include "StrategyList.h"
#include "Scanner.h"
#include "RelationExtractor.h"
#include "ParentExtractor.h"
#include "Parser.h"

class SourceProcessor {
private:
    StrategyList strategies;
    TokenList tokens;
    PopulatePKB& pkb;

public:
    explicit SourceProcessor(PopulatePKB& pkb) : pkb(pkb) {};
    void exec(const std::string& source);

public:
    // TODO: Make private or something.
    void runScanner(const std::string& source);
    Program parse();
    void runRelationExtractor(const Program& program);
};


#endif //SPA_SOURCEPROCESSOR_H
