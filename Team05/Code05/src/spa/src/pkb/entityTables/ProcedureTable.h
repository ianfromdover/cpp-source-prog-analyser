#pragma once
#define SPA_PROCEDURETABLE_H

#include <vector>
#include "utilSpa/SpaTypes.h"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class ProcedureTable {
private:
    vector<ProcName> procList;
public:
    ProcedureTable();
    bool addProc(ProcName name);
    bool hasProc(ProcName name);
    vector<ProcName> getAllProcs();
    [[nodiscard]] int getSize() const;
};
