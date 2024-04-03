//
// Created by Chua Bing Quan on 2/4/24.
//

#include "CFGCollection.h"

CFGCollection::CFGCollection(const std::shared_ptr<Program> &program) {
    this->cfgs = std::make_shared<std::vector<std::shared_ptr<CFG>>>();
    for (const auto& procedure : *program->getProcedures()) {
        const auto cfg = std::make_shared<CFG>(procedure);
        this->cfgs->push_back(cfg);
        this->cfgByName.insert({ procedure->getName(), cfg });
        const auto range = cfg->getRange();
        this->cfgByIntervalStart.insert({ range.first, { range.second, cfg } });
    }
}

std::optional<std::shared_ptr<CFG>> CFGCollection::find(const std::string& procedureName) const {
    const auto it = this->cfgByName.find(procedureName);
    if (it == this->cfgByName.end()) {
        return std::nullopt;
    }
    return it->second;
}

std::optional<std::shared_ptr<CFG>> CFGCollection::find(StmtNo stmtNo) const {
    if (this->cfgByIntervalStart.empty()) {
        return std::nullopt;
    }

    const auto it = this->cfgByIntervalStart.lower_bound(stmtNo);

    if (it != this->cfgByIntervalStart.begin()) {
        const auto prevIt = std::prev(it);
        if (prevIt->first <= stmtNo && stmtNo <= prevIt->second.first) {
            return prevIt->second.second;
        }
    }

    if (it != this->cfgByIntervalStart.end() && it->first <= stmtNo && stmtNo <= it->second.first) {
        return it->second.second;
    }

    return std::nullopt;
}

std::shared_ptr<std::vector<std::shared_ptr<CFG>>> CFGCollection::get() const {
    return this->cfgs;
}