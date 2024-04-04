//
// Created by Chua Bing Quan on 27/3/24.
//

#include "Affects.h"

Affects::Affects(const std::shared_ptr<CFGCollection>& cfgCollection, const std::shared_ptr<QueryPkb>& queryPkb) : extractor(queryPkb) {
    this->cfgCollection = cfgCollection;
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

void Affects::compute(const std::shared_ptr<CFG>& cfg) {
    // TODO: Figure out how to populate def-use chain (especially if CFGs are incrementally analyzed across get calls).

    std::tie(this->currentCFGDefinitions, this->currentCFGUses) = this->extractor.extract(cfg);
    const auto [in, out] = Solver<DefinitionSet>::solve(cfg, this->meet, this->transfer, DefinitionSet());
}

bool Affects::get(StmtNo s1, StmtNo s2) {
    const auto cfg = this->cfgCollection->find(s1);
    if (!cfg || !(*cfg)->containsStmtNo(s2)) {
        return false;
    }

    const auto procedureName = (*cfg)->getProcedureName();
    auto defUseChainIt = this->defUseChainMap.find(procedureName);
    if (defUseChainIt == this->defUseChainMap.end()) {
        this->compute(*cfg);
        defUseChainIt = this->defUseChainMap.find(procedureName);
    }

    const auto defUseChain = defUseChainIt->second;
    const auto defUseIt = defUseChain.find(s1);
    if (defUseIt == defUseChain.end()) {
        return false;
    }

    return defUseIt->second.find(s2) != defUseIt->second.end();
}

void Affects::flush() {
    this->defUseChainMap.clear();
}