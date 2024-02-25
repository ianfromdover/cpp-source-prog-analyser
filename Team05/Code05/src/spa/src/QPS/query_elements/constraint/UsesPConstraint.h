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
public:
    UsesPConstraint(std::shared_ptr<EntityReference> , std::shared_ptr<EntityReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::pair<Column<std::string>,Column<std::string>> getRelationshipTable() override;
};


#endif //SPA_USESPCONSTRAINT_H
