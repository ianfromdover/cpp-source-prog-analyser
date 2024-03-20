#pragma once
#define SPA_CONSTTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the const values statements and the corresponding stmtNos that are in the program.
 */
class ConstTable {
private:
    TwoSideMap<StmtNo, ConstVal> map;
public:
    ConstTable();
    // Adds a constant to the table, returns false if it already exists
    bool addConst(StmtNo sNum, ConstVal value);
    // Returns the statement numbers that the constants are on
    vector<StmtNo> getConstStmts(ConstVal value);
    // Returns the constant values by the statement number, if the constant is not found, returns empty vector
    vector<ConstVal> getConsts(StmtNo sNum);
    // Returns all the constants as strings in 1 column: ConstVal
    Table getConsts();
    // Returns all the constants as strings in 2 columns: StmtNo | ConstVal
    Table getAllAsStrings();
};
