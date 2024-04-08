//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_CONSTRAINT_H
#define SPA_CONSTRAINT_H

#include <string>
#include <vector>
#include <memory>
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"
#include "qps/query_elements/QueryEnums.h"
#include "common/SpaTypes.h"
#include "pkb/apis/QueryPkb.h"

class QueryPkbVirtual;

class Constraint {
private:
    bool isNot = false;
public:
    int priority = 0; // Used in constraint ordering for optimization
    virtual std::string getConstraintClass() = 0;
    virtual std::string getConstraintType() = 0;
    virtual std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() = 0;
    std:: string toString();
    virtual Table getRelationshipTable(QueryPkbVirtual &) =0;
    void setNot(bool val) {
        this->isNot = val;
    }
    bool getNot() {
        return this->isNot;
    }

    virtual std::size_t hash() const = 0;

};


#endif //SPA_CONSTRAINT_H
