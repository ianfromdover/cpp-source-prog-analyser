#pragma once
#define SPA_PKB_H

#include <string>
#include <vector>
#include "pkb/constraintTables/ParentTable.h"

using namespace std;

/**
 * Stores all the relationship and entity tables.
 * TODO: Rename to PKBStorage
 */
class PKBStorage {
private:
public:
    PKBStorage();

    std::unique_ptr<ParentTable> parentTable;
};
