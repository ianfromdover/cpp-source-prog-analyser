//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_TUPLERETURNABLE_H
#define SPA_TUPLERETURNABLE_H


#include "Returnable.h"
#include "Entity.h"
#include "qps/query_evaluator/query_result/TupleStringResult.h"

class TupleReturnable : public Returnable {
public:
    std::vector<std::shared_ptr<Entity>> entityVector;
    void addEntityVector(std::shared_ptr<Entity>);
    std::string getReturnType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual &pkb) override;
    std::shared_ptr<Formattable> getSelectResults(QueryPkbVirtual &pkb, shared_ptr<ResultTable>, shared_ptr<ResultTable> rTable) override;
};


#endif //SPA_TUPLERETURNABLE_H
