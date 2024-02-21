//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_QPSPARSER_H
#define SPA_QPSPARSER_H

#include <memory>
#include <vector>
#include "qps/tokenizer/QPSToken.h"
#include "qps/tokenizer/QPSTokenList.h"
#include "DeclarationClause.h"
#include "SelectClause.h"
#include "RelationshipClause.h"
#include "PatternClause.h"
#include "IntermediateQuery.h"


    class QPSParser {
    private:
        //static std::initializer_list<>
        int current = 0;
        std::vector<std::shared_ptr<QPSToken>> tokens;

    public:
        explicit QPSParser(QPSTokenList &tokens) : tokens(tokens.getTokens()) {};

        std::shared_ptr<IntermediateQuery> parse();

    private:
        bool match(std::initializer_list<QPSTokenType::QPSTypeInfo> types);

        bool check(QPSTokenType::QPSTypeInfo type);

        bool check(std::initializer_list<QPSTokenType::QPSTypeInfo> types);

        bool isDeclaration();

        bool isRelationship();

        bool isSuchThat();

        bool isAtEnd();

        QPSToken advance();

        QPSToken peek();

        std::vector<QPSToken> peekAhead(int lookahead);

        QPSToken previous();

        bool checkPrevious(QPSTokenType::QPSTypeInfo type);

        QPSToken consume(QPSTokenType::QPSTypeInfo type, const std::string& message);

        std::shared_ptr<DeclarationClause> declaration();

        std::shared_ptr<SelectClause> select();

        std::shared_ptr<RelationshipClause> relationship();

        std::shared_ptr<RelationshipClause> parent();
        std::shared_ptr<RelationshipClause> follow();
        std::shared_ptr<RelationshipClause> uses();
        std::shared_ptr<RelationshipClause> modifies();

        std::shared_ptr<PatternClause> pattern();

        QPSToken stmtRef();

        QPSToken entRef();

        QPSToken synonym(QPSToken t);

        QPSToken exprSpec();

        QPSToken expr();
        QPSToken exprTail();

        QPSToken term();
        QPSToken termTail();

        QPSToken factor();

    };



#endif //SPA_QPSPARSER_H
