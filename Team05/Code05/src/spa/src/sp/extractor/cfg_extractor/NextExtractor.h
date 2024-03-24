//
// Created by sjh_9 on 22/3/2024.
//

#ifndef SPA_NEXTEXTRACTOR_H
#define SPA_NEXTEXTRACTOR_H

#include <unordered_set>
#include "sp/extractor/CfgExtractor.h"
#include "sp/cfg/block/Block.h"

class NextExtractor : public CfgExtractor {
public:
    // Constructor
    explicit NextExtractor(std::shared_ptr<BasePKBPopulator> pkb) : CfgExtractor(std::move(pkb)) {};
    // Block Methods
    void visitCFG(const CFG& cfg) override;
    void addNextRelation(StmtNo from, StmtNo to);
    void processPredecessors(const std::shared_ptr<Block> &block);
    void processSuccessors(const std::shared_ptr<Block> &block);
    void processBody(const std::shared_ptr<Block>& block);
};


#endif //SPA_NEXTEXTRACTOR_H
