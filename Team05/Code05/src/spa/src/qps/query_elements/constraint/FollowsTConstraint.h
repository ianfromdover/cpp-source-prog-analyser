//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_FOLLOWSTCONSTRAINT_H
#define SPA_FOLLOWSTCONSTRAINT_H


#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"
#include "common/Column.h"
#include "pkb/apis/QueryPKB.h"

class FollowsTConstraint : public RelationshipConstraint{
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    FollowsTConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<StatementReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;

    string &stripCharacters(string &str, const string &chars);

    bool isStatementSynonym(string type);

};



#endif //SPA_FOLLOWSTCONSTRAINT_H
