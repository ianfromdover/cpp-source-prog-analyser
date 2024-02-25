//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_VARIABLETABLE_H
#define SPA_VARIABLETABLE_H


#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class VariableTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    VariableTable() = default;

    bool addVariable(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getVariable();
};

#endif //SPA_VARIABLETABLE_H
