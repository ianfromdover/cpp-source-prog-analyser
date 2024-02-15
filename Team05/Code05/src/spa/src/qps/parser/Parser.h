//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_PARSER_H
#define SPA_PARSER_H

#include <memory>
#include <vector>
#include "qps/tokenizer/Token.h"
#include "qps/tokenizer/TokenList.h"
#include "DeclarationClause.h"
#include "SelectClause.h"
#include "RelationshipClause.h"
#include "PatternClause.h"

namespace qps {
    class Parser {
    private:
        int current = 0;
        std::vector<std::shared_ptr<Token>> tokens;

    public:
        explicit Parser(TokenList &tokens) : tokens(tokens.getTokens()) {};

        void parse();

    private:
        bool match(std::initializer_list<TokenType::TypeInfo> types);

        bool check(TokenType::TypeInfo type);

        bool check(std::initializer_list<TokenType::TypeInfo> types);

        bool isDeclaration();

        bool isRelationship();

        bool isSuchThat();

        bool isAtEnd();

        Token advance();

        Token peek();

        std::vector<Token> peekAhead(int lookahead);

        Token previous();

        Token consume(TokenType::TypeInfo type, const std::string& message);

        std::shared_ptr<DeclarationClause> declaration();

        std::shared_ptr<SelectClause> select();

        std::shared_ptr<RelationshipClause> relationship();

        std::shared_ptr<RelationshipClause> parent();

        std::shared_ptr<PatternClause> pattern();

        Token stmtRef();

        Token entRef();

        Token synonym();

        Token exprSpec();

        Token expr();
        Token exprTail();

        Token term();
        Token termTail();

        Token factor();

    };
}


#endif //SPA_PARSER_H
