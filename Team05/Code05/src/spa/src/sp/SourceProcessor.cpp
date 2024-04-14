//
// Created by sjh_9 on 9/2/2024.
//

#include "SourceProcessor.h"
#include "sp/extractor/relation_extractor/UsesExtractor.h"
#include "sp/extractor/relation_extractor/ModifiesExtractor.h"
#include "sp/extractor/node_extractor/ReadExtractor.h"
#include "sp/extractor/node_extractor/CallExtractor.h"
#include "sp/extractor/node_extractor/IfExtractor.h"
#include "sp/extractor/node_extractor/WhileExtractor.h"
#include "sp/extractor/node_extractor/PrintExtractor.h"
#include "sp/extractor/node_extractor/AssignExtractor.h"
#include "sp/extractor/node_extractor/StatementExtractor.h"
#include "sp/extractor/node_extractor/VariableExtractor.h"
#include "sp/extractor/node_extractor/ConstantExtractor.h"
#include "sp/extractor/relation_extractor/FollowsExtractor.h"
#include "sp/semantic_analyzer/SemanticAnalyzer.h"
#include "sp/extractor/relation_extractor/CallsExtractor.h"
#include "sp/extractor/cfg_extractor/NextExtractor.h"
#include "sp/cfg/CFG.h"

std::shared_ptr<std::vector<std::shared_ptr<Token>>> SourceProcessor::scan(const std::string& source) {
    return Scanner(source).scanTokens();
}

std::shared_ptr<Program> SourceProcessor::parse(const std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) {
    return Parser(tokens).parse();
}

void SourceProcessor::validate(const std::shared_ptr<Program>& program) {
    SemanticAnalyzer().check(program);
}

void SourceProcessor::extract(const std::shared_ptr<Program>& program) {
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
            std::make_shared<UsesExtractor>(this->pkb, program),
            std::make_shared<ModifiesExtractor>(this->pkb, program),
            std::make_shared<FollowsExtractor>(this->pkb),
            std::make_shared<CallsExtractor>(this->pkb, program),
    };
    auto cfgExtractor = std::vector<shared_ptr<CfgExtractor>> {
            std::make_shared<NextExtractor>(this->pkb),
    };
    for (const auto& procedure : *program->getProcedures()) {
        //std::cout << "pkb.addProcedure(" << procedure->getName() << ");" << std::endl;
        pkb->addProcedure(procedure->getName());
        for (const auto& extractor : relationExtractor) {
            procedure->accept(*extractor);
        }
        for (const auto& extractor : cfgExtractor) {
            CFG(procedure).accept(*extractor);
        }
    }
}
