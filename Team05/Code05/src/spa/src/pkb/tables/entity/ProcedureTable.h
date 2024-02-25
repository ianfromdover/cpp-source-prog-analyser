//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PROCEDURETABLE_H
#define SPA_PROCEDURETABLE_H


#include "utilSpa/StringColumn.h"

class ProcedureTable  {
private:
    std::pair<StringColumn, StringColumn> table;
public:
    ProcedureTable() = default;

    bool addProcedure(const std::string& name, const std::string& nameCopy);
    std::pair<StringColumn, StringColumn> getProcedure();
};


#endif //SPA_PROCEDURETABLE_H
