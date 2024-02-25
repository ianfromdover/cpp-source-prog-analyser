//
// Created by sjh_9 on 25/2/2024.
//

#include "WhileTable.h"

bool WhileTable::addWhile(int stmtNo, const std::string& name) {
    table.first.addInt(stmtNo);
    table.second.addString(name);
    return true;
}

std::pair<IntColumn, StringColumn> WhileTable::getWhile() {
    return table;
}
