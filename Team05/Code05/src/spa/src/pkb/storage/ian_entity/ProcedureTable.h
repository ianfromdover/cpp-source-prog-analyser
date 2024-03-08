#pragma once
#define SPA_PROCEDURETABLE_H

#include <vector>
#include "utilSpa/SpaTypes.h"

/**
 * Stores the procedures in the program.
 */
class ProcedureTable {
private:
    vector<ProcName> procList;

    bool contains(ProcName name);

public:
    ProcedureTable();
    // Adds a procedure name to the table, returns false if it already exists
    bool addProc(ProcName name);
    // Returns all the procedure names
    vector<Str> getProcByName(ProcName name);
    // Returns all the procedure names
    vector<vector<Str>> getAllAsStrings();
};
