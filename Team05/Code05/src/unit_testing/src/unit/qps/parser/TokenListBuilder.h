//
// Created by Alex on 22/2/2024.
//

#ifndef SPA_TOKENLISTBUILDER_H
#define SPA_TOKENLISTBUILDER_H

#include "qps/tokenizer/QPSTokenType.h"
#include "qps/tokenizer/QPSTokenList.h"

using namespace std;
typedef QPSTokenType::QPSTypeInfo type;

class TokenListBuilder {
public:
    TokenListBuilder() = default;
    QPSTokenList tokenList;
    QPSTokenList get() {
        tokenList.addToken(type::END_OF_FILE, "");
        return tokenList;
    };

    TokenListBuilder singleStmtDeclaration() {
        return stmt().identifier().semicolon();
    };

    TokenListBuilder singleIfDeclaration() {
        return ifStmt().identifier().semicolon();
    };

    TokenListBuilder multiStmtDeclaration() {
        return stmt().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiReadDeclaration() {
        return read().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiPrintDeclaration() {
        return print().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiWhileDeclaration() {
        return whileStmt().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiIfDeclaration() {
        return ifStmt().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiAssignDeclaration() {
        return assign().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiVariableDeclaration() {
        return variable().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiConstantDeclaration() {
        return constant().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder multiProcedureDeclaration() {
        return procedure().identifier().comma().identifier().semicolon();
    };

    TokenListBuilder validIfPattern(){
        return pattern().identifier().leftParen().identifier().comma().wildcard().comma().wildcard().rightParen();
    }

    TokenListBuilder validWhilePattern(){
        return pattern().identifier().leftParen().identifier().comma().wildcard().rightParen();
    };

    TokenListBuilder validAssignPattern(){
        return pattern().identifier().leftParen().identifier().comma().wildcard().rightParen();
    };

    TokenListBuilder validFollows(){
        return suchThat().follows().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validFollowsStar(){
        return suchThat().followsStar().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validParent(){
        return suchThat().parent().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validParentStar(){
        return suchThat().parentStar().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validCalls(){
        return suchThat().calls().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validCallsStar(){
        return suchThat().callsStar().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validBooleanSelect(){
        return select().boolean();
    }

    TokenListBuilder validSingleTupleSelect(){
        return select().leftA_Brac().identifier().rightA_Brac();
    }

    TokenListBuilder validMultiTupleSelect(){
      return select().leftA_Brac().identifier().comma().identifier().comma().identifier().rightA_Brac();
    }

    TokenListBuilder validUses(){
        return suchThat().uses().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder validModifies(){
        return suchThat().modifies().leftParen().identifier().comma().identifier().rightParen();
    }

    TokenListBuilder select() {
        tokenList.addToken(type::SELECT, "Select");
        return *this;
    };

    TokenListBuilder follows() {
        tokenList.addToken(type::FOLLOWS, "Follows");
        return *this;
    };

    TokenListBuilder followsStar() {
        tokenList.addToken(type::FOLLOWS_T, "Follows*");
        return *this;
    };

    TokenListBuilder parentStar() {
        tokenList.addToken(type::PARENT_T, "Parent*");
        return *this;
    };

    TokenListBuilder parent() {
        tokenList.addToken(type::PARENT, "Parent");
        return *this;
    };

    TokenListBuilder uses() {
      tokenList.addToken(type::USES, "Uses");
      return *this;
    };

    TokenListBuilder modifies() {
      tokenList.addToken(type::MODIFIES, "Modifies");
      return *this;
    };

    TokenListBuilder calls() {
        tokenList.addToken(type::CALLS, "Calls");
        return *this;
    };

    TokenListBuilder callsStar() {
        tokenList.addToken(type::CALLS_T, "Calls*");
        return *this;
    };

    TokenListBuilder identifier() {
        tokenList.addToken(type::IDENTIFIER, "s");
        return *this;
    };

    TokenListBuilder wildcard() {
        tokenList.addToken(type::WILDCARD, "_");
        return *this;
    };

    TokenListBuilder boolean() {
        tokenList.addToken(type::BOOLEAN, "BOOLEAN");
        return *this;
    };

    TokenListBuilder quotedIdent() {
        tokenList.addToken(type::QUOTE, "\"");
        tokenList.addToken(type::IDENTIFIER, "s");
        tokenList.addToken(type::QUOTE, "\"");
        return *this;
    };

    TokenListBuilder wildcardConst(){
        tokenList.addToken(type::WILDCARD, "_");
        tokenList.addToken(type::QUOTE, "\"");
        tokenList.addToken(type::INTEGER, "1");
        tokenList.addToken(type::QUOTE, "\"");
        tokenList.addToken(type::WILDCARD, "_");
        return *this;
    };

    TokenListBuilder wildcardIdent(){
        tokenList.addToken(type::WILDCARD, "_");
        tokenList.addToken(type::QUOTE, "\"");
        tokenList.addToken(type::IDENTIFIER, "s");
        tokenList.addToken(type::QUOTE, "\"");
        tokenList.addToken(type::WILDCARD, "_");
        return *this;
    };


    TokenListBuilder integer() {
        tokenList.addToken(type::INTEGER, "1");
        return *this;
    };

    TokenListBuilder comma() {
        tokenList.addToken(type::COMMA, ",");
        return *this;
    };

    TokenListBuilder leftParen() {
        tokenList.addToken(type::LEFT_PAREN, "(");
        return *this;
    };

    TokenListBuilder leftA_Brac() {
        tokenList.addToken(type::LEFT_A_BRAC, "<");
        return *this;
    };

    TokenListBuilder rightA_Brac() {
      tokenList.addToken(type::RIGHT_A_BRAC, ">");
      return *this;
    };

    TokenListBuilder rightParen() {
        tokenList.addToken(type::RIGHT_PAREN, ")");
        return *this;
    };

    TokenListBuilder semicolon() {
        tokenList.addToken(type::SEMICOLON, ";");
        return *this;
    };

    TokenListBuilder stmt() {
        tokenList.addToken(type::STMT1, "stmt");
        return *this;
    };

    TokenListBuilder read() {
        tokenList.addToken(type::READ, "read");
        return *this;
    };

    TokenListBuilder print() {
        tokenList.addToken(type::PRINT, "print");
        return *this;
    };

    TokenListBuilder whileStmt() {
        tokenList.addToken(type::WHILE, "while");
        return *this;
    };

    TokenListBuilder ifStmt() {
        tokenList.addToken(type::IF, "if");
        return *this;
    };

    TokenListBuilder assign() {
        tokenList.addToken(type::ASSIGN, "assign");
        return *this;
    };

    TokenListBuilder variable() {
        tokenList.addToken(type::VARIABLE, "variable");
        return *this;
    };

    TokenListBuilder constant() {
        tokenList.addToken(type::CONSTANT, "constant");
        return *this;
    };

    TokenListBuilder procedure() {
        tokenList.addToken(type::PROCEDURE, "procedure");
        return *this;
    };

    TokenListBuilder pattern() {
        tokenList.addToken(type::PATTERN, "pattern");
        return *this;
    };

    TokenListBuilder suchThat() {
        tokenList.addToken(type::SUCH, "such");
        tokenList.addToken(type::THAT, "that");
        return *this;
    };
};


#endif //SPA_TOKENLISTTokenListBuilder_H
