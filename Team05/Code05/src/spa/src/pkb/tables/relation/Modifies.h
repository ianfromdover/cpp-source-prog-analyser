//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_MODIFIES_H
#define SPA_MODIFIES_H


#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class ModifiesTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    ModifiesTable() = default;

    bool addModifies(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getModifies();
};

#endif //SPA_MODIFIES_H
