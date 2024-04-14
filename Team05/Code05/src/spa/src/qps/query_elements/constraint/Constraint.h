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
#include "qps/query_projector/ResultTable.h"

class QueryPkbVirtual;

class Constraint {
private:
    bool isNot = false;
protected:
    virtual Table getFullTable(QueryPkbVirtual &pkb) = 0;
    virtual Table getTable(QueryPkbVirtual &pkb) = 0;
    virtual Table getTableWithDefaultHeadersFromPkb(QueryPkbVirtual &pkb) = 0 ;
    bool isStatementSynonym(std::string type);
    bool isEntitySynonym(std::string type);
    bool isStatementOrEntitySynonym(string type);
    static inline const std::vector<std::string> defaultHeaders = {
        HEADER_ASSIGNLHS, HEADER_ASSIGNRHS,
        HEADER_IFPATTERN, HEADER_WHILEPATTERN,
        HEADER_CALLSLHS, HEADER_CALLSRHS,
        HEADER_CALLSTLHS, HEADER_CALLSTRHS,
        HEADER_FOLLOWSLHS, HEADER_FOLLOWSRHS,
        HEADER_FOLLOWSTLHS, HEADER_FOLLOWSTRHS,
        HEADER_MODIFIESTLHS, HEADER_MODIFIESTRHS,
        HEADER_MODIFIESSLHS, HEADER_MODIFIESSRHS,
        HEADER_PARENTLHS, HEADER_PARENTRHS,
        HEADER_PARENTTLHS, HEADER_PARENTTRHS,
        HEADER_USESPLHS, HEADER_USESPRHS,
        HEADER_USESSLHS, HEADER_USESSRHS,
        HEADER_AFFECTSLHS, HEADER_AFFECTSRHS,
        HEADER_NEXTLHS, HEADER_NEXTRHS,
        HEADER_NEXTTLHS, HEADER_NEXTTRHS,
        HEADER_ENT_CONSTANTLHS,
        HEADER_ENT_ASSIGNRHS,
        HEADER_ENT_CALLRHS,
        HEADER_ENT_IFRHS,
        HEADER_ENT_PRINTRHS,
        HEADER_ENT_READRHS,
    };
public:
    int priority = 0; // Used in constraint ordering for optimization
    virtual std::string getConstraintClass() = 0;
    virtual std::string getConstraintType() = 0;
    virtual Table getRelationshipTable(QueryPkbVirtual &) = 0;
    virtual std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() = 0;
    std:: string toString();
    bool getNot();
    virtual std::size_t hash() const = 0;
    void setNot(bool val);
    void removeHeaders(shared_ptr<ResultTable> table);
    void removeHeaders(vector<std::string> toRemove,
                       shared_ptr<ResultTable> table);
};


#endif //SPA_CONSTRAINT_H
