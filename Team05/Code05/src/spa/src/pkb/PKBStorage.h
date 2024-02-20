#pragma once
#define SPA_PKBSTORAGE_H

#include <string>
#include <vector>
#include "pkb/constraintTables/ParentTable.h"
#include "pkb/constraintTables/FollowsTable.h"

using namespace std;

/**
 * Stores all the relationship and entity tables.
 */
class PKBStorage {
private:
public:
    PKBStorage();

    std::unique_ptr<ParentTable> parentTable;
    std::unique_ptr<FollowsTable> followsTable;
};
