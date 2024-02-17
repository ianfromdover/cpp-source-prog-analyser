//
// Created by tohzh on 17/2/2024.
//

#include "QueryBuilder.h"

#include <utility>

void QueryBuilder::reset() {
    intermediateObject.reset();
    qo.reset();
}

void QueryBuilder::setSingleRelationshipConstraint(std::shared_ptr<qps::RelationshipClause> relationship) {
    shared_ptr<Constraint> ptr = RelationshipConstraintDirector::process(std::move(relationship));
    qo->addConstraint(ptr);
}

void QueryBuilder::setSinglePatternClause(std::shared_ptr<qps::PatternClause> patternClause) {
    ConcretePatternConstraintBuilder builder;
    qo->addConstraint(builder.buildPatternConstraint(std::move(patternClause)));
}


void QueryBuilder::setSingleSelectClause() {
    std::string name = intermediateObject->getSelectClause()->selectElements[0];
    qo->setReturnType(qo->getEntityInDeclaration(name));
}

//only need one relationship for milestone 1
void QueryBuilder::setAllRelationshipConstraint() {
    setSingleRelationshipConstraint(intermediateObject->getRelationshipClause());
}

//only need one pattern for milestone 1
void QueryBuilder::setAllPatternClauses() {
    setSinglePatternClause(intermediateObject->getPatternClause());
}


void QueryBuilder::setAllDeclarationClauses() {
    std::map<std::string, qps::TokenType::TypeInfo> synonymTypeMap = intermediateObject->getSynonymTypeMap();
    std::map<std::string, qps::TokenType::TypeInfo>::iterator it;
    for (it = synonymTypeMap.begin(); it != synonymTypeMap.end(); it++) {
        std::string synName = it->first;
        qps::TokenType::TypeInfo typeInfo = it->second;
        std::shared_ptr<Entity> declaration = ConstraintArgCreator::buildEntity(typeInfo, synName);
        qo->addDeclaration(declaration);
    }
}

std::shared_ptr<QueryObject> QueryBuilder::getQueryObjectRepresentation() {
    return qo;
}

std::shared_ptr<QueryObject> QueryBuilder::build(shared_ptr<IntermediateQuery> inter) {
    reset();
    intermediateObject = std::move(inter);
    qo = make_shared<QueryObject>();
    setAllDeclarationClauses();
    setAllRelationshipConstraint();
    setSingleSelectClause(); // has to be done after declaration
    setAllPatternClauses();
    return getQueryObjectRepresentation();
}




