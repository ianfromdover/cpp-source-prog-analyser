//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_CONCRETEQUERYBUILDER_H
#define SPA_CONCRETEQUERYBUILDER_H

#include "QueryBuilder.h"

class ConcreteQueryBuilder : public QueryBuilder {
public:
    void addDeclaration(Declaration) override;
};


#endif //SPA_CONCRETEQUERYBUILDER_H
