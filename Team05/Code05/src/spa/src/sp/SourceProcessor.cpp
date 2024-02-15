//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"

void SourceProcessor::exec(const std::string& source) {
    auto tokens = this->scan(source);
    auto program = this->parse(tokens);
    this->extract(program);
}

shared_ptr<std::vector<std::shared_ptr<Token>>> SourceProcessor::scan(const std::string& source) {
    auto tokens = std::make_shared<std::vector<std::shared_ptr<Token>>>();
    auto strategies = std::make_shared<std::vector<std::shared_ptr<TokenStrategy>>>();
    auto scanner = Scanner(source, strategies, tokens);
    scanner.scanTokens();
    return tokens;
}

Program SourceProcessor::parse(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) {
    return Parser(tokens).parse();
}

void SourceProcessor::extract(const Program& program) {
    ParentExtractor parentExtractor(this->pkb);
    for (const auto& procedure : *program) {
        procedure->accept(parentExtractor);
    }
}
