#include "pkb/storage/ian_entity/StatementTable.h"

StatementTable::StatementTable() {}

bool StatementTable::addFinalStatementNo(StmtNo sNum) {
    finalStatementNum = sNum;
    return true;
}

vector<StmtNo> StatementTable::getAllStmts() {
    vector<StmtNo> stmts;
    for (int i = 1; i < finalStatementNum; i++) {
        stmts.push_back(i);
    }
    return stmts;
}
