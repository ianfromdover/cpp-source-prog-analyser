#pragma once
#define SPA_PROCEDURETABLE_H

#include "common/SpaTypes.h"

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
    bool add(ProcName name);
    // Returns all the procedure names
    Table getAll();
};
