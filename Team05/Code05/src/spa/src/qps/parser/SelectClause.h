//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_SELECTCLAUSE_H
#define SPA_SELECTCLAUSE_H

#include <vector>
#include <string>
#include "Clause.h"

class SelectClause : public Clause{
public:
    SelectClause() : Clause(ClauseType::SELECT) {}

    void addSelect(const std::string&);
    std::vector<std::string> getAllSelect();
    std::vector<std::string> selectElements;

};


#endif //SPA_SELECTCLAUSE_H
