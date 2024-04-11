//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_RETURNABLE_H
#define SPA_RETURNABLE_H
#include <string>
#include "pkb/apis/QueryPkbVirtual.h"
#include "qps/query_projector/Formattable.h"
#include "qps/query_projector/ResultTable.h"


class Returnable {
public:
    virtual std::string getReturnType() = 0;
    virtual std::string toString() = 0;
    virtual std::vector<std::string> getArgumentValue() = 0;
    virtual Table getEntityTable(QueryPkbVirtual &pkb) = 0;
    /**
     * used by queryEvaluator to get return result
     * @param pkb pkb interface
     * @param rTable either the select table or return table
     * @param resultTable result table (for use in boolean)
     * @return
     */
    virtual std::shared_ptr<Formattable> getSelectResults(QueryPkbVirtual &pkb, shared_ptr<ResultTable> rTable, shared_ptr<ResultTable> resultTable) = 0;
};


#endif //SPA_RETURNABLE_H
