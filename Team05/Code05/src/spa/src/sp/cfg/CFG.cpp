//
// Created by Chua Bing Quan on 15/3/24.
//

#include "CFG.h"

CFG::CFG(const std::shared_ptr<Program>& program) {
    this->blocks = CFG::compile(program);
}

std::shared_ptr<Block> CFG::getEntryBlock() const {
    return this->blocks->front();
}

std::shared_ptr<Blocks> CFG::getBlocks() const {
    return this->blocks;
}

std::shared_ptr<Blocks> CFG::compile(const std::shared_ptr<Program>& program) {
    for (const auto& procedure : *program->getProcedures()) {
        for (auto& stmt : *procedure->getBody()) {
            // TODO: Complete compilation from Program to CFG.
        }
    }
}
