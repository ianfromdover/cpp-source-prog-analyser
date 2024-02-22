//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"
#include "UsesExtractor.h"
#include "ModifiesExtractor.h"
#include "ReadExtractor.h"
#include "CallExtractor.h"
#include "IfExtractor.h"
#include "WhileExtractor.h"
#include "PrintExtractor.h"
#include "AssignExtractor.h"
#include "StatementExtractor.h"
#include "VariableExtractor.h"
#include "ConstantExtractor.h"
#include "FollowsExtractor.h"
#include "SemanticAnalyzer.h"

void SourceProcessor::exec(const std::string& source) {
    auto tokens = this->scan(source);
    auto program = this->parse(tokens);
    this->validate(program);
    this->extract(program);
}

std::shared_ptr<std::vector<std::shared_ptr<Token>>> SourceProcessor::scan(const std::string& source) {
    return Scanner(source).scanTokens();
}

Program SourceProcessor::parse(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) {
    return Parser(tokens).parse();
}

void SourceProcessor::validate(const Program &program) {
    SemanticAnalyzer().check(program);
}

void SourceProcessor::extract(const Program& program) {
    auto relationExtractor = std::vector<shared_ptr<ProgramVisitor>>{
            std::make_shared<ReadExtractor>(this->pkb),
            std::make_shared<CallExtractor>(this->pkb),
            std::make_shared<IfExtractor>(this->pkb),
            std::make_shared<WhileExtractor>(this->pkb),
            std::make_shared<PrintExtractor>(this->pkb),
            std::make_shared<AssignExtractor>(this->pkb),
            std::make_shared<StatementExtractor>(this->pkb),
            std::make_shared<VariableExtractor>(this->pkb),
            std::make_shared<ConstantExtractor>(this->pkb),
            std::make_shared<ParentExtractor>(this->pkb),
            std::make_shared<UsesExtractor>(this->pkb),
            std::make_shared<ModifiesExtractor>(this->pkb),
            std::make_shared<FollowsExtractor>(this->pkb)
    };
    for (const auto& procedure : *program) {
        //std::cout << "pkb.addProcedure(" << procedure->getProcName() << ");" << std::endl;
        pkb->addProcedure(procedure->getName());
        for (const auto& extractor : relationExtractor) {
            procedure->accept(*extractor);
        }
    }
}
