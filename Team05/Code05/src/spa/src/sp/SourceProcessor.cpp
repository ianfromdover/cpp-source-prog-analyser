//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"
#include "UsesExtractor.h"
#include "ModifiesExtractor.h"

void SourceProcessor::exec(const std::string& source) {
    auto tokens = this->scan(source);
    auto program = this->parse(tokens);
    this->extract(program);
}

std::shared_ptr<std::vector<std::shared_ptr<Token>>> SourceProcessor::scan(const std::string& source) {
    return Scanner(source).scanTokens();
}

Program SourceProcessor::parse(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) {
    return Parser(tokens).parse();
}

void SourceProcessor::extract(const Program& program) {
    ParentExtractor parentExtractor(this->pkb);
    UsesExtractor usesExtractor(this->pkb);
    ModifiesExtractor modifiesExtractor(this->pkb);
    FollowsExtractor followsExtractor(this->pkb);
    for (const auto& procedure : *program) {
        procedure->accept(parentExtractor);
        procedure->accept(usesExtractor);
        procedure->accept(modifiesExtractor);
        procedure->accept(followsExtractor);
    }
}
