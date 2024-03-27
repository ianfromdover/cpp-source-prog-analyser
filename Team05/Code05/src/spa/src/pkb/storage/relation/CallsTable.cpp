#include "CallsTable.h"

CallsTable::CallsTable() = default;
bool CallsTable::addCalls(ProcName caller, ProcName called) {
    return map.insert(caller, called);
}

std::vector<ProcName> CallsTable::getCallers(ProcName called) {
    return map.getKeys(called);
}

std::vector<ProcName> CallsTable::getCalled(ProcName caller) {
    return map.getValues(caller);
}

Table CallsTable::getAllAsStrings() {
    return map.getAllForStrStr();
}
