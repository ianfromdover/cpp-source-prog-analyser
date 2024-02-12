//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"

void SourceProcessor::exec(const std::string& source) {
    this->runScanner(source);
    auto program = this->parse();
    this->runRelationExtractor(program);
}

void SourceProcessor::runScanner(const std::string& source) {
    auto scanner = Scanner(source, strategies, tokens);
    scanner.scanTokens();
}

Program SourceProcessor::parse() {
    return Parser(this->tokens).parse();
}

void SourceProcessor::runRelationExtractor(const Program& program) {
    ParentExtractor parentExtractor(this->pkb);
    for (const auto& procedure : *program) {
        procedure->accept(parentExtractor);
    }
}
