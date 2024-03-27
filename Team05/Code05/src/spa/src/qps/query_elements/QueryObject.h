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
    std::string getReturnString();
    std::string getDeclarationString();
    std::string getConstraintString();
public:
    std::shared_ptr<Returnable> getReturnType();
    void setReturnType(std::shared_ptr<Returnable> r);
    std::vector<std::shared_ptr<Constraint>> getConstraints();
    void addConstraint(std::shared_ptr<Constraint>);
    std::vector<std::shared_ptr<Entity>> getDeclarations();
    void addDeclaration(const std::shared_ptr<Entity>&);
    std::shared_ptr<Entity> getEntityInDeclaration(std::string);
    std::string toString();

    string combineString(string returnString, string declarationString, string constraintString);

    // TODO: create a virtual function isEqual in Constraint classes which will be overridden by the concrete constraint classes themselves,
    // TODO: create a function HERE that does the checking of the constraints within one single QueryObject to see if there are any repeats
    // TODO: if there are repeats ie hash value is the same, delete one of the repeats
    // TODO: consider using C++ unordered_map or unordered_set to check hash values and get the unique list of constraints in the QO.
    // TODO: so using the new thing we only need a new thing where each constraint has a hash code function, ie a way to check if an object is totally the same as another object.

};


#endif //SPA_QUERYOBJECT_H
