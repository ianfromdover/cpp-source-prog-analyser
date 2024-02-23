//
// Created by Alex on 22/2/2024.
//

#ifndef SPA_INTERMEDIATEBUILDER_H
#define SPA_INTERMEDIATEBUILDER_H

#include "qps/parser/IntermediateQuery.h"

class IntermediateBuilder {
public:
    IntermediateBuilder() = default;
    IntermediateQuery build() {
        return query;
    };
    IntermediateBuilder addSingleStmtDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::STMT1), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiStmtDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::STMT1), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::STMT1), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiReadDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::READ), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::READ), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiPrintDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiCallDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::CALL), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::CALL), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiWhileDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::WHILE), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::WHILE), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiIfDeclaration(){
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::IF), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::IF), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiAssignDeclaration() {
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::IF), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::IF), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiVariableDeclaration() {
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::VARIABLE), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::VARIABLE), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiConstantDeclaration() {
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::CONSTANT), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::CONSTANT), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addMultiProcedureDeclaration() {
        DeclarationClause cl;
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PROCEDURE), "s");
        cl.addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PROCEDURE), "s");
        query.addClause(std::make_shared<DeclarationClause>(cl));
        return *this;
    }
    IntermediateBuilder addSingleSelectClause(){
        SelectClause cl;
        cl.addSelect("s");
        query.addClause(std::make_shared<SelectClause>(cl));
        return *this;
    }


    IntermediateQuery query;
};

#endif //SPA_INTERMEDIATEBUILDER_H
