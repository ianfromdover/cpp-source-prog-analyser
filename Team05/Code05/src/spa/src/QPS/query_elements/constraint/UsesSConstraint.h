//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_USESSCONSTRAINT_H
#define SPA_USESSCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "pkb/apis/QueryPKB.h"


class UsesSConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    UsesSConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<EntityReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;

    string &stripCharacters(string &str, const string &chars);

    bool isStatementSynonym(string type);
};


#endif //SPA_USESSCONSTRAINT_H
