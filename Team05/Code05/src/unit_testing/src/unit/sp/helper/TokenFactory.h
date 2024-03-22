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

using TokenStream = std::vector<std::shared_ptr<Token>>;

class TokenFactory {
private:
    static std::string opToString(TokenType op);
    static std::shared_ptr<TokenStream> createLogical(const std::shared_ptr<TokenStream>& left,
                                                      TokenType op, const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createBinary(const std::shared_ptr<TokenStream>& left, TokenType op,
                                                     const std::shared_ptr<TokenStream>& right);
public:
    // Helper creators
    static std::shared_ptr<Token> createToken(TokenType type, const std::string& lexeme);
    static std::shared_ptr<TokenStream> createTokenStream(const std::initializer_list<std::shared_ptr<Token>>& tokens);
    static std::shared_ptr<TokenStream> mergeStreams(const std::initializer_list<std::shared_ptr<TokenStream>>& streams);
    // Top-level creators
    static std::shared_ptr<TokenStream> createProgram(const std::initializer_list<std::shared_ptr<TokenStream>>& procedures);
    static std::shared_ptr<TokenStream> createProcedure(const std::string& name,
                                                        const std::initializer_list<std::shared_ptr<TokenStream>>& body);
    // Expression creators
    static std::shared_ptr<TokenStream> createGrouping(const std::shared_ptr<TokenStream>& expr);
    static std::shared_ptr<TokenStream> createAndExpr(const std::shared_ptr<TokenStream>& left,
                                                      const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createOrExpr(const std::shared_ptr<TokenStream>& left,
                                                     const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createNotExpr(const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createAddExpr(const std::shared_ptr<TokenStream>& left,
                                                      const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createSubtractExpr(const std::shared_ptr<TokenStream>& left,
                                                           const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createMultiplyExpr(const std::shared_ptr<TokenStream>& left,
                                                           const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createDivideExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createModExpr(const std::shared_ptr<TokenStream>& left,
                                                      const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createGreaterExpr(const std::shared_ptr<TokenStream>& left,
                                                          const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createGreaterEqualExpr(const std::shared_ptr<TokenStream>& left,
                                                               const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createLesserExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createLesserEqualExpr(const std::shared_ptr<TokenStream>& left,
                                                              const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createEqualsExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createNotEqualsExpr(const std::shared_ptr<TokenStream>& left,
                                                            const std::shared_ptr<TokenStream>& right);
    static std::shared_ptr<TokenStream> createVariable(const std::string& name);
    static std::shared_ptr<TokenStream> createInt(int value);
    // Statement creators
    static std::shared_ptr<TokenStream> createRead(const std::string& variable);
    static std::shared_ptr<TokenStream> createPrint(const std::string& variable);
    static std::shared_ptr<TokenStream> createCall(const std::string& procedure);
    static std::shared_ptr<TokenStream> createWhile(const std::shared_ptr<TokenStream>& condition,
                                                    const std::initializer_list<std::shared_ptr<TokenStream>>& body);
    static std::shared_ptr<TokenStream> createIf(const std::shared_ptr<TokenStream>& condition,
                                const std::initializer_list<std::shared_ptr<TokenStream>>& thenBranch,
                                const std::initializer_list<std::shared_ptr<TokenStream>>& elseBranch);
    static std::shared_ptr<TokenStream> createAssign(const std::string& variable, const std::shared_ptr<TokenStream>& value);
};

#endif //SPA_TOKENFACTORY_H
