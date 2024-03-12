#pragma once
#define SPA_PATTERN_IF_TABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class PatternIfTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    PatternIfTable();

    bool addIf(StmtNo sNum, VarName var);
    std::vector<StmtNo> getPatternByVar(VarName var); // Gets keys
    std::vector<VarName> getPatternByNum(StmtNo sNum); // Gets values
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllAsStrings();

};

