//
// Created by Chua Bing Quan on 27/3/24.
//

#include "Affects.h"
#include "pkb/apis/QueryPkb.h"

Affects::Affects(const std::shared_ptr<CFGCollection>& cfgCollection, const std::shared_ptr<QueryPkb>& queryPkb) : extractor(queryPkb) {
    this->cfgCollection = cfgCollection;
    this->queryPkb = queryPkb;
    this->meet = [](const DefinitionSet& s1, const DefinitionSet& s2) {
        auto result = s1;
        result.insert(s2.begin(), s2.end());
        return result;
    };
    this->transfer = [&](const std::shared_ptr<Block>& block, const DefinitionSet& in) {
        if (block->isDummy()) {
            return in;
        }
        auto out = in;
        const auto& gen = this->currentCFGDefs.at(block);
        const auto& kill = Affects::findKilledDefinitions(in, gen);
        Affects::removeKilledDefinitions(out, kill);
        out.insert(gen.begin(), gen.end());
        return std::move(out);
    };
}

DefinitionSet Affects::findKilledDefinitions(const DefinitionSet &in, const DefinitionSet &gen) {
    DefinitionSet kill;
    if (in.empty() || gen.empty()) {
        return std::move(kill);
    }

    std::unordered_set<std::string> genNames;
    for (const auto& def : gen) {
        genNames.insert(def->getName());
    }

    for (const auto& def : in) {
        if (genNames.find(def->getName()) != genNames.end()) {
            kill.insert(def);
        }
    }

    return std::move(kill);
}

void Affects::removeKilledDefinitions(DefinitionSet &minuend, const DefinitionSet &subtrahend) {
    for (const auto& elem : subtrahend) {
        minuend.erase(elem);
    }
}

void Affects::compute(const std::shared_ptr<CFG>& cfg) {
    std::tie(this->currentCFGDefs, this->currentCFGUses) = this->extractor.extract(cfg);
    const auto [in, out] = Solver<DefinitionSet>::solve(cfg, this->meet, this->transfer, DefinitionSet());
    this->updateDefUseChain(cfg, in);
}

void Affects::updateDefUseChain(const std::shared_ptr<CFG>& cfg, const std::unordered_map<std::shared_ptr<Block>, DefinitionSet>& in) {
    auto& defUseChain = this->defUseChainMap[cfg->getProcedureName()];
    for (const auto& block : *cfg->getBlocks()) {
        const auto& reachingDefs = in.at(block);
        const auto& blockDefs = this->currentCFGDefs.at(block);
        const auto& blockUses = this->currentCFGUses.at(block);

        for (const auto& use : blockUses) {
            std::vector<StmtNo> reachingStmtNos;
            for (const auto& def : reachingDefs) {
                if (def->getName() == use->getName()) {
                    reachingStmtNos.push_back(*(def->getOccurrences()->rbegin()));
                }
            }

            std::optional<std::shared_ptr<VarOccurrence>> blockDef;
            for (const auto& def : blockDefs) {
                if (def->getName() == use->getName()) {
                    blockDef = def;
                    break;
                }
            }

            if (reachingStmtNos.empty() && !blockDef) {
                continue;
            }

            for (const auto& useStmtNo : *use->getOccurrences()) {
                if (!reachingStmtNos.empty() && (!blockDef || useStmtNo <= *((*blockDef)->getOccurrences()->begin()))) {
                    for (const auto defStmtNo : reachingStmtNos) {
                        defUseChain[defStmtNo].insert(useStmtNo);
                    }
                    continue;
                }

                std::optional<StmtNo> blockDefStmtNo;
                // Occurrences are already sorted in ascending order.
                for (const auto defStmtNo : *(*blockDef)->getOccurrences()) {
                    if (defStmtNo < useStmtNo) {
                        blockDefStmtNo = defStmtNo;
                        continue;
                    }
                    break;
                }

                if (blockDefStmtNo) {
                    defUseChain[*blockDefStmtNo].insert(useStmtNo);
                }
            }
        }
    }
}

bool Affects::get(StmtNo s1, StmtNo s2) {
    if (!this->queryPkb->isAsgn(s1) || !this->queryPkb->isAsgn(s2)) {
        return false;
    }

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