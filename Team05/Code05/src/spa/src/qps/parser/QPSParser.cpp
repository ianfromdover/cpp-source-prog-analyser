//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "QPSParser.h"
#include "IntermediateQuery.h"
#include "qps/Exceptions/QPSParseException.h"

bool QPSParser::match(std::initializer_list<QPSTokenType::QPSTypeInfo> types) {
    for (const auto &type: types) {
        if (this->check(type)) {
            this->advance();
            return true;
        }
    }
    return false;
}

bool QPSParser::check(std::initializer_list<QPSTokenType::QPSTypeInfo> types) {
    for (const auto &type: types) {
        if (this->check(type)) {
            return true;
        }
    }
    return false;
}

bool QPSParser::check(QPSTokenType::QPSTypeInfo type) {
    if (this->isAtEnd()) {
        return false;
    }
    return this->peek().getType().getInfo() == type;
}


bool QPSParser::isDeclaration() {
    return this->check({
                               QPSTokenType::STMT1,
                               QPSTokenType::READ,
                               QPSTokenType::PRINT,
                               QPSTokenType::CALL,
                               QPSTokenType::WHILE,
                               QPSTokenType::IF,
                               QPSTokenType::ASSIGN,
                               QPSTokenType::VARIABLE,
                               QPSTokenType::CONSTANT,
                               QPSTokenType::PROCEDURE});
}

bool QPSParser::isRelationship() {
    return this->check({
                               QPSTokenType::PARENT,
                               QPSTokenType::PARENT_T,
                               QPSTokenType::FOLLOWS,
                               QPSTokenType::FOLLOWS_T,
                               QPSTokenType::USES_S,
                               QPSTokenType::MODIFIES_S,
                      QPSTokenType::MODIFIES, QPSTokenType::USES,
                      QPSTokenType::CALLS,
                               QPSTokenType::CALLS_T});
}

bool QPSParser::isSuchThat() {
    std::vector<QPSToken> lookahead = this->peekAhead(2);
    if (lookahead.empty()) {
        return false;
    }
    return lookahead[0].getType().getInfo() == QPSTokenType::SUCH &&
           lookahead[1].getType().getInfo() == QPSTokenType::THAT;
}

bool QPSParser::isAtEnd() {
    return this->peek().getType().getInfo() == QPSTokenType::END_OF_FILE;
}

QPSToken QPSParser::advance() {
    if (!this->isAtEnd()) {
        this->current++;
    }
    return this->previous();
}

QPSToken QPSParser::peek() {
    return *this->tokens.at(this->current);
}

// will return empty list if not enough tokens to peek
std::vector<QPSToken> QPSParser::peekAhead(int lookahead) {
    if (this->current + lookahead < this->tokens.size()) {
        std::vector<QPSToken> lookaheadTokens;
        for (int i = 0; i < lookahead; i++) {
            lookaheadTokens.push_back(*this->tokens.at(this->current + i));
        }
        return lookaheadTokens;
    } else {
        return {};
    }
}

QPSToken QPSParser::previous() {
    return *this->tokens.at(this->current - 1);
}

bool QPSParser::checkPrevious(QPSTokenType::QPSTypeInfo type) {
    return this->previous().getType().getInfo() == type;
}


QPSToken QPSParser::consume(QPSTokenType::QPSTypeInfo type, const std::string &message) {
    if (this->check(type)) {
        return this->advance();
    }

    throw QPSParseException(message + " at [" + std::to_string(current) + "]");
}

std::shared_ptr<DeclarationClause> QPSParser::declaration() {
    std::vector<std::string> synonyms;
    std::string type;
    if (!this->match({QPSTokenType::STMT1, QPSTokenType::READ, QPSTokenType::PRINT, QPSTokenType::CALL, QPSTokenType::WHILE,
                 QPSTokenType::IF, QPSTokenType::ASSIGN, QPSTokenType::VARIABLE, QPSTokenType::CONSTANT,
                 QPSTokenType::PROCEDURE})) throw QPSParseException("at [" + std::to_string(current) + "]: expected declaration type.");
    QPSToken declarationType = this->previous();
    QPSToken entityType = this->synonym(this->consume(QPSTokenType::IDENTIFIER, "Expect identifier."));
    synonyms.push_back(entityType.getLexeme());
    while (this->match({QPSTokenType::COMMA})) {
        QPSToken synonym = this->synonym(this->consume(QPSTokenType::IDENTIFIER, "Expect identifier."));
        synonyms.push_back(synonym.getLexeme());
    }
    this->consume(QPSTokenType::SEMICOLON, "Expect ';' after declaration.");
    auto declarationCl = std::make_shared<DeclarationClause>();
    for (auto &synonym: synonyms) {
        declarationCl->addDeclaration(declarationType.getType(), synonym);
    }
    return declarationCl;
}

std::shared_ptr<SelectClause> QPSParser::select() {

    QPSToken declarationType = this->consume(QPSTokenType::SELECT, "Expect select type.");
    QPSToken entityType = this->synonym(this->consume(QPSTokenType::IDENTIFIER, "Expect identifier."));

    std::shared_ptr<SelectClause> selectCl = std::make_shared<SelectClause>();
    selectCl->addSelect(entityType.getLexeme());

    return selectCl;
}

std::shared_ptr<RelationshipClause> QPSParser::relationship() {
    std::shared_ptr<RelationshipClause> relationshipClause;

    if (this->check({QPSTokenType::PARENT, QPSTokenType::PARENT_T})) {
        relationshipClause = this->parent();
    } else if (this->check({QPSTokenType::FOLLOWS, QPSTokenType::FOLLOWS_T})) {
        relationshipClause = this->follow();
    } else if (this->check({QPSTokenType::USES, QPSTokenType::MODIFIES})) {
      relationshipClause = this->usesModifies();
    } else if (this->check({QPSTokenType::CALLS, QPSTokenType::CALLS_T})) {
        relationshipClause = this->calls();
    } else {
        relationshipClause = nullptr;
    }

    return relationshipClause;
}

std::shared_ptr<RelationshipClause> QPSParser::calls() {
    this->match({QPSTokenType::CALLS, QPSTokenType::CALLS_T});
    QPSToken relationshipType = this->previous();
    this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after relationship type.");
    auto t1 = entRef();
    this->consume(QPSTokenType::COMMA, "Expect ',' after entRef.");
    auto t2 = entRef();
    this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after relationship type.");

    RelationshipClause parentCl(relationshipType.getType().getInfo(), t1, QPSTokenType::ENT_REF, t2,
                                QPSTokenType::ENT_REF);

    return std::make_shared<RelationshipClause>(parentCl);
}

std::shared_ptr<RelationshipClause> QPSParser::parent() {

    this->match({QPSTokenType::PARENT, QPSTokenType::PARENT_T});
    QPSToken relationshipType = this->previous();
    this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after relationship type.");
    auto t1 = stmtRef();
    this->consume(QPSTokenType::COMMA, "Expect ',' after stmtRef.");
    auto t2 = stmtRef();
    this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after relationship type.");

    RelationshipClause parentCl(relationshipType.getType().getInfo(), t1, QPSTokenType::STMT_REF, t2,
                                QPSTokenType::STMT_REF);

    return std::make_shared<RelationshipClause>(parentCl);
}

std::shared_ptr<RelationshipClause> QPSParser::follow() {

    this->match({QPSTokenType::FOLLOWS, QPSTokenType::FOLLOWS_T});
    QPSToken relationshipType = this->previous();
    this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after relationship type.");
    auto t1 = stmtRef();
    this->consume(QPSTokenType::COMMA, "Expect ',' after stmtRef.");
    auto t2 = stmtRef();
    this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after relationship type.");

    RelationshipClause parentCl(relationshipType.getType().getInfo(), t1, QPSTokenType::STMT_REF, t2,
                                QPSTokenType::STMT_REF);

    return std::make_shared<RelationshipClause>(parentCl);
}

std::shared_ptr<RelationshipClause> QPSParser::usesModifies() {
  this->match({QPSTokenType::USES, QPSTokenType::MODIFIES});
  QPSToken relationshipType = this->previous();
    this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after relationship type.");
    auto t1 = stmtRef();
    this->consume(QPSTokenType::COMMA, "Expect ',' after stmtRef.");
    auto t2 = entRef();
    this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after relationship type.");
    RelationshipClause relCl(relationshipType.getType().getInfo(), t1, QPSTokenType::STMT_REF, t2,
                             QPSTokenType::ENT_REF);
    return std::make_shared<RelationshipClause>(relCl);
}

std::shared_ptr<PatternClause> QPSParser::pattern() {
    QPSToken synAssign = this->synonym(this->consume(QPSTokenType::IDENTIFIER, "Expect identifier."));

    this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after identifier.");
    QPSToken entRef = this->entRef();
    this->consume(QPSTokenType::COMMA, "Expect ',' after entRef.");
    QPSToken exprSpec = this->exprSpec();
    this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after expr spec.");

    PatternClause patternCl(synAssign.getLexeme(), entRef, QPSTokenType::QPSTypeInfo::ENT_REF, exprSpec,
                            QPSTokenType::EXPR_REF);

    return std::make_shared<PatternClause>(patternCl);
}

QPSToken QPSParser::stmtRef() {
    if (this->match({QPSTokenType::INTEGER, QPSTokenType::IDENTIFIER, QPSTokenType::WILDCARD})) {
        if (this->checkPrevious(QPSTokenType::INTEGER))
            return this->previous();

        if (this->checkPrevious(QPSTokenType::IDENTIFIER))
            return this->synonym(this->previous());

        if (this->checkPrevious(QPSTokenType::WILDCARD))
            return this->previous();
    }
    throw QPSParseException("at [" + std::to_string(current) + "]: invalid statement reference");
}

QPSToken QPSParser::entRef() {
    if (this->match({QPSTokenType::IDENTIFIER, QPSTokenType::WILDCARD, QPSTokenType::QUOTE})) {
        if (this->checkPrevious(QPSTokenType::IDENTIFIER))
            return synonym(this->previous());

        if (this->checkPrevious(QPSTokenType::WILDCARD))
            return this->previous();

        if (this->checkPrevious(QPSTokenType::QUOTE)) {
            QPSToken ident = this->consume(QPSTokenType::IDENTIFIER, "Expect identifier.");
            this->consume(QPSTokenType::QUOTE, "Expect quote.");

            QPSTokenType type(QPSTokenType::QUOTED_IDENT);
            QPSToken newToken = QPSToken(type, "\"" + ident.getLexeme() + "\"");
            return newToken;
        }
    }
    throw QPSParseException("at [" + std::to_string(current) + "]: invalid statement reference.");
}

QPSToken QPSParser::synonym(QPSToken t) {
    QPSTokenType type(QPSTokenType::SYNONYM);
    QPSToken newToken = QPSToken(type, t.getLexeme());
    return newToken;
}

QPSToken QPSParser::exprSpec() {
    if (this->check(QPSTokenType::WILDCARD)) {
        QPSToken t = this->consume(QPSTokenType::WILDCARD, "Expect wildcard.");
        if (this->check(QPSTokenType::QUOTE)) {
            this->consume(QPSTokenType::QUOTE, "Expect quote.");
            QPSToken expr = this->expr();
            this->consume(QPSTokenType::QUOTE, "Expect quote.");
            this->consume(QPSTokenType::WILDCARD, "Expect wildcard.");

            QPSTokenType type(QPSTokenType::EXPR_WILDCARD);
            QPSToken newToken = QPSToken(type, "\"" + expr.getLexeme() + "\"");
            return newToken;
        } else {
            return t;
        }
    }

    if (this->check(QPSTokenType::QUOTE)) {
        this->consume(QPSTokenType::QUOTE, "Expect quote.");
        QPSToken expr = this->expr();
        this->consume(QPSTokenType::QUOTE, "Expect quote.");

        QPSTokenType type(QPSTokenType::EXPR);
        QPSToken newToken = QPSToken(type, "\"" + expr.getLexeme() + "\"");
        return newToken;
    }

    throw QPSParseException("at [" + std::to_string(current) + "]: invalid expression spec.");
}

QPSToken QPSParser::expr() {
    QPSToken t1 = this->term();
    QPSToken t2 = this->exprTail();
    QPSTokenType type(QPSTokenType::EXPR);
    QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
    return newToken;
}

QPSToken QPSParser::exprTail() {
    if (this->check(QPSTokenType::PLUS)) {
        this->consume(QPSTokenType::PLUS, "Expect '+' after expression.");
        QPSToken t1 = this->term();
        QPSToken t2 = this->exprTail();
        QPSTokenType type(QPSTokenType::EXPR);
        QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
        return newToken;
    }
    if (this->check(QPSTokenType::MINUS)) {
        this->consume(QPSTokenType::MINUS, "Expect '-' after expression.");
        QPSToken t1 = this->term();
        QPSToken t2 = this->exprTail();
        QPSTokenType type(QPSTokenType::EXPR);
        QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
        return newToken;
    }
    return {QPSTokenType(QPSTokenType::EMPTY), ""};
}

QPSToken QPSParser::term() {
    QPSToken t1 = this->factor();
    QPSToken t2 = this->termTail();
    QPSTokenType type(QPSTokenType::TERM);
    QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
    return newToken;
}

QPSToken QPSParser::termTail() {
    if (this->check(QPSTokenType::STAR)) {
        this->consume(QPSTokenType::STAR, "Expect '+' after expression.");
        QPSToken t1 = this->factor();
        QPSToken t2 = this->termTail();
        QPSTokenType type(QPSTokenType::TERM);
        QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
        return newToken;
    }
    if (this->check(QPSTokenType::SLASH)) {
        this->consume(QPSTokenType::SLASH, "Expect '/' after expression.");
        QPSToken t1 = this->term();
        QPSToken t2 = this->exprTail();
        QPSTokenType type(QPSTokenType::TERM);
        QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
        return newToken;
    }
    if (this->check(QPSTokenType::PERCENT)) {
        this->consume(QPSTokenType::PERCENT, "Expect '%' after expression.");
        QPSToken t1 = this->term();
        QPSToken t2 = this->exprTail();
        QPSTokenType type(QPSTokenType::TERM);
        QPSToken newToken = QPSToken(type, t1.getLexeme() + t2.getLexeme());
        return newToken;
    }
    return {QPSTokenType(QPSTokenType::EMPTY), ""};
}

QPSToken QPSParser::factor() {
    if (this->check(QPSTokenType::INTEGER))
        return this->consume(QPSTokenType::INTEGER, "Expect integer.");
    if (this->check(QPSTokenType::IDENTIFIER))
        return this->consume(QPSTokenType::IDENTIFIER, "Expect identifier.");
    if (this->check(QPSTokenType::LEFT_PAREN)) {
        this->consume(QPSTokenType::LEFT_PAREN, "Expect '(' after expression.");
        QPSToken t = this->expr();
        this->consume(QPSTokenType::RIGHT_PAREN, "Expect ')' after expression.");
        QPSTokenType type(QPSTokenType::FACTOR);
        QPSToken newToken = QPSToken(type, t.getLexeme());
    }
    throw QPSParseException("at [" + std::to_string(current) + "]: invalid factor.");

}


std::shared_ptr<IntermediateQuery> QPSParser::parse() {
    auto query = std::make_shared<IntermediateQuery>();

    while (isDeclaration()) {
        std::shared_ptr<DeclarationClause> declaration = this->declaration();
        query->addClause(declaration);
    }

    if (this->check(QPSTokenType::SELECT)) {
        std::shared_ptr<SelectClause> select = this->select();
        query->addClause(select);
    } else {
        throw QPSParseException("at [" + std::to_string(current) + "]: Expect select clause.");
    }

    while (isSuchThat() || this->check({QPSTokenType::PATTERN})) {

        if (isSuchThat()) {
            this->consume(QPSTokenType::SUCH, "Expect 'such'.");
            this->consume(QPSTokenType::THAT, "Expect 'that' after 'such'.");

            if (isRelationship()) {
                std::shared_ptr<RelationshipClause> relationship = this->relationship();

                if (relationship) query->addClause(relationship);
            } else {
                throw QPSParseException("at [" + std::to_string(current) + "]: Expect relationship.");
            }
        }

        if (this->match({QPSTokenType::PATTERN})) {
            std::shared_ptr<PatternClause> pattern = this->pattern();
            if (pattern) query->addClause(pattern);
        }
    }

    if (!isAtEnd()) throw QPSParseException("at [" + std::to_string(current) + "]: Expect end of file.");
    return query;
}
