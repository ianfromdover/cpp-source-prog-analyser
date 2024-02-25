//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_CALLTABLE_H
#define SPA_CALLTABLE_H

#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class CallTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    CallTable() = default;

    bool addCall(int stmtNo, const std::string &name);

    std::pair<IntColumn, StringColumn> getCall();
};


#endif //SPA_CALLTABLE_H
