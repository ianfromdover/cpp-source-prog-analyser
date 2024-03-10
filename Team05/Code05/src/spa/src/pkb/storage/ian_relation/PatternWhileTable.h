#pragma once
#define SPA_PATTERN_WHILE_TABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class PatternWhileTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    PatternWhileTable();

    bool addWhile(StmtNo sNum, VarName var);
    std::vector<StmtNo> getPatternByVar(VarName var); // Gets keys
    std::vector<VarName> getPatternByNum(StmtNo sNum); // Gets values
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllAsStrings();

};

