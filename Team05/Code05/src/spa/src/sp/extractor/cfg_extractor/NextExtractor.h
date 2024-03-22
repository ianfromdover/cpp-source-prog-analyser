//
// Created by sjh_9 on 22/3/2024.
//

#ifndef SPA_NEXTEXTRACTOR_H
#define SPA_NEXTEXTRACTOR_H

#include "sp/extractor/CfgExtractor.h"
#include <unordered_set>

class NextExtractor : public CfgExtractor {
private:
    std::unordered_set<std::string> visited = std::unordered_set<std::string>();
public:
    // Constructor
    explicit NextExtractor(std::shared_ptr<BasePKBPopulator> pkb) : CfgExtractor(std::move(pkb)) {};
    // Block Methods
    void visitBlock(const Block& block) override;
    void addNextRelation(const std::shared_ptr<Stmt> &fromStmt, const std::shared_ptr<Stmt> &toStmt);
    void processPredecessors(const std::shared_ptr<Block> &block);
    void processSuccessors(const std::shared_ptr<Block> &block);
    void processStatementList(const std::shared_ptr<Block>& block);
};


#endif //SPA_NEXTEXTRACTOR_H
