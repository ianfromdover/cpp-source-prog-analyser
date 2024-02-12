//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"

void SourceProcessor::runScanner(const std::string& source) {
    auto scanner = new Scanner(source, strategies, tokens);
    scanner->scanTokens();
    std::cout << tokens.toString() << std::endl;
}

void SourceProcessor::runRelationExtractor(PopulatePKB& pkb) {
    ParentExtractor parentExtractor(pkb);
    // For each node in the AST
    // node.accept(visitor)
}