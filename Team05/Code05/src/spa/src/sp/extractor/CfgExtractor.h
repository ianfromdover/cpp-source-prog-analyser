//
// Created by sjh_9 on 22/3/2024.
//

#ifndef SPA_CFGEXTRACTOR_H
#define SPA_CFGEXTRACTOR_H

#include "pkb/apis/PopulatePKB.h"
#include "sp/ast/Stmt.h"

class CFG;

class CfgExtractor {
protected:
    std::shared_ptr<BasePKBPopulator> pkb;
public:
    explicit CfgExtractor(std::shared_ptr<BasePKBPopulator> pkb) : pkb(std::move(pkb)) {};
    virtual ~CfgExtractor() = default;
    // Block Methods
    virtual void visitCFG(const CFG&);
};


#endif //SPA_CFGEXTRACTOR_H
