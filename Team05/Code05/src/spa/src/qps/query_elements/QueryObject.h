//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_QUERYOBJECT_H
#define SPA_QUERYOBJECT_H

#include <vector>
#include <memory>
#include "Returnable.h"
#include "qps/query_elements/constraint/Constraint.h"
#include "Declaration.h"


class QueryObject {
private:
    std::shared_ptr<Returnable> returnType;
    std::vector<Constraint*> constraints;
    std::vector<Declaration*> declarations;

public:
    std::shared_ptr<Returnable> getReturnType();
    void setReturnType(std::shared_ptr<Returnable> r);
    std::vector<Constraint*> getConstraints();
    void addConstraint(Constraint&);
    std::vector<Declaration*> getDeclarations();
    void addDeclaration(Declaration&);
};


#endif //SPA_QUERYOBJECT_H
