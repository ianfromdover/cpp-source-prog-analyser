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
    ReadExtractor readExtractor(this->pkb);
    CallExtractor callExtractor(this->pkb);
    IfExtractor ifExtractor(this->pkb);
    WhileExtractor whileExtractor(this->pkb);
    PrintExtractor printExtractor(this->pkb);
    AssignExtractor assignExtractor(this->pkb);
    StatementExtractor statementExtractor(this->pkb);
    VariableExtractor variableExtractor(this->pkb);
    ConstantExtractor constantExtractor(this->pkb);
    for (const auto& procedure : *program) {
        //procedure->accept(parentExtractor);
        //procedure->accept(usesExtractor);
        //procedure->accept(modifiesExtractor);
        //procedure->accept(followsExtractor);
        //procedure->accept(readExtractor);
        //procedure->accept(callExtractor);
        //procedure->accept(ifExtractor);
        //procedure->accept(whileExtractor);
        //procedure->accept(printExtractor);
        //procedure->accept(assignExtractor);
        //procedure->accept(statementExtractor);
        //std::cout << "pkb.addProcedure(" << procedure->getProcName() << ");" << std::endl;
        //procedure->accept(variableExtractor);
        procedure->accept(constantExtractor);
    }
}
