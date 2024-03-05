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
public:
    ProcedureTable();
    bool addProc(ProcName name);
    bool hasProc(ProcName name);
    vector<ProcName> getAllProcs();
    [[nodiscard]] int getSize() const;
};
