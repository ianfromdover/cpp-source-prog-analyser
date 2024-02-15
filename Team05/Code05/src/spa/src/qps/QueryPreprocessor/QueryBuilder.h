//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_QUERYBUILDER_H
#define SPA_QUERYBUILDER_H

#include <memory>
#include "qps/query_elements/QueryObject.h"
#include "../query_elements/constraint/RelationshipConstraint.h"
#include "qps/query_elements/constraint_argument/StatementEntity.h"


class QueryBuilder {
public:
    void addDeclaration(const std::string&, std::string);
    void addRelationshipConstraints(std::string, std::string, std::string);
    void addReturnType(std::string);
    std::shared_ptr<QueryObject> build();
private:
    std::shared_ptr<Entity> searchDeclaration(const std::string& synonym);
    std::vector<std::shared_ptr<Entity>> declarations;
    std::vector<shared_ptr<Constraint>> constraints;
    std::shared_ptr<Returnable> returnType;
};

#endif //SPA_QUERYBUILDER_H
