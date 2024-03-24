#include "PatternWhileTable.h"

PatternWhileTable::PatternWhileTable() = default;

bool PatternWhileTable::addWhile(StmtNo sNum, VarName var) {
    return map.insert(sNum, std::move(var));
}

vector<StmtNo> PatternWhileTable::getPatternByVar(VarName var) {
    return map.getKeys(std::move(var));
}
vector<VarName> PatternWhileTable::getPatternByNum(StmtNo sNum) {
    return map.getValues(sNum);
}

Table PatternWhileTable::getWhileNums() {
    return map.getFirstColA();
}

Table PatternWhileTable::getAllAsStrings() {
    return map.getAllForAStr();
}
