//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_QUERYOBJECT_H
#define SPA_QUERYOBJECT_H

#include <vector>
#include <memory>
#include "Returnable.h"
#include "qps/query_elements/constraint/Constraint.h"
#include "Entity.h"

class QueryObject {
private:
    std::shared_ptr<Returnable> returnType;
    std::vector<std::shared_ptr<Constraint>> constraints;
    std::vector<std::shared_ptr<Entity>> declarations;

public:
    std::shared_ptr<Returnable> getReturnType();
    void setReturnType(std::shared_ptr<Returnable> r);
    std::vector<std::shared_ptr<Constraint>> getConstraints();
    void addConstraint(std::shared_ptr<Constraint>);
    std::vector<std::shared_ptr<Entity>> getDeclarations();
    void addDeclaration(const std::shared_ptr<Entity>&);
    std::shared_ptr<Entity> getEntityInDeclaration(std::string);
    std::string toString();
};


#endif //SPA_QUERYOBJECT_H
