//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_MODIFIESPCONSTRAINT_H
#define SPA_MODIFIESPCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "qps/query_elements/constraint_argument/entity_reference/EntityReference.h"
#include "pkb/apis/QueryPkb.h"

class ModifiesPConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    ModifiesPConstraint(std::shared_ptr<EntityReference> , std::shared_ptr<EntityReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPkbVirtual &) override;
};


#endif //SPA_MODIFIESPCONSTRAINT_H
