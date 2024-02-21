#pragma once
#define SPA_PKBSTORAGE_H

#include <string>
#include <vector>
#include "pkb/constraintTables/FollowsTable.h"
 #include "pkb/constraintTables/FollowsTTable.h"
#include "pkb/constraintTables/ParentTable.h"
// #include "pkb/constraintTables/ParentTTable.h"
#include "pkb/constraintTables/UsesTable.h"
// #include "pkb/constraintTables/ModifiesTable.h"
// #include "pkb/constraintTables/AssignPatternTable.h"

// for milestone 2:
// #include "pkb/constraintTables/IfPatternTable.h"
// #include "pkb/constraintTables/WhilePatternTable.h"
// #include "pkb/constraintTables/CallsTable.h"
// #include "pkb/constraintTables/CallsTTable.h"
// #include "pkb/constraintTables/NextTable.h"
// #include "pkb/constraintTables/NextTTable.h"
// #include "pkb/constraintTables/AffectsTable.h"

using namespace std;

/**
 * Stores all the relationship and entity tables.
 */
class PKBStorage {
private:
public:
    PKBStorage();

    std::unique_ptr<FollowsTable> followsTable;
    std::unique_ptr<FollowsTTable> followsTTable;
    std::unique_ptr<ParentTable> parentTable;
    // std::unique_ptr<ParentTTable> parentTTable;
    std::unique_ptr<UsesTable> usesTable;
    // std::unique_ptr<ModifiesTable> modifiesTable;
    // std::unique_ptr<AssignPatternTable> assignPatternTable;

    // ai-gen start (copilot, 0, e)
    // prompt: used copilot
    // for milestone 2:
    // declare all the other tables here
    // std::unique_ptr<IfPatternTable> ifPatternTable;
    // std::unique_ptr<WhilePatternTable> whilePatternTable;
    // std::unique_ptr<CallsTable> callsTable;
    // std::unique_ptr<CallsTTable> callsTTable;
    // std::unique_ptr<NextTable> nextTable;
    // std::unique_ptr<NextTTable> nextTTable;
    // std::unique_ptr<AffectsTable> affectsTable;
    // ai-gen end
};
