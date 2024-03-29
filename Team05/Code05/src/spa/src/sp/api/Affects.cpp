//
// Created by Chua Bing Quan on 27/3/24.
//

#include "Affects.h"

Affects::Affects(const std::shared_ptr<CFGs> &cfgs) {
    this->cfgs = cfgs;
    this->defUseChain = DefUseChain();
    this->meet = [](const DefinitionSet& s1, const DefinitionSet& s2) {
        auto result = s1;
        result.insert(s2.begin(), s2.end());
        return result;
    };
    this->transfer = [&](const std::shared_ptr<Block>& block, const DefinitionSet& in) {
        // TODO: Figure out how variable shadowing within the same block (gen) should be handled (if at all).
        auto out = in;
        if (block->isDummy()) {
            return std::move(out);
        }
        const auto& gen = this->currentCFGDefinitions.at(block);
        const auto& kill = Affects::computeKillSet(in, gen);
        Affects::computeSetDifference(out, kill);
        out.insert(gen.begin(), gen.end());
        return std::move(out);
    };
    this->extractor = DefUseExtractor();
}

// TODO: Consider renaming this method to "intersection".
DefinitionSet Affects::computeKillSet(const DefinitionSet &in, const DefinitionSet &gen) {
    DefinitionSet kill;
    if (in.empty() || gen.empty()) {
        return std::move(kill);
    }

    std::unordered_set<std::string> genNames;
    for (const auto& def : gen) {
        genNames.insert(def.getName());
    }

    for (const auto& def : in) {
        if (genNames.find(def.getName()) != genNames.end()) {
            kill.insert(def);
        }
    }

    return std::move(kill);
}

// TODO: Consider renaming this method to "difference".
void Affects::computeSetDifference(DefinitionSet &minuend, const DefinitionSet &subtrahend) {
    for (const auto& elem : subtrahend) {
        minuend.erase(elem);
    }
}

std::pair<Solver<DefinitionSet>::Facts, Solver<DefinitionSet>::Facts> Affects::compute() {
    // TODO: Consider if analysis should be conducted on specific CFGs (given by get(s1, s2)) or on all CFGs.
    // TODO: Figure out how to conduct analysis across procedures (because of call).
    // TODO: Figure out how to populate def-use chain (especially if CFGs are incrementally analyzed across get calls).
    // TODO: When implementation is done, return void.
    for (const auto& [_, cfg] : *cfgs) {
        std::tie(this->currentCFGDefinitions, this->currentCFGUses) = this->extractor.extract(cfg);
        const auto [in, out] = Solver<DefinitionSet>::solve(cfg, this->meet, this->transfer, DefinitionSet());
        return { std::move(in), std::move(out) };
    }
}

std::pair<Solver<DefinitionSet>::Facts, Solver<DefinitionSet>::Facts> Affects::get(StmtNo s1, StmtNo s2) {
//    if (this->defUseChain.empty()) {
//        this->compute();
//    }
//    return false;
    // TODO: Revisit this this when compute implementation is complete.
    // TODO: When implementation is done, return bool.
    return this->compute();
}

void Affects::flush() {
    // TODO: Revisit this this when compute implementation is complete.
    this->defUseChain.clear();
}