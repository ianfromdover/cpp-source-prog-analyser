//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_WHILETABLE_H
#define SPA_WHILETABLE_H

#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class WhileTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    WhileTable() = default;

    bool addWhile(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getWhile();
};


#endif //SPA_WHILETABLE_H
