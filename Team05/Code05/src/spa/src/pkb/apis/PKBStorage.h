#pragma once
#define SPA_PKBSTORAGE_H
#include <memory>
//#include "pkb/storage/entity/ReadTable.h"
//#include "pkb/storage/entity/CallTable.h"
//#include "pkb/storage/entity/IfTable.h"
//#include "pkb/storage/entity/WhileTable.h"
//#include "pkb/storage/entity/PrintTable.h"
//#include "pkb/storage/entity/StatementTable.h"
//#include "pkb/storage/entity/ProcedureTable.h"
//#include "pkb/storage/entity/VariableTable.h"
//#include "pkb/storage/entity/ConstantTable.h"
//#include "pkb/storage/relation/FollowsTable.h"
//#include "pkb/storage/relation/FollowsTTable.h"
#include "pkb/storage/entity/AssignTable.h"
#include "pkb/storage/relation/ParentTable.h"
#include "pkb/storage/relation/ParentTTable.h"
#include "pkb/storage/relation/ModifiesTable.h"
#include "pkb/storage/relation/UsesTable.h"
#include "pkb/storage/relation/ModifiesSTable.h"
#include "pkb/storage/relation/ModifiesPTable.h"
#include "pkb/storage/relation/UsesSTable.h"
#include "pkb/storage/relation/UsesPTable.h"
#include "pkb/storage/relation/CallsTable.h"
#include "pkb/storage/relation/CallsTTable.h"

#include "pkb/storage/ian_entity/CallTable.h"
#include "pkb/storage/ian_entity/ConstTable.h"
#include "pkb/storage/ian_entity/IfTable.h"
#include "pkb/storage/ian_entity/PrintTable.h"
#include "pkb/storage/ian_entity/ProcedureTable.h"
#include "pkb/storage/ian_entity/ReadTable.h"
#include "pkb/storage/ian_entity/StatementTable.h"
#include "pkb/storage/ian_entity/VarTable.h"
#include "pkb/storage/ian_entity/WhileTable.h"

#include "pkb/storage/ian_relation/AffectsTable.h"
#include "pkb/storage/ian_relation/CallsTable.h"
#include "pkb/storage/ian_relation/CallsTTable.h"
#include "pkb/storage/ian_relation/FollowsTable.h"
#include "pkb/storage/ian_relation/FollowsTTable.h"
#include "pkb/storage/ian_relation/ModifiesPTable.h"
#include "pkb/storage/ian_relation/ModifiesSTable.h"
#include "pkb/storage/ian_relation/NextTable.h"
#include "pkb/storage/ian_relation/NextTTable.h"
#include "pkb/storage/ian_relation/ParentTable.h"
#include "pkb/storage/ian_relation/ParentTTable.h"
#include "pkb/storage/ian_relation/PatternAssignTable.h"
#include "pkb/storage/ian_relation/PatternIfTable.h"
#include "pkb/storage/ian_relation/PatternWhileTable.h"
#include "pkb/storage/ian_relation/UsesPTable.h"
#include "pkb/storage/ian_relation/UsesSTable.h"

class PKBStorage {
public:
    PKBStorage() = default;
    // entities
    std::shared_ptr<CallTable> callTable = std::make_shared<CallTable>();
    std::shared_ptr<ConstTable> constTable = std::make_shared<ConstTable>();
    std::shared_ptr<IfTable> ifTable = std::make_shared<IfTable>();
    std::shared_ptr<PrintTable> printTable = std::make_shared<PrintTable>();
    std::shared_ptr<ProcedureTable> procedureTable = std::make_shared<ProcedureTable>();
    std::shared_ptr<ReadTable> readTable = std::make_shared<ReadTable>();
    std::shared_ptr<StatementTable> statementTable = std::make_shared<StatementTable>();
    std::shared_ptr<VarTable> varTable = std::make_shared<VarTable>();
    std::shared_ptr<WhileTable> whileTable = std::make_shared<WhileTable>();

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
    // std::shared_ptr<UsesPTable> usesPTable = std::make_shared<UsesPTable>(); // not yet implemented
    std::shared_ptr<PatternAssignTable> patternAssignTable = std::make_shared<PatternAssignTable>();
//    std::shared_ptr<CallsTable> callsTable = std::make_shared<CallsTable>(); // bug: no include
//    std::shared_ptr<CallsTTable> callsTTable = std::make_shared<CallsTTable>(); // bug: no include
    std::shared_ptr<UsesPTable> usesPTable = std::make_shared<UsesPTable>();
    std::shared_ptr<CallsTable> callsTable = std::make_shared<CallsTable>();
    std::shared_ptr<CallsTTable> callsTTable = std::make_shared<CallsTTable>();

};
