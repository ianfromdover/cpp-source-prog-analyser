//
// Created by tohzh on 17/2/2024.
//

#include "QueryObjectBuilder.h"

#include <utility>

void QueryObjectBuilder::reset() {
    intermediateObject.reset();
    qo.reset();
}

void QueryObjectBuilder::setSingleRelationshipConstraint(std::shared_ptr<RelationshipClause> relationship) {
    shared_ptr<Constraint> ptr = RelationshipConstraintDirector::process(std::move(relationship));
    qo->addConstraint(ptr);
}

void QueryObjectBuilder::setSinglePatternClause(std::shared_ptr<PatternClause> patternClause) {
    ConcretePatternConstraintBuilder builder;
    qo->addConstraint(builder.buildPatternConstraint(std::move(patternClause)));
}


void QueryObjectBuilder::setSingleSelectClause() {
    std::string name = intermediateObject->getSelectClause()->selectElements[0];
    qo->setReturnType(qo->getEntityInDeclaration(name));
}

//only need one relationship for milestone 1
void QueryObjectBuilder::setAllRelationshipConstraint() {
    setSingleRelationshipConstraint(intermediateObject->getRelationshipClause());
}

//only need one pattern for milestone 1
void QueryObjectBuilder::setAllPatternClauses() {
    setSinglePatternClause(intermediateObject->getPatternClause());
}


void QueryObjectBuilder::setAllDeclarationClauses() {
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




