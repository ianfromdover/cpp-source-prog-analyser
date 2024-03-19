#include "CallsTTable.h"

CallsTTable::CallsTTable() = default;
bool CallsTTable::addCallsT(ProcName caller, ProcName called) {
    return map.insert(caller, called);
}

std::vector<ProcName> CallsTTable::getCallersT(ProcName called) {
    return map.getKeys(called);
}

std::vector<ProcName> CallsTTable::getCalledT(ProcName caller) {
    return map.getValues(caller);
}

Table CallsTTable::getAllAsStrings() {
    return map.getAllForStrStr();
}
