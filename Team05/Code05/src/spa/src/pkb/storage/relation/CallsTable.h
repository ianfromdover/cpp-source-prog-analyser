#pragma once
#define SPA_CALLSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class CallsTable {
private:
    TwoSideMap<ProcName, ProcName> map;
public:
    CallsTable();
    // Adds a calls relationship, returns true if the relationship is added
    bool addCalls(ProcName caller, ProcName called);
    // Returns a list of callers of this procedure, unsorted. Returns an empty list if it does not exist
    std::vector<ProcName> getCallers(ProcName called);
    // Returns a list of procedures this one calls, unsorted. Returns an empty list if it does not exist
    std::vector<ProcName> getCalled(ProcName caller);
    // Gets a table with 2 columns, Caller | Called
    std::vector<std::vector<Str>> getAllAsStrings();
};
