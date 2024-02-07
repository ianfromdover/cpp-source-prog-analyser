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
    void addDeclaration(Declaration);
    void addReturnType(Returnable);
    void addRelationshipConstraint(RelationshipConstraint);
    void addPatternConstraint(PatternConstraint);
    Query build();
};


#endif //SPA_QUERYBUILDER_H
