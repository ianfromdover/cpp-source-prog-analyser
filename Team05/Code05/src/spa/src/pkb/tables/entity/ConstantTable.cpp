//
// Created by sjh_9 on 25/2/2024.
//

#include "ConstantTable.h"

bool ConstantTable::addConstant(int stmtNo, int val) {
    table.first.addInt(stmtNo);
    table.second.addInt(val);
    return true;
}

std::pair<IntColumn, IntColumn> ConstantTable::getConstant() {
    return table;
}
