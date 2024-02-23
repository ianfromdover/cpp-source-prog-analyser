//
// Created by yewme on 22/2/2024.
//

#include "ModifiesTable.h"

ModifiesTable::ModifiesTable() = default;

//// ModifiesRe
//bool ModifiesTable::addModifiesRe(StmtNo stmtNo, VarName varName) {
//    if (isModifiesRe(stmtNo, varName)) {
//        return false;
//    }
//    return twoSideMapOMRead.insert(parent, child);
//}
//
//bool ModifiesTable::isModifiesRe(StmtNo parent, StmtNo child) {
//    if (!twoSideMapOMRead.containsKey(parent)
//        || !twoSideMapOMRead.containsValue(child)) {
//        return false;
//    }
//    return twoSideMapOMRead.getKey(child).value() == parent;
//}
//
//bool ModifiesTable::hasModifiesRe(StmtNo child) {
//    return twoSideMapOMRead.getKey(child).has_value();
//}
//
//bool ModifiesTable::hasModifiesRe(StmtNo parent) {
//    return twoSideMapOMRead.containsKey(parent);
//}
//
//StmtNo ModifiesTable::getModifiersRe(VarName varName) {
//    auto k = twoSideMapOMRead.getKey(varName);
//    if (!k.has_value()) {
//        return -1;
//    }
//    return k.value();
//}
//
//vector<VarName> ModifiesTable::getModifiedRe(StmtNo stmtNo) {
//    return twoSideMapOMRead.getValues(stmtNo);
//}
//
//int ModifiesTable::getSizeRe() const {
//    return twoSideMapOMRead.size();
//}

// ModifiesS
// Since there are many different types of ModifiesS, we can just if else in the queryModifies in QueryPKB
bool ModifiesTable::addModifiesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo, VarName varName) {
    if (isModifiesS(map, stmtNo, varName)) {
        return false;
    }
    return map.insert(stmtNo, varName);
}

bool ModifiesTable::isModifiesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo, VarName varName) {
    if (!map.containsKey(stmtNo)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = map.getKeys(varName);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), stmtNo) != keyValues.end();
}

bool ModifiesTable::hasModifiersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName varName) {
    return !map.getKeys(varName).empty();
}

bool ModifiesTable::hasModifiedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo) {
    return map.containsKey(stmtNo);
}

std::vector<StmtNo> ModifiesTable::getModifiersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName varName) {
    auto k = map.getKeys(varName);
    if (k.empty()) {
        return {};
    }
    return k;
}

std::vector<VarName> ModifiesTable::getModifiedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo) {
    return map.getValues(stmtNo);
}

int ModifiesTable::getSizeS(TwoSideMapManyMany<StmtNo, VarName> map) const {
    return map.size();
}

// ProcName map

bool ModifiesTable::addModifiesP(ProcName procName, VarName varName) {
    if (isModifiesP(procName, varName)) {
        return false;
    }
    return procNameMap.insert(procName, varName);
}

bool ModifiesTable::isModifiesP(ProcName procName, VarName varName) {
    if (!procNameMap.containsKey(procName)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = procNameMap.getKeys(varName);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<ProcName>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), procName) != keyValues.end();
}

bool ModifiesTable::hasModifiersP(VarName varName) {
    return !procNameMap.getKeys(varName).empty();
}

bool ModifiesTable::hasModifiedP(ProcName procName) {
    return procNameMap.containsKey(procName);
}

std::vector<ProcName> ModifiesTable::getModifiersP(VarName varName) {
    auto k = procNameMap.getKeys(varName);
    if (k.empty()) {
        return {};
    }
    return k;
}

vector<VarName> ModifiesTable::getModifiedP(ProcName procName) {
    return procNameMap.getValues(procName);
}

int ModifiesTable::getSizeP() const {
    return procNameMap.size();
}

TwoSideMapManyMany<StmtNo, VarName> ModifiesTable::getReadMap() {
    return readMap;
}

TwoSideMapManyMany<StmtNo, VarName> ModifiesTable::getAssignMap() {
    return assignMap;
}

TwoSideMapManyMany<StmtNo, VarName> ModifiesTable::getCallMap() {
    return callMap;
}

TwoSideMapManyMany<StmtNo, VarName> ModifiesTable::getIfContainerMap() {
    return ifContainerMap;
}

TwoSideMapManyMany<StmtNo, VarName> ModifiesTable::getWhileContainerMap() {
    return whileContainerMap;
}


