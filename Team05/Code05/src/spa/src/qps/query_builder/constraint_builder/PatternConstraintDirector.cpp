//
// Created by tohzh on 16/3/2024.
//

#include "PatternConstraintDirector.h"

#include <utility>

std::shared_ptr<Constraint> PatternConstraintDirector::process(shared_ptr<PatternClause> r,
                                                                    shared_ptr<QueryObject> qo) {
    QPSTokenType::QPSTypeInfo type = PatternConstraintDirector::getPatternType(r, qo);
    shared_ptr<PatternConstraintBuilderTemplate> b;
    switch (type) {
        case (QPSTokenType::ASSIGN): {
            b = make_shared<AssignPatternConstraintBuilder>();
            break;
        }
        case (QPSTokenType::IF): {
            b = make_shared<IfPatternConstraintBuilder>();
            break;
        }
        case (QPSTokenType::WHILE): {
            b = make_shared<WhilePatternConstraintBuilder>();
            break;
        }
        default: {
            throw QPSException("Invalid pattern type");
        }
    }
    b->buildPatternConstraint(std::move(r), std::move(qo));
    return b->build();
}

QPSTokenType::QPSTypeInfo PatternConstraintDirector::getPatternType(shared_ptr<PatternClause> patternC, shared_ptr<QueryObject> qo) {
    std::string syn = patternC->getPatternSynonym();
    auto entity = qo->getEntityInDeclaration(syn);
    std::string entType = entity->getEntityType();
    if (entType == TYPE_IF) {
        return QPSTokenType::IF;
    } else if (entType == TYPE_WHILE) {
        return QPSTokenType::WHILE;
    } else if (entType == TYPE_ASSIGN) {
        return QPSTokenType::ASSIGN;
    } else {
        throw QPSException("Invalid pattern type");
    }
}
