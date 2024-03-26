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


void QueryObjectBuilder::setSingleSelectClause() {
    if (!intermediateObject->hasSelectClause()) {
        return;
    }

    // TODO: if condition check intermediate query only has 1 select entity
    if (true) {
        std::string name = intermediateObject->getSelectClause()->selectElements[0];
        qo->setReturnType(qo->getEntityInDeclaration(name));
    }

    // TODO: if condition check intermediate query has boolean select
    if (false) {

    }

    //TODO: if condition check intermediate query has multiple select entity
    if (false) {

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
    setSingleSelectClause(); // has to be done after declaration
    setAllPatternClauses();
    return getQueryObjectRepresentation();
}




