#include <string>
#include <algorithm>
#include "ProcedureTable.h"

ProcedureTable::ProcedureTable() = default;

bool ProcedureTable::contains(ProcName name) {
    return std::find(procList.begin(), procList.end(), name) != procList.end();
}

bool ProcedureTable::add(ProcName name) {
    if (contains(name)) {
        return false;
    }
    procList.push_back(name);
    return true;
}

Table ProcedureTable::getAll() {
    Table stmts;
    for (auto name : procList) {
        stmts.push_back({name});
    }
    return stmts;
}
