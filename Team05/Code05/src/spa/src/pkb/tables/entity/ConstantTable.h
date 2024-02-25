//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_CONSTANTTABLE_H
#define SPA_CONSTANTTABLE_H


#include "utilSpa/IntColumn.h"

class ConstantTable  {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    ConstantTable() = default;

    bool addConstant(int stmtNo, int val);
    std::pair<IntColumn, IntColumn> getConstant();
};


#endif //SPA_CONSTANTTABLE_H
