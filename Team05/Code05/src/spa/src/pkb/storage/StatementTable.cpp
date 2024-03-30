#include "StatementTable.h"

StatementTable::StatementTable() {}

bool StatementTable::addFinalStatementNo(StmtNo sNum) {
    finalStatementNum = sNum;
    return true;
}

Table StatementTable::getAll() {
    Table stmts;
  for (int i = 1; i <= finalStatementNum; i++) {
    stmts.push_back({to_string(i)});
    }
    return stmts;
}
