//
// Created by tohzh on 17/2/2024.
//

#include "QueryObjectBuilder.h"

#include <utility>

void QueryObjectBuilder::reset() {
    intermediateObject.reset();
    qo.reset();
}

void QueryObjectBuilder::setSingleRelationshipConstraint(std::shared_ptr<RelationshipClause> relationship, std::shared_ptr<QueryObject> qo) {
    shared_ptr<Constraint> ptr = RelationshipConstraintDirector::process(std::move(relationship), qo);
    qo->addConstraint(ptr);
}

void QueryObjectBuilder::setSinglePatternClause(std::shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    shared_ptr<Constraint> ptr = PatternConstraintDirector::process(std::move(patternClause), qo);
    qo->addConstraint(ptr);
}

void QueryObjectBuilder::setSingleWithClause(std::shared_ptr<WithClause> withClause, shared_ptr<QueryObject> qo) {
    shared_ptr<Constraint> ptr = WithConstraintDirector::process(std::move(withClause), qo);
    qo->addConstraint(ptr);
}

shared_ptr<Entity> QueryObjectBuilder::setSingleSelectClause(int i) {
    if (intermediateObject->getSelectClause()->getSelectAttributeAt(i).getType().getInfo() != QPSTokenType::ERR_NULL) {
        std::string name = intermediateObject->getSelectClause()->getSelectEntityAt(i).getLexeme();
        QPSTokenType::QPSTypeInfo attribute = intermediateObject->getSelectClause()->getSelectAttributeAt(i).getType().getInfo();
        std::shared_ptr<VariableWith> var = std::make_shared<VariableWith>(name, attribute);
        var->setVariable(qo);
        return var;
    } else {
        std::string name = intermediateObject->getSelectClause()->getSelectEntityAt(i).getLexeme();
        return qo->getEntityInDeclaration(name);
    }
}

void QueryObjectBuilder::setSelectClauses() {
    if (!intermediateObject->hasSelectClause()) {
        return;
    }

    if (intermediateObject->getSelectClause()->isSelectBool()) {
      qo->setReturnType(std::make_shared<Boolean>());
    }

    else if (intermediateObject->getSelectClause()->getAllSelect().size() == 1) {
        qo->setReturnType(setSingleSelectClause(0));
    }

    else if (intermediateObject->getSelectClause()->getAllSelect().size() > 1) {
        std::vector<std::string> names = intermediateObject->getSelectClause()->selectElements;
        auto tupleReturn  = std::make_shared<TupleReturnable>();
        for (int i = 0; i < intermediateObject->getSelectClause()->getAllSelect().size(); i ++) {
            auto entity = setSingleSelectClause(i);
            tupleReturn->addEntityVector(entity);
        }
        qo->setReturnType(tupleReturn);
    } else {
        throw QPSException("Invalid select clause");
    }
}

void QueryObjectBuilder::setAllRelationshipConstraint() {
    if (!intermediateObject->hasRelationshipClause()) {
        return;
    }

    auto relationClauseVector = intermediateObject->getAllRelationshipClauses();
    for (auto relationClause : relationClauseVector) {
        setSingleRelationshipConstraint(relationClause, this->getQueryObjectRepresentation());
    }

}


void QueryObjectBuilder::setAllPatternClauses() {
    if (!intermediateObject->hasPatternClause()) {
        return;
    }
    auto patternClauseVector = intermediateObject->getAllPatternClauses();
    for (auto patternClause : patternClauseVector) {
        setSinglePatternClause(patternClause, this->getQueryObjectRepresentation());
    }
}

void QueryObjectBuilder::setAllWithConstraint() {
    if (!intermediateObject->hasWithClause()) {
        return;
    }
    auto withClauseVector = intermediateObject->getAllWithClauses();
    for (auto withClause : withClauseVector) {
        setSingleWithClause(withClause, this->getQueryObjectRepresentation());
    }
}

void QueryObjectBuilder::setAllDeclarationClauses() {
    if (!intermediateObject->hasDeclarationClause()) {
        return;
    }

    std::map<std::string, QPSTokenType::QPSTypeInfo> synonymTypeMap = intermediateObject->getSynonymTypeMap();
    std::map<std::string, QPSTokenType::QPSTypeInfo>::iterator it;
    for (it = synonymTypeMap.begin(); it != synonymTypeMap.end(); it++) {
        std::string synName = it->first;
        QPSTokenType::QPSTypeInfo typeInfo = it->second;
        std::shared_ptr<Entity> declaration = ConstraintArgCreator::buildEntity(typeInfo, synName);
        qo->addDeclaration(declaration);
    }
}

std::shared_ptr<QueryObject> QueryObjectBuilder::getQueryObjectRepresentation() {
    return qo;
}

std::shared_ptr<QueryObject> QueryObjectBuilder::build(shared_ptr<IntermediateQuery> inter) {
    reset();
    intermediateObject = std::move(inter);
    qo = make_shared<QueryObject>();
    setAllDeclarationClauses();
    setAllRelationshipConstraint();
    setSelectClauses(); // has to be done after declaration
    setAllPatternClauses();
    setAllWithConstraint();
    return getQueryObjectRepresentation();
}






