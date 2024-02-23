//
// Created by yewme on 23/2/2024.
//

#include "UsesTable.h"

// UsesS
bool UsesTable::addUsesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used) {
    if (isUsesS(map, user, used)) {
        return false;
    }
    return map.insert(user, used);
}

bool UsesTable::isUsesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used) {
    if (!map.containsKey(user)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = map.getKeys(used);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), user) != keyValues.end();
}

bool UsesTable::hasUsersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName used) {
    return !map.getKeys(used).empty();
}

bool UsesTable::hasUsedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user) {
    return map.containsKey(user);
}

std::vector<StmtNo> UsesTable::getUsersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName used) {
    auto k = map.getKeys(used);
    if (k.empty()) {
        return {};
    }
    return k;
}

std::vector<VarName> UsesTable::getUsedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user) {
    return map.getValues(user);
}

int UsesTable::getSizeS(TwoSideMapManyMany<StmtNo, VarName> map) const {
    return map.size();
}

// UsesP
bool UsesTable::addUsesP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used) {
    if (isUsesS(map, user, used)) {
        return false;
    }
    return map.insert(user, used);
}

bool UsesTable::isUsesP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used) {
    if (!map.containsKey(user)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = map.getKeys(used);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), user) != keyValues.end();
}

bool UsesTable::hasUsersP(TwoSideMapManyMany<StmtNo, VarName> map, VarName used) {
    return !map.getKeys(used).empty();
}

bool UsesTable::hasUsedP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user) {
    return map.containsKey(user);
}

std::vector<StmtNo> UsesTable::getUsersP(TwoSideMapManyMany<StmtNo, VarName> map, VarName used) {
    auto k = map.getKeys(used);
    if (k.empty()) {
        return {};
    }
    return k;
}

std::vector<VarName> UsesTable::getUsedP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user) {
    return map.getValues(user);
}

int UsesTable::getSizeP(TwoSideMapManyMany<StmtNo, VarName> map) const {
    return map.size();
}

// UsesPrint
bool UsesTable::addUsesPrint(VarName used, StmtNo user) {
    if (isUsesPrint(used, user)) {
        return false;
    }
    return printMap.insert(used, user);
}

bool UsesTable::isUsesPrint(VarName used, StmtNo user) {
    if (!printMap.containsKey(used)
        || !printMap.containsValue(user)) {
        return false;
    }
    return printMap.getKey(user).value() == used;
}

bool UsesTable::hasUsedPrint(StmtNo user) {
    return printMap.getKey(user).has_value();
}

bool UsesTable::hasUserPrint(VarName used) {
    return printMap.containsKey(used);
}

VarName UsesTable::getUsedPrint(StmtNo user) {
    auto k = printMap.getKey(user);
    if (!k.has_value()) {
        return "-1";
    }
    return k.value();
}

vector<StmtNo> UsesTable::getUserPrint(VarName user) {
    return printMap.getValues(user);
}

int UsesTable::getSizePrint() const {
    return printMap.size();
}
