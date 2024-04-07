//
// Created by Chua Bing Quan on 2/4/24.
//

#ifndef SPA_CFGCOLLECTION_H
#define SPA_CFGCOLLECTION_H

#include <map>
#include <memory>
#include <optional>
#include <unordered_map>
#include "sp/ast/Program.h"
#include "CFG.h"

class CFGCollection {
private:
    std::shared_ptr<std::vector<std::shared_ptr<CFG>>> cfgs;
    std::unordered_map<std::string, std::shared_ptr<CFG>> cfgByName;
    std::map<StmtNo, std::pair<StmtNo, std::shared_ptr<CFG>>> cfgByIntervalStart;
public:
    explicit CFGCollection(const std::shared_ptr<Program>& program);
    [[nodiscard]] std::optional<std::shared_ptr<CFG>> find(const std::string& procedureName) const;
    [[nodiscard]] std::optional<std::shared_ptr<CFG>> find(StmtNo stmtNo) const;
    [[nodiscard]] std::shared_ptr<std::vector<std::shared_ptr<CFG>>> get() const;
};


#endif //SPA_CFGCOLLECTION_H
