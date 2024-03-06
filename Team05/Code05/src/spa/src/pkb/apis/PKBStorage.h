//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PKBSTORAGE_H
#define SPA_PKBSTORAGE_H
#include <memory>
#include "pkb/tables/entity/ReadTable.h"
#include "pkb/tables/entity/CallTable.h"
#include "pkb/tables/entity/IfTable.h"
#include "pkb/tables/entity/WhileTable.h"
#include "pkb/tables/entity/PrintTable.h"
#include "pkb/tables/entity/StatementTable.h"
#include "pkb/tables/entity/ProcedureTable.h"
#include "pkb/tables/entity/VariableTable.h"
#include "pkb/tables/entity/ConstantTable.h"
#include "pkb/tables/relation/FollowsTable.h"
#include "pkb/tables/relation/FollowsTTable.h"
#include "pkb/tables/entity/AssignTable.h"
#include "pkb/tables/relation/ParentTable.h"
#include "pkb/tables/relation/ParentTTable.h"
#include "pkb/tables/relation/ModifiesTable.h"
#include "pkb/tables/relation/UsesTable.h"
#include "pkb/tables/relation/CallsTable.h"
#include "pkb/tables/relation/CallsTTable.h"

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
    std::shared_ptr<ModifiesTable> modifiesTable = std::make_shared<ModifiesTable>();
    std::shared_ptr<UsesTable> usesTable = std::make_shared<UsesTable>();
    std::shared_ptr<CallsTable> callsTable = std::make_shared<CallsTable>();
    std::shared_ptr<CallsTTable> callsTTable = std::make_shared<CallsTTable>();

};

#endif //SPA_PKBSTORAGE_H
