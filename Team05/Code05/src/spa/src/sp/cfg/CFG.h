//
// Created by Chua Bing Quan on 15/3/24.
//

#ifndef SPA_CFG_H
#define SPA_CFG_H

#include <vector>
#include "sp/ast/Program.h"
#include "sp/cfg/block/Block.h"
#include "sp/cfg/helper/CFGHelper.h"

class CFG {
private:
    std::shared_ptr<Blocks> blocks;
private:
    static std::shared_ptr<Blocks> compile(const std::shared_ptr<Program>& program);
public:
    explicit CFG(const std::shared_ptr<Program>& program);
    std::shared_ptr<Block> getEntryBlock() const;
    std::shared_ptr<Blocks> getBlocks() const;
};


#endif //SPA_CFG_H
