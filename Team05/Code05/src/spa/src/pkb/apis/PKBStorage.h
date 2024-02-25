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
#include "pkb/tables/relation/Modifies.h"
#include "pkb/tables/relation/UsesTable.h"

class PKBStorage {
public:
    PKBStorage() = default;
    std::shared_ptr<ReadTable> readTable;
    std::shared_ptr<CallTable> callTable;
    std::shared_ptr<IfTable> ifTable;
    std::shared_ptr<WhileTable> whileTable;
    std::shared_ptr<PrintTable> printTable;
    std::shared_ptr<StatementTable> statementTable;
    std::shared_ptr<ProcedureTable> procedureTable;
    std::shared_ptr<VariableTable> variableTable;
    std::shared_ptr<ConstantTable> constantTable;
    std::shared_ptr<AssignTable> assignTable = std::make_shared<AssignTable>();

    std::shared_ptr<FollowsTable> followsTable;
    std::shared_ptr<FollowsTTable> followsTTable;
    std::shared_ptr<ParentTable> parentTable;
    std::shared_ptr<ParentTTable> parentTTable;
    std::shared_ptr<ModifiesTable> modifiesTable;
    std::shared_ptr<UsesTable> usesTable;

};

#endif //SPA_PKBSTORAGE_H
