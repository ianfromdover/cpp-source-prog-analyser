//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_USESPCONSTRAINT_H
#define SPA_USESPCONSTRAINT_H


#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"


class UsesPConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
    Table getTable(QueryPkbVirtual &pkb);
public:
    UsesPConstraint(std::shared_ptr<EntityReference> , std::shared_ptr<EntityReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPkbVirtual &) override;

    string &stripCharacters(string &str, const string &chars);

    std::size_t hash() const override;
};


#endif //SPA_USESPCONSTRAINT_H
