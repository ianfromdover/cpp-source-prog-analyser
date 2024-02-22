//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SOURCEPROCESSOR_H
#define SPA_SOURCEPROCESSOR_H

#include <utility>

#include "Scanner.h"
#include "RelationExtractor.h"
#include "ParentExtractor.h"
#include "Parser.h"

class SourceProcessor {
private:
    shared_ptr<PKBApi> pkb;
 
public:
    explicit SourceProcessor(shared_ptr<PKBApi> pkb) : pkb(std::move(pkb)) {};
    void exec(const std::string& source);
    shared_ptr<std::vector<std::shared_ptr<Token>>> scan(const std::string& source);
    Program parse(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens);
    void validate(const Program& program);
    void extract(const Program& program);
    SourceProcessor& operator=(const SourceProcessor& other) { return *this; }
};


#endif //SPA_SOURCEPROCESSOR_H
