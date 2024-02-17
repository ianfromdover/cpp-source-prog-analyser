//
// Created by tohzh on 17/2/2024.
//

#ifndef SPA_CONSTRAINTBUILDER_H
#define SPA_CONSTRAINTBUILDER_H


#include "qps/parser/RelationshipClause.h" // error when I include this inclusion, it has to be the first import (also for subsequent imports)
#include "ConstraintArgCreator.h"
#include "../query_elements/constraint/FollowsConstraint.h"
#include "../query_elements/constraint/FollowsTConstraint.h"
#include "../query_elements/constraint/ParentConstraint.h"
#include "../query_elements/constraint/ParentTConstraint.h"
#include "../query_elements/constraint/UsesSConstraint.h"
#include "../query_elements/constraint/UsesPConstraint.h"
#include "../query_elements/constraint/ModifiesSConstraint.h"
#include "../query_elements/constraint/ModifiesPConstraint.h"
#include "../query_elements/constraint/ConcretePatternConstraint.h"
#include <stdexcept>

class ConstraintBuilder {
private:
    static shared_ptr<Constraint> constraintClause;
    static shared_ptr<ConstraintArgument> arg1;
    static shared_ptr<ConstraintArgument> arg2;
    static void reset();
    static void buildConstraint(qps::TokenType::TypeInfo, qps::TokenType::TypeInfo, qps::TokenType::TypeInfo);
    static void buildFirstArg(qps::Token&, qps::TokenType::TypeInfo);
    static void buildSecondArg(qps::Token&, qps::TokenType::TypeInfo);
    static std::shared_ptr<ConstraintArgument> buildArg(qps::Token&, qps::TokenType::TypeInfo);
    static std::shared_ptr<Constraint> build();
public:
    static std::shared_ptr<Constraint> buildConstraint(shared_ptr<qps::RelationshipClause>);
};


#endif //SPA_CONSTRAINTBUILDER_H
