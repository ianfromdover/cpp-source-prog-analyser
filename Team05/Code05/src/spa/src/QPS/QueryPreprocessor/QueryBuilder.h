//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_QUERYBUILDER_H
#define SPA_QUERYBUILDER_H

#include <memory>
#include "../Query/Returnable.h"
#include "../Query/RelationshipConstraint.h"
#include "../Query/PatternConstraint.h"
#include "../Query/Query.h"
#include "qps/query_elements/QueryObject.h"


class QueryBuilder {
public:
    void addDeclaration(std::string, std::string);
    void addConstraints(std::string, std::string, std::string);
    void addReturnType(std::string);
    std::shared_ptr<QueryObject> build();
private:
    std::vector<Entity> declarations;
    std::vector<std::string> constraintsArguments;
};

#endif //SPA_QUERYBUILDER_H
