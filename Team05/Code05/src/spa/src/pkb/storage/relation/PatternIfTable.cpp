#include "PatternIfTable.h"

PatternIfTable::PatternIfTable() = default;

bool PatternIfTable::addIf(StmtNo sNum, VarName var) {
    return map.insert(sNum, std::move(var));
}
vector<StmtNo> PatternIfTable::getPatternByVar(VarName var) {
    return map.getKeys(std::move(var));
}
vector<VarName> PatternIfTable::getPatternByNum(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<vector<Str>> PatternIfTable::getAllAsStrings() {
    return map.getAllForAStr();
}
