//
// Created by Chua Bing Quan on 21/3/24.
//

#ifndef SPA_TOKENFACTORY_H
#define SPA_TOKENFACTORY_H

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "sp/tokenizer/token/Token.h"

using TokenStream = std::shared_ptr<std::vector<std::shared_ptr<Token>>>;

class TokenFactory {
private:
    static std::string opToString(TokenType op);
    static TokenStream createLogical(const TokenStream& left, TokenType op, const TokenStream& right);
    static TokenStream createBinary(const TokenStream& left, TokenType op, const TokenStream& right);
public:
    // Helper creators
    static std::shared_ptr<Token> createToken(TokenType type, const std::string& lexeme);
    static TokenStream createTokenStream(const std::initializer_list<std::shared_ptr<Token>>& tokens);
    static TokenStream mergeStreams(const std::initializer_list<TokenStream>& streams);
    // Top-level creators
    static TokenStream createProgram(const std::initializer_list<TokenStream>& procedures);
    static TokenStream createProcedure(const std::string& name, const std::initializer_list<TokenStream>& body);
    // Expression creators
    static TokenStream createGrouping(const TokenStream& expr);
    static TokenStream createAndExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createOrExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createNotExpr(const TokenStream& right);
    static TokenStream createAddExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createSubtractExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createMultiplyExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createDivideExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createModExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createGreaterExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createGreaterEqualExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createLesserExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createLesserEqualExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createEqualsExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createNotEqualsExpr(const TokenStream& left, const TokenStream& right);
    static TokenStream createVariable(const std::string& name);
    static TokenStream createInt(int value);
    // Statement creators
    static TokenStream createRead(const std::string& variable);
    static TokenStream createPrint(const std::string& variable);
    static TokenStream createCall(const std::string& procedure);
    static TokenStream createWhile(const TokenStream& condition, const std::initializer_list<TokenStream>& body);
    static TokenStream createIf(const TokenStream& condition,
                                const std::initializer_list<TokenStream>& thenBranch,
                                const std::initializer_list<TokenStream>& elseBranch);
    static TokenStream createAssign(const std::string& variable, const TokenStream& value);
};

#endif //SPA_TOKENFACTORY_H
