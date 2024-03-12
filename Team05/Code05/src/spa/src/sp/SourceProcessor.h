//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SOURCEPROCESSOR_H
#define SPA_SOURCEPROCESSOR_H

#include <utility>

#include "sp/tokenizer/Scanner.h"
#include "sp/extractor/RelationExtractor.h"
#include "sp/extractor/relation_extractor/ParentExtractor.h"
#include "sp/parser/Parser.h"

class SourceProcessor {
private:
    shared_ptr<BasePKBPopulator> pkb;
 
public:
    explicit SourceProcessor(shared_ptr<BasePKBPopulator> pkb) : pkb(std::move(pkb)) {};
    void exec(const std::string& source);
    shared_ptr<std::vector<std::shared_ptr<Token>>> scan(const std::string& source);
    std::shared_ptr<Program> parse(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens);
    void validate(const std::shared_ptr<Program>& program);
    void extract(const std::shared_ptr<Program>& program);
};


#endif //SPA_SOURCEPROCESSOR_H
