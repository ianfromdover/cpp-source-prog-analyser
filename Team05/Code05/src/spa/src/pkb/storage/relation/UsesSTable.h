#pragma once
#define SPA_USESSTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class UsesSTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    UsesSTable() = default;
    bool addUsesS(StmtNo sNum, VarName name);
    vector<VarName> getUsesBySNum(StmtNo sNum);
    vector<StmtNo> getUsesByVar(VarName name);
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllAsStrings();
};
