//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTCREATOR_H
#define SPA_CONSTRAINTCREATOR_H

#include "../query_elements/constraint/FollowsConstraint.h"
#include "../query_elements/constraint/FollowsTConstraint.h"
#include "../query_elements/constraint/ParentConstraint.h"
#include "../query_elements/constraint/ParentTConstraint.h"
#include "../query_elements/constraint/UsesSConstraint.h"
#include "../query_elements/constraint/UsesPConstraint.h"
#include "../query_elements/constraint/ModifiesSConstraint.h"
#include "../query_elements/constraint/ModifiesPConstraint.h"
#include "../query_elements/constraint/ConcretePatternConstraint.h"
//#include "qps/tokenizer/Token.h"
#include "ConstraintArgCreator.h"

class ConstraintCreator {
private:
    shared_ptr<Constraint> constraintClause;
    void reset();
public:
//    virtual void addFirstArg(shared_ptr<qps::Token>) = 0;
//    virtual void addSecondArg(shared_ptr<qps::Token>) = 0;
    std::shared_ptr<Constraint> build();
};


#endif //SPA_CONSTRAINTCREATOR_H
