//
// Created by tohzh on 21/3/2024.
//

#include "TupleReturnable.h"
#include "qps/query_projector/ResultTable.h"

void TupleReturnable::addEntityVector(std::shared_ptr<Entity> e) {
    if (this->entityVector.empty()) {
        this->entityVector = std::vector<std::shared_ptr<Entity>>();
    }
    this->entityVector.push_back(e);
}

std::vector<std::vector<std::string>> TupleReturnable::getEntityTable(QueryPkbVirtual &pkb) {
    std::vector<std::vector<std::string>> result;
    ResultTable rs;
    for (std::shared_ptr<Entity> ent : entityVector) {
        std::vector<std::vector<std::string>> table = ent->getEntityTable(pkb);
        rs.add(table);
//        result.push_back(table.at(0));
    }
    return rs._table;
}

std::vector<std::string> TupleReturnable::getArgumentValue() {
    std::vector<std::string> result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        //we assume that there will not be tuples in a tuple; all entities will therefore only have one argValue
        std::string val = entityVector.at(i)->getArgumentValue()[0];
        result.push_back(val);
    }
    return result;
}

std::string TupleReturnable::toString() {
    std::string result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        result += entityVector.at(i)->toString();
        if (i < entityVector.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

std::string TupleReturnable::getReturnType() {
    std::string result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        result += entityVector.at(i)->getReturnType();
        if (i < entityVector.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

std::shared_ptr<Formattable> TupleReturnable::getSelectResults(QueryPkbVirtual &pkb, shared_ptr<ResultTable> rTable, shared_ptr<ResultTable> resultTable) {
    std::vector<vector<string>> val = rTable->getDistinctColumns(getArgumentValue());
    std::shared_ptr<TupleStringResult> sd = std::make_shared<TupleStringResult>(val);
    return sd;
}
