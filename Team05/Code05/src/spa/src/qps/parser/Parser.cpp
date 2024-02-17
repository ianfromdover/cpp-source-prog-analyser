//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "Parser.h"
#include "IntermediateQuery.h"

namespace qps {
    bool Parser::match(std::initializer_list<TokenType::TypeInfo> types) {
        for (const auto &type: types) {
            if (this->check(type)) {
                this->advance();
                return true;
            }
        }
        return false;
    }

    bool Parser::check(std::initializer_list<TokenType::TypeInfo> types) {
        for (const auto &type: types) {
            if (this->check(type)) {
                return true;
            }
        }
        return false;
    }

    bool Parser::check(TokenType::TypeInfo type) {
        if (this->isAtEnd()) {
            return false;
        }
        return this->peek().getType().getInfo() == type;
    }


    bool Parser::isDeclaration() {
        return this->check(TokenType::STMT);
    }

    bool Parser::isRelationship() {
        return this->check(TokenType::PARENT);
    }

    bool Parser::isSuchThat() {
        std::vector<Token> lookahead = this->peekAhead(2);
        if (lookahead.empty()) {
            return false;
        }
        return lookahead[0].getType().getInfo() == TokenType::SUCH &&
               lookahead[1].getType().getInfo() == TokenType::THAT;
    }

    bool Parser::isAtEnd() {
        return this->peek().getType().getInfo() == TokenType::END_OF_FILE;
    }

    Token Parser::advance() {
        if (!this->isAtEnd()) {
            this->current++;
        }
        return this->previous();
    }

    Token Parser::peek() {
        return *this->tokens.at(this->current);
    }

// will return empty list if not enough tokens to peek
    std::vector<Token> Parser::peekAhead(int lookahead) {
        if (this->current + lookahead < this->tokens.size()) {
            std::vector<Token> lookaheadTokens;
            for (int i = 0; i < lookahead; i++) {
                lookaheadTokens.push_back(*this->tokens.at(this->current + i));
            }
            return lookaheadTokens;
        } else {
            return {};
        }
    }

    Token Parser::previous() {
        return *this->tokens.at(this->current - 1);
    }

    bool Parser::checkPrevious(TokenType::TypeInfo type) {
        return this->previous().getType().getInfo() == type;
    }


    Token Parser::consume(TokenType::TypeInfo type, const std::string& message) {
        if (this->check(type)) {
            return this->advance();
        }

        // TODO: Handle parse errors according to requirements.
        throw std::runtime_error(message);
    }

    std::shared_ptr<DeclarationClause> Parser::declaration() {
        std::vector<std::string> synonyms;
        std::string type;
        Token declarationType = this->consume(TokenType::STMT, "Expect declaration type.");
        Token entityType = this->synonym(this->consume(TokenType::IDENTIFIER, "Expect identifier."));
        synonyms.push_back(entityType.getLexeme());
        while (this->match({TokenType::COMMA})) {
            Token synonym = this->synonym(this->consume(TokenType::IDENTIFIER, "Expect identifier."));
            synonyms.push_back(synonym.getLexeme());
        }
        this->consume(TokenType::SEMICOLON, "Expect ';' after declaration.");
        auto declarationCl = std::make_shared<DeclarationClause>();
        for (auto &synonym: synonyms) {
            declarationCl->addDeclaration(declarationType.getType(), synonym);
        }
        return declarationCl;
    }

    std::shared_ptr<SelectClause> Parser::select() {

        Token declarationType = this->consume(TokenType::SELECT, "Expect select type.");
        Token entityType = this->synonym(this->consume(TokenType::IDENTIFIER, "Expect identifier."));

        std::shared_ptr<SelectClause> selectCl = std::make_shared<SelectClause>();
        selectCl->addSelect(entityType.getLexeme());

        return selectCl;
    }

    std::shared_ptr<RelationshipClause> Parser::relationship() {
        std::shared_ptr<RelationshipClause> relationshipClause;

        if (this->check(TokenType::PARENT)) {
            relationshipClause = this->parent();
        } else {
            relationshipClause = nullptr;
        }

        return relationshipClause;
    }

    std::shared_ptr<RelationshipClause> Parser::parent() {

        Token relationshipType = this->consume(TokenType::PARENT, "Expect declaration type.");
        this->consume(TokenType::LEFT_PAREN, "Expect '(' after relationship type.");
        auto t1 = stmtRef();
        this->consume(TokenType::COMMA, "Expect ',' after stmtRef.");
        auto t2 = stmtRef();
        this->consume(TokenType::RIGHT_PAREN, "Expect ')' after relationship type.");

        RelationshipClause parentCl(relationshipType.getType().getInfo(), t1, TokenType::STMT_REF,  t2, TokenType::STMT_REF);

        return std::make_shared<RelationshipClause>(parentCl);
    }

    std::shared_ptr<PatternClause> Parser::pattern() {
        Token synAssign = this->synonym(this->consume(TokenType::IDENTIFIER, "Expect identifier."));

        this->consume(TokenType::LEFT_PAREN, "Expect '(' after identifier.");
        Token entRef = this->entRef();
        this->consume(TokenType::COMMA, "Expect ',' after entRef.");
        Token exprSpec = this->exprSpec();
        this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expr spec.");

        PatternClause patternCl(synAssign.getLexeme(), entRef, TokenType::TypeInfo::ENT_REF, exprSpec, TokenType::EXPR_REF);

        return std::make_shared<PatternClause>(patternCl);
    }

    Token Parser::stmtRef() {
        if (this->match({TokenType::INTEGER, TokenType::IDENTIFIER, TokenType::WILDCARD})) {
            if (this->checkPrevious(TokenType::INTEGER))
                return this->previous();

            if (this->checkPrevious(TokenType::IDENTIFIER))
                return this->synonym(this->previous());

            if (this->checkPrevious(TokenType::WILDCARD))
                return this->previous();
        }
        throw std::runtime_error("syntax error: statement reference");
    }

    Token Parser::entRef() {
        if (this->match({TokenType::IDENTIFIER, TokenType::WILDCARD, TokenType::QUOTE})) {
            if (this->checkPrevious(TokenType::IDENTIFIER))
                return synonym(this->previous());

            if (this->checkPrevious(TokenType::WILDCARD))
                return this->previous();

            if (this->checkPrevious(TokenType::QUOTE)) {
                Token ident = this->consume(TokenType::IDENTIFIER, "Expect identifier.");
                this->consume(TokenType::QUOTE, "Expect quote.");

                TokenType type(TokenType::QUOTED_IDENT);
                Token newToken = Token(type, "\"" + ident.getLexeme() + "\"");
                return newToken;
            }
        }
        throw std::runtime_error("syntax error: statement reference");
    }

    Token Parser::synonym(Token t) {
        TokenType type(TokenType::SYNONYM);
        Token newToken = Token(type, t.getLexeme());
        return newToken;
    }

    Token Parser::exprSpec() {
        if (this->check(TokenType::WILDCARD)){
            Token t = this->consume(TokenType::WILDCARD, "Expect wildcard.");
            if (this->check(TokenType::QUOTE)){
                this->consume(TokenType::QUOTE, "Expect quote.");
                Token expr = this->expr();
                this->consume(TokenType::QUOTE, "Expect quote.");
                this->consume(TokenType::WILDCARD, "Expect wildcard.");

                TokenType type(TokenType::EXPR_WILDCARD);
                Token newToken = Token(type, "\"" + expr.getLexeme() + "\"");
                return newToken;
            } else {
                return t;
            }
        }

        if (this->check(TokenType::QUOTE)){
            this->consume(TokenType::QUOTE, "Expect quote.");
            Token expr = this->expr();
            this->consume(TokenType::QUOTE, "Expect quote.");

            TokenType type(TokenType::EXPR);
            Token newToken = Token(type, "\"" + expr.getLexeme() + "\"");
            return newToken;
        }

        throw std::runtime_error("syntax error: exprSpec");
    }

    Token Parser::expr() {
        Token t1 = this->term();
        Token t2 = this->exprTail();
        TokenType type(TokenType::EXPR);
        Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
        return newToken;
    }

    Token Parser::exprTail() {
        if (this->check(TokenType::PLUS)){
            this->consume(TokenType::PLUS, "Expect '+' after expression.");
            Token t1 = this->term();
            Token t2 = this->exprTail();
            TokenType type(TokenType::EXPR);
            Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
            return newToken;
        }
        if (this->check(TokenType::MINUS)){
            this->consume(TokenType::MINUS, "Expect '-' after expression.");
            Token t1 = this->term();
            Token t2 = this->exprTail();
            TokenType type(TokenType::EXPR);
            Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
            return newToken;
        }
        return {TokenType(TokenType::EMPTY), ""};
    }

    Token Parser::term() {
        Token t1 = this->factor();
        Token t2 = this->termTail();
        TokenType type(TokenType::TERM);
        Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
        return newToken;
    }

    Token Parser::termTail() {
        if (this->check(TokenType::STAR)){
            this->consume(TokenType::STAR, "Expect '+' after expression.");
            Token t1 = this->factor();
            Token t2 = this->termTail();
            TokenType type(TokenType::TERM);
            Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
            return newToken;
        }
        if (this->check(TokenType::SLASH)){
            this->consume(TokenType::SLASH, "Expect '/' after expression.");
            Token t1 = this->term();
            Token t2 = this->exprTail();
            TokenType type(TokenType::TERM);
            Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
            return newToken;
        }
        if (this->check(TokenType::PERCENT)){
            this->consume(TokenType::PERCENT, "Expect '%' after expression.");
            Token t1 = this->term();
            Token t2 = this->exprTail();
            TokenType type(TokenType::TERM);
            Token newToken = Token(type, t1.getLexeme()+t2.getLexeme());
            return newToken;
        }
        return {TokenType(TokenType::EMPTY), ""};
    }

    Token Parser::factor() {
        if (this->check(TokenType::INTEGER))
            return this->consume(TokenType::INTEGER, "Expect integer.");
        if (this->check(TokenType::IDENTIFIER))
            return this->consume(TokenType::IDENTIFIER, "Expect identifier.");
        if (this->check(TokenType::LEFT_PAREN)) {
            this->consume(TokenType::LEFT_PAREN, "Expect '(' after expression.");
            Token t = this->expr();
            this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
            TokenType type(TokenType::FACTOR);
            Token newToken = Token(type, t.getLexeme());
        }
        throw std::runtime_error("syntax error: factor");

    }


    std::shared_ptr<IntermediateQuery> Parser::parse() {
        auto query = std::make_shared<IntermediateQuery>();

        if (isDeclaration()) {
            while (this->isDeclaration()) {
                std::shared_ptr<DeclarationClause> declaration = this->declaration();
                query->addClause(declaration);
            }

            if (this->check(TokenType::SELECT)) {
                std::shared_ptr<SelectClause> select = this->select();
                query->addClause(select);
            }

            if (isSuchThat()) {
                this->consume(TokenType::SUCH, "Expect 'such' after select clause.");
                this->consume(TokenType::THAT, "Expect 'that' after 'such'.");

                if (isRelationship()) {
                    std::shared_ptr<RelationshipClause> relationship = this->relationship();
                    query->addClause(relationship);
                }
            }

            if (this->match({TokenType::PATTERN})) {
                std::shared_ptr<PatternClause> pattern = this->pattern();
                query->addClause(pattern);
            }

            if (!isAtEnd()) throw std::runtime_error("Expect end of file.");

            return query;
        }
        throw std::runtime_error("Expect declaration clause.");
    }
}