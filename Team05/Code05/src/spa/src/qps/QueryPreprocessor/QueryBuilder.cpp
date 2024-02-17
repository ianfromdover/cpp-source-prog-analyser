//
// Created by Alex on 8/2/2024.
//

#include <stdexcept>
#include <utility>
#include "QueryBuilder.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint/ParentConstraint.h"
#include "qps/Exceptions/SemanticErrorException.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"


void QueryBuilder::addRelationshipConstraints(std::string type, std::string syn1, std::string syn2) {
    std::shared_ptr<RelationshipConstraint> r;
    if (type == "Parent" || type == "Parent*"){
        std::shared_ptr<StatementReference> s1;
        std::shared_ptr<StatementReference> s2;
        try {
            int value = std::stoi(syn1);
            auto argPtr = std::make_shared<IntegerArgument>(value);
            s1 = dynamic_pointer_cast<StatementReference>(argPtr);
        } catch (const std::invalid_argument& e) {
            std::shared_ptr<Entity> arg1 = searchDeclaration(syn1);
            s1 = std::dynamic_pointer_cast<StatementReference>(arg1);
        }

        try {
            int value = std::stoi(syn2);
            auto argPtr = std::make_shared<IntegerArgument>(value);
            s2 = dynamic_pointer_cast<StatementReference>(argPtr);
        } catch (const std::exception e) {
            std::shared_ptr<Entity> arg2 = searchDeclaration(syn2);
            s2 = std::dynamic_pointer_cast<StatementReference>(arg2);
        }

        if (s1.get() && s2.get()) {

            ParentConstraint p(s1, s2);
            r = std::make_shared<ParentConstraint>(p);
        } else {
            throw std::runtime_error("synonym used not declared");
        }
    }
    constraints.push_back(r);
}

void QueryBuilder::addDeclaration(const std::string& entityType, std::string synonym) {
    std::shared_ptr<Entity> e;

    for (auto d : declarations){
        if (d->getIdentifier() == synonym){
            throw SemanticErrorException("Synonym already declared");
        }
    }

    if (entityType == "stmt") { // removed spaUtils definition due to clash with token::stmt, to check w alex
        StatementEntity stmt(synonym);
        e = std::make_shared<StatementEntity>(stmt);
    } else {
        throw std::runtime_error("invalid declaration type");
    }
    declarations.push_back(e);
}

std::shared_ptr<Entity> QueryBuilder::searchDeclaration(const std::string& synonym){
    for (shared_ptr<Entity> e : declarations){
        if (e->getIdentifier() == synonym){
            return e;
        }
    }
    return nullptr;
}

void QueryBuilder::addReturnType(std::string r) {
    std::shared_ptr<Entity> arg1 = searchDeclaration(r);
    if (arg1){
        returnType=arg1;
    } else {
        throw std::runtime_error("unable to find return type declaration");
    }
}

std::shared_ptr<QueryObject> QueryBuilder::build() {
    std::shared_ptr<QueryObject> query = std::make_shared<QueryObject>();
    for (const auto& d : declarations){
        query->addDeclaration(d); // TODO: Refactor with shared pointers
    }

    for (const auto& c : constraints){
        query->addConstraint(c); // TODO: Refactor with shared pointers
    }

    query->setReturnType(returnType);

    return query;
}
