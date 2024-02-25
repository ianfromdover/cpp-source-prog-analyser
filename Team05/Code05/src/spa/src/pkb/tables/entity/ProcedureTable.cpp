//
// Created by sjh_9 on 25/2/2024.
//

#include "ProcedureTable.h"

bool ProcedureTable::addProcedure(const std::string& name, const std::string& nameCopy) {
    table.first.addString(name);
    table.second.addString(nameCopy);
    return true;
}

std::pair<StringColumn, StringColumn> ProcedureTable::getProcedure() {
    return table;
}