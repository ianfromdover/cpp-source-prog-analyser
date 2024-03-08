#include "pkb/storage/ian_entity/StatementTable.h"

StatementTable::StatementTable() {}

bool StatementTable::addFinalStatementNo(StmtNo sNum) {
    finalStatementNum = sNum;
    return true;
}
vector<StmtNo> StatementTable::getStmtByNum(StmtNo sNum) {
    return sNum > finalStatementNum ? vector<StmtNo>{} : vector<StmtNo>{sNum};
}

vector<StmtNo> StatementTable::getAllStmts() {
    vector<StmtNo> stmts;
    for (int i = 1; i < finalStatementNum; i++) {
        stmts.push_back(i);
    }
    return stmts;
}

vector<vector<Str>> StatementTable::getAllAsStrings() {
    vector<vector<Str>> stmts;
    for (int i = 1; i < finalStatementNum; i++) {
        stmts.push_back({to_string(i)});
    }
    return stmts;
}
