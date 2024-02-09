//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"

void SourceProcessor::runScanner(std::string source) {
    auto scanner = new Scanner(source, strategies, tokens);
    scanner->scanTokens();
    std::cout << tokens.toString() << std::endl;
}