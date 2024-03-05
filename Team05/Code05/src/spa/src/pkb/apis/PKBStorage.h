//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PKBSTORAGE_H
#define SPA_PKBSTORAGE_H
#include <memory>
#include "pkb/storage/entity/ReadTable.h"
#include "pkb/storage/entity/CallTable.h"
#include "pkb/storage/entity/IfTable.h"
#include "pkb/storage/entity/WhileTable.h"
#include "pkb/storage/entity/PrintTable.h"
#include "pkb/storage/entity/StatementTable.h"
#include "pkb/storage/entity/ProcedureTable.h"
#include "pkb/storage/entity/VariableTable.h"
#include "pkb/storage/entity/ConstantTable.h"
#include "pkb/storage/relation/FollowsTable.h"
#include "pkb/storage/relation/FollowsTTable.h"
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

class PKBStorage {
public:
    PKBStorage() = default;
    std::shared_ptr<ReadTable> readTable = std::make_shared<ReadTable>();
    std::shared_ptr<CallTable> callTable = std::make_shared<CallTable>();
    std::shared_ptr<IfTable> ifTable = std::make_shared<IfTable>();
    std::shared_ptr<WhileTable> whileTable = std::make_shared<WhileTable>();
    std::shared_ptr<PrintTable> printTable = std::make_shared<PrintTable>();
    std::shared_ptr<StatementTable> statementTable = std::make_shared<StatementTable>();
    std::shared_ptr<ProcedureTable> procedureTable = std::make_shared<ProcedureTable>();
    std::shared_ptr<VariableTable> variableTable = std::make_shared<VariableTable>();
    std::shared_ptr<ConstantTable> constantTable = std::make_shared<ConstantTable>();
    std::shared_ptr<AssignTable> assignTable = std::make_shared<AssignTable>();

    std::shared_ptr<FollowsTable> followsTable = std::make_shared<FollowsTable>();
    std::shared_ptr<FollowsTTable> followsTTable = std::make_shared<FollowsTTable>();
    std::shared_ptr<ParentTable> parentTable = std::make_shared<ParentTable>();
    std::shared_ptr<ParentTTable> parentTTable = std::make_shared<ParentTTable>();
    std::shared_ptr<ModifiesSTable> modifiesSTable = std::make_shared<ModifiesSTable>();
    std::shared_ptr<ModifiesPTable> modifiesPTable = std::make_shared<ModifiesPTable>();
    std::shared_ptr<UsesSTable> usesSTable = std::make_shared<UsesSTable>();
    std::shared_ptr<UsesPTable> usesPTable = std::make_shared<UsesPTable>();
    std::shared_ptr<CallsTable> callsTable = std::make_shared<CallsTable>();
    std::shared_ptr<CallsTTable> callsTTable = std::make_shared<CallsTTable>();

};

#endif //SPA_PKBSTORAGE_H
