#pragma once
#define SPA_PKBSTORAGE_H
#include <memory>

#include "pkb/storage/entity/CallTable.h"
#include "pkb/storage/entity/ConstTable.h"
#include "pkb/storage/entity/PrintTable.h"
#include "pkb/storage/entity/ProcedureTable.h"
#include "pkb/storage/entity/ReadTable.h"
#include "pkb/storage/entity/StatementTable.h"
#include "pkb/storage/entity/VarTable.h"

#include "pkb/storage/relation/AffectsTable.h"
#include "pkb/storage/relation/CallsTable.h"
#include "pkb/storage/relation/CallsTTable.h"
#include "pkb/storage/relation/FollowsTable.h"
#include "pkb/storage/relation/FollowsTTable.h"
#include "pkb/storage/relation/ModifiesPTable.h"
#include "pkb/storage/relation/ModifiesSTable.h"
#include "pkb/storage/relation/NextTable.h"
#include "pkb/storage/relation/NextTTable.h"
#include "pkb/storage/relation/ParentTable.h"
#include "pkb/storage/relation/ParentTTable.h"
#include "pkb/storage/relation/PatternAssignTable.h"
#include "pkb/storage/relation/PatternIfTable.h"
#include "pkb/storage/relation/PatternWhileTable.h"
#include "pkb/storage/relation/UsesPTable.h"
#include "pkb/storage/relation/UsesSTable.h"

class PkbStorage {
public:
    PkbStorage() = default;
    // entities
    std::shared_ptr<CallTable> callTable = std::make_shared<CallTable>();
    std::shared_ptr<ConstTable> constTable = std::make_shared<ConstTable>();
    std::shared_ptr<PrintTable> printTable = std::make_shared<PrintTable>();
    std::shared_ptr<ProcedureTable> procedureTable = std::make_shared<ProcedureTable>();
    std::shared_ptr<ReadTable> readTable = std::make_shared<ReadTable>();
    std::shared_ptr<StatementTable> statementTable = std::make_shared<StatementTable>();
    std::shared_ptr<VarTable> varTable = std::make_shared<VarTable>();

    // relations
    std::shared_ptr<AffectsTable> affectsTable = std::make_shared<AffectsTable>();
    std::shared_ptr<CallsTable> callsTable = std::make_shared<CallsTable>();
    std::shared_ptr<CallsTTable> callsTTable = std::make_shared<CallsTTable>();
    std::shared_ptr<FollowsTable> followsTable = std::make_shared<FollowsTable>();
    std::shared_ptr<FollowsTTable> followsTTable = std::make_shared<FollowsTTable>();
    std::shared_ptr<ModifiesPTable> modifiesPTable = std::make_shared<ModifiesPTable>();
    std::shared_ptr<ModifiesSTable> modifiesSTable = std::make_shared<ModifiesSTable>();
    std::shared_ptr<NextTable> nextTable = std::make_shared<NextTable>();
    std::shared_ptr<NextTTable> nextTTable = std::make_shared<NextTTable>();
    std::shared_ptr<ParentTable> parentTable = std::make_shared<ParentTable>();
    std::shared_ptr<ParentTTable> parentTTable = std::make_shared<ParentTTable>();
    std::shared_ptr<PatternAssignTable> patternAssignTable = std::make_shared<PatternAssignTable>();
    std::shared_ptr<PatternIfTable> patternIfTable = std::make_shared<PatternIfTable>();
    std::shared_ptr<PatternWhileTable> patternWhileTable = std::make_shared<PatternWhileTable>();
    std::shared_ptr<UsesPTable> usesPTable = std::make_shared<UsesPTable>();
    std::shared_ptr<UsesSTable> usesSTable = std::make_shared<UsesSTable>();
};