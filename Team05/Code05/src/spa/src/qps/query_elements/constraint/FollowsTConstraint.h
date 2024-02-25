//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_FOLLOWSTCONSTRAINT_H
#define SPA_FOLLOWSTCONSTRAINT_H


#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "utilSpa/Column.h"

class FollowsTConstraint : public RelationshipConstraint{
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    FollowsTConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<StatementReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::pair<Column<std::string>,Column<std::string>> getRelationshipTable() override;
};



#endif //SPA_FOLLOWSTCONSTRAINT_H
