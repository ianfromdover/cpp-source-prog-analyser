//
// Created by tohzh on 10/2/2024.
//

#ifndef SPA_PARENTCONSTRAINT_H
#define SPA_PARENTCONSTRAINT_H

#include "RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementReference.h"

class ParentConstraint : public RelationshipConstraint {
private:
    std::vector<std::shared_ptr<ConstraintArgument>> constraintArguments;
public:
    ParentConstraint(std::shared_ptr<StatementReference> , std::shared_ptr<StatementReference> );
    std::string getConstraintType() override;
    std::vector<std::shared_ptr<ConstraintArgument>> getConstraintArguments() override;
    std::vector<std::vector<std::string>> getRelationshipTable(QueryPKBVirtual &) override;

    string &stripCharacters(string &str, const string &chars);

    bool isStatementSynonym(string type);
};


#endif //SPA_PARENTCONSTRAINT_H
