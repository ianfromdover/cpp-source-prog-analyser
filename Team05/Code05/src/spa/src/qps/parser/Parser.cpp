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
        Token entityType = this->synonym();
        synonyms.push_back(entityType.getLexeme());
        while (this->match({TokenType::COMMA})) {
            Token synonym = this->synonym();
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
        std::shared_ptr<SelectClause> selectcl = std::make_shared<SelectClause>();

        Token declarationType = this->consume(TokenType::SELECT, "Expect select type.");
        Token entityType = this->synonym();

        selectcl->addSelect(entityType.getLexeme());

        return selectcl;
    }

    std::shared_ptr<RelationshipClause> Parser::relationship() {
        std::shared_ptr<RelationshipClause> relationshipClause = std::make_shared<RelationshipClause>();

        Token relationshipType = this->consume(TokenType::PARENT, "Expect declaration type.");
        this->consume(TokenType::LEFT_PAREN, "Expect '(' after relationship type.");


        return relationshipClause;
    }

    std::shared_ptr<RelationshipClause> Parser::parent() {
        std::shared_ptr<RelationshipClause> relationshipClause = std::make_shared<RelationshipClause>();

        Token relationshipType = this->consume(TokenType::PARENT, "Expect declaration type.");
        this->consume(TokenType::LEFT_PAREN, "Expect '(' after relationship type.");
        if (this->check({TokenType::IDENTIFIER, TokenType::WILDCARD, TokenType::INTEGER})) {
            Token t = stmtRef();
            relationshipClause->setFirstArg(t);
        }
        this->consume(TokenType::COMMA, "Expect ',' after stmtRef.");
        if (this->check({TokenType::IDENTIFIER, TokenType::WILDCARD, TokenType::INTEGER})) {
            Token t = stmtRef();
            relationshipClause->setSecondArg(t);
        }
        this->consume(TokenType::RIGHT_PAREN, "Expect ')' after relationship type.");

        return relationshipClause;
    }

    Token Parser::stmtRef() {
        if (this->check(TokenType::INTEGER))
            return this->consume(TokenType::INTEGER, "Expect integer.");

        if (this->check(TokenType::IDENTIFIER))
            return this->synonym();

        if (this->check(TokenType::WILDCARD))
            return this->consume(TokenType::WILDCARD, "Expect wildcard.");

        throw std::runtime_error("syntax error: statement reference");
    }

    Token Parser::entRef() {
        if (this->check(TokenType::IDENTIFIER))
            return synonym();

        if (this->check(TokenType::WILDCARD))
            return this->consume(TokenType::WILDCARD, "Expect wildcard.");

        if (this->check(TokenType::QUOTE)) {
            this->consume(TokenType::QUOTE, "Expect quote.");
            Token ident = this->consume(TokenType::IDENTIFIER, "Expect identifier.");
            this->consume(TokenType::QUOTE, "Expect quote.");

            TokenType type(TokenType::QUOTED_IDENT);
            Token newToken = Token(type, "\"" + ident.getLexeme() + "\"");
            return newToken;
        }

        throw std::runtime_error("syntax error: statement reference");
    }

    Token Parser::synonym() {
        Token t = this->consume(TokenType::IDENTIFIER, "Expect identifier.");
        TokenType type(TokenType::SYNONYM);
        Token newToken = Token(type, t.getLexeme());
        return newToken;
    }


    void Parser::parse() {
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
                    if (this->check(TokenType::PARENT)) {
                        std::shared_ptr<RelationshipClause> relationship = this->parent();
                        query->addClause(relationship);
                    }
                }
            }
        }
    }
}