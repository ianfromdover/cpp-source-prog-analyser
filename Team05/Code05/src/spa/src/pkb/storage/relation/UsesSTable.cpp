#include "UsesSTable.h"

bool UsesSTable::addUsesS(StmtNo sNum, VarName name) {
    return map.insert(sNum, name);
}

vector<VarName> UsesSTable::getUsesBySNum(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<StmtNo> UsesSTable::getUsesByVar(VarName name) {
    return map.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllAsStrings() {
    return map.getAllForAStr();
}
