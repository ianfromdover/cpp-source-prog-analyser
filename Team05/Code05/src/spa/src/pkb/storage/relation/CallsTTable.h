#pragma once
#define SPA_CALLSTTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class CallsTTable {
private:
    TwoSideMap<ProcName, ProcName> map;
public:
    CallsTTable();
    // Adds a calls relationship, returns true if the relationship is added
    bool addCallsT(ProcName caller, ProcName called);
    // Returns a list of callers T of this procedure, unsorted. Returns an empty list if it does not exist
    std::vector<ProcName> getCallersT(ProcName called);
    // Returns a list of procedures this one calls recursively, unsorted. Returns an empty list if it does not exist
    std::vector<ProcName> getCalledT(ProcName caller);
    // Gets a table with 2 columns, Caller* | Called*
    std::vector<std::vector<Str>> getAllAsStrings();
};
