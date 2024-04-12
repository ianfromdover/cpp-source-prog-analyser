//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_RELATIONSHIPCONSTRAINT_H
#define SPA_RELATIONSHIPCONSTRAINT_H

#include "qps/query_elements/constraint/Constraint.h"
#include "common/Column.h"

class RelationshipConstraint : public Constraint {
protected:
    string &stripCharacters(string &str, const string &chars);
    Table getFullTable(QueryPkbVirtual &pkb) override;
    Table getRelationshipTable(QueryPkbVirtual &) override;
    virtual vector<string> getDefaultHeaders() = 0;
public:
    std::string getConstraintClass() override;

    bool isDefaultHeaders(vector<std::string> header);
};


#endif //SPA_RELATIONSHIPCONSTRAINT_H
