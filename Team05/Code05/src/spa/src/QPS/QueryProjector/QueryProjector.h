//
// Created by Alex on 25/2/2024.
//

#ifndef SPA_QUERYPROJECTOR_H
#define SPA_QUERYPROJECTOR_H


#include <utility>
#include <vector>
#include "utilSpa/Column.h"
#include "qps/query_elements/constraint/Constraint.h"

class QueryProjector {
public:
    QueryProjector()=default;

    void mergeResults(std::vector<std::pair<Column<std::string>,Column<std::string>>>);
    std::pair<Column<std::string>, Column<std::string>> joinRhs(
            std::pair<Column<std::string>, Column<std::string>> table1,
            const std::pair<Column<std::string>, Column<std::string>>& table2, int colNo2);
    std::pair<Column<std::string>, Column<std::string>> joinLhs(
            std::pair<Column<std::string>, Column<std::string>> table1,
            const std::pair<Column<std::string>, Column<std::string>>& table2, int colNo2);
    void processConstraints(std::shared_ptr<Constraint> c);

};


#endif //SPA_QUERYPROJECTOR_H
