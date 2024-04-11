#pragma once
#define SPA_PKBSTORAGE_H
#include <memory>

#include "pkb/storage/ProcedureTable.h"
#include "pkb/storage/StatementTable.h"

#include "pkb/storage/PatternAssignTable.h"
#include "pkb/storage/PkbTable.hpp"
#include "sp/api/NextT.h"

class Affects;

class PkbStorage {
public:
    PkbStorage() = default;
    std::shared_ptr<Affects> affects;
    std::shared_ptr<NextT> nextT;
    // entities
    std::shared_ptr<ProcedureTable> procedureTable = std::make_shared<ProcedureTable>();
    std::shared_ptr<StatementTable> statementTable = std::make_shared<StatementTable>();

    std::shared_ptr<PkbTable<StmtNo, ProcName>> callTable = std::make_shared<PkbTable<StmtNo, ProcName>>();
    std::shared_ptr<PkbTable<StmtNo, ConstVal>> constTable = std::make_shared<PkbTable<StmtNo, ConstVal>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> printTable = std::make_shared<PkbTable<StmtNo, VarName>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> readTable = std::make_shared<PkbTable<StmtNo, VarName>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> varTable = std::make_shared<PkbTable<StmtNo, VarName>>();

    // relations
    std::shared_ptr<PatternAssignTable> patternAssignTable = std::make_shared<PatternAssignTable>();

    std::shared_ptr<PkbTable<ProcName, ProcName>> callsTable = std::make_shared<PkbTable<ProcName, ProcName>>();
    std::shared_ptr<PkbTable<ProcName, ProcName>> callsTTable = std::make_shared<PkbTable<ProcName, ProcName>>();
    std::shared_ptr<PkbTable<StmtNo, StmtNo>> followsTable = std::make_shared<PkbTable<StmtNo, StmtNo>>();
    std::shared_ptr<PkbTable<StmtNo, StmtNo>> followsTTable = std::make_shared<PkbTable<StmtNo, StmtNo>>();
    std::shared_ptr<PkbTable<ProcName, VarName>> modifiesPTable = std::make_shared<PkbTable<ProcName, VarName>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> modifiesSTable = std::make_shared<PkbTable<StmtNo, VarName>>();
    std::shared_ptr<PkbTable<StmtNo, StmtNo>> nextTable = std::make_shared<PkbTable<StmtNo, StmtNo>>();
    std::shared_ptr<PkbTable<StmtNo, StmtNo>> parentTable = std::make_shared<PkbTable<StmtNo, StmtNo>>();
    std::shared_ptr<PkbTable<StmtNo, StmtNo>> parentTTable = std::make_shared<PkbTable<StmtNo, StmtNo>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> patternIfTable = std::make_shared<PkbTable<StmtNo, std::string>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> patternWhileTable = std::make_shared<PkbTable<StmtNo, std::string>>();
    std::shared_ptr<PkbTable<ProcName, VarName>> usesPTable = std::make_shared<PkbTable<ProcName, VarName>>();
    std::shared_ptr<PkbTable<StmtNo, VarName>> usesSTable = std::make_shared<PkbTable<StmtNo, VarName>>();
};