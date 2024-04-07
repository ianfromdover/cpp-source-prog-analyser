//
// Created by tohzh on 5/4/2024.
//

#include "WithConstraintBuilder.h"

#include <utility>

void WithConstraintBuilder::addPatternClause(std::shared_ptr<WithClause> withClause, shared_ptr<QueryObject> qo) {
    arg1 = createWithArgument(withClause->getFirstArg(), withClause->getFirstArgType(), withClause->getFirstArgAttributeNoException(), qo);
    arg2 = createWithArgument(withClause->getSecondArg(), withClause->getSecondArgType(), withClause->getSecondArgAttributeNoException(), qo);
    shared_ptr<WithConstraint> withConstraint =  make_shared<WithConstraint>(arg1, arg2);
    constraintClause = withConstraint;
}

shared_ptr<WithReference> WithConstraintBuilder::createWithArgument(QPSToken token, QPSTokenType::QPSTypeInfo argType, QPSTokenType::QPSTypeInfo argAttribute, shared_ptr<QueryObject> qo) {
    if (argType == QPSTokenType::INTEGER || argType == QPSTokenType::QUOTED_IDENT) {
        std::string integer = token.getLexeme();
        return make_shared<LiteralWith>(integer);
    } else if (argType == QPSTokenType::ATTR_REF) {
        auto arg = ConstraintBuilderTemplate::buildArgAsWithRef(token, QPSTokenType::WITH_REF, qo);
        std::string identifier = token.getLexeme();
        VariableWith s = VariableWith(identifier, argAttribute);
        s.setVariable(qo);
        return make_shared<VariableWith>(s);
    } else {
        throw QPSException("found invalid [with] QPSTokenType of: " +  to_string(argType));
    }
}

void WithConstraintBuilder::addConstraintClause(shared_ptr<WithClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
}
