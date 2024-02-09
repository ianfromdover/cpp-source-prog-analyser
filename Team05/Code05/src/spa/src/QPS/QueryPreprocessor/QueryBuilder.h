//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_QUERYBUILDER_H
#define SPA_QUERYBUILDER_H

#include "../Query/Declaration.h"
#include "../Query/Returnable.h"
#include "../Query/RelationshipConstraint.h"
#include "../Query/PatternConstraint.h"
#include "../Query/Query.h"


class QueryBuilder {
public:
    virtual void addDeclaration(Declaration) = 0;
};

#endif //SPA_QUERYBUILDER_H
