//
// Created by Chua Bing Quan on 21/3/24.
//

#include "TokenFactory.h"

std::string TokenFactory::opToString(TokenType op) {
    switch (op) {
        case TokenType::BANG_EQUAL: return "!=";
        case TokenType::EQUAL_EQUAL: return "==";
        case TokenType::GREATER: return ">";
        case TokenType::GREATER_EQUAL: return ">=";
        case TokenType::LESSER_EQUAL: return "<=";
        case TokenType::LESSER: return "<";
        case TokenType::OR: return "||";
        case TokenType::AND: return "&&";
        case TokenType::ADD: return "+";
        case TokenType::SUBTRACT: return "-";
        case TokenType::MULTIPLY: return "*";
        case TokenType::DIVIDE: return "/";
        case TokenType::MOD: return "%";
        default: throw std::runtime_error("TokenFactory expects operator for string conversion");
    }
}

std::shared_ptr<TokenStream> TokenFactory::createLogical(const std::shared_ptr<TokenStream>& left, TokenType op,
                                                         const std::shared_ptr<TokenStream>& right) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
    });
    stream->insert(stream->end(), left->begin(), left->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));

    stream->push_back(TokenFactory::createToken(op, TokenFactory::opToString(op)));

    stream->push_back(TokenFactory::createToken(TokenType::LEFT_PAREN, "("));
    stream->insert(stream->end(), right->begin(), right->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));

    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createBinary(const std::shared_ptr<TokenStream>& left, TokenType op,
                                                        const std::shared_ptr<TokenStream>& right) {
    const auto stream = TokenFactory::createTokenStream({});
    stream->insert(stream->end(), left->begin(), left->end());
    stream->push_back(TokenFactory::createToken(op, TokenFactory::opToString(op)));
    stream->insert(stream->end(), right->begin(), right->end());
    return stream;
}

std::shared_ptr<Token> TokenFactory::createToken(TokenType type, const std::string& lexeme) {
    return std::make_shared<Token>(type, lexeme);
}

std::shared_ptr<TokenStream> TokenFactory::createTokenStream(const std::initializer_list<std::shared_ptr<Token>>& tokens) {
    return std::make_shared<std::vector<std::shared_ptr<Token>>>(tokens);
}

std::shared_ptr<TokenStream> TokenFactory::mergeStreams(const std::initializer_list<std::shared_ptr<TokenStream>>& streams) {
    const auto merged = TokenFactory::createTokenStream({});
    for (const auto& stream : streams) {
        merged->insert(merged->end(), stream->begin(), stream->end());
    }
    return merged;
}

std::shared_ptr<TokenStream> TokenFactory::createProgram(const std::initializer_list<std::shared_ptr<TokenStream>>& procedures) {
    const auto stream = TokenFactory::mergeStreams(procedures);
    stream->push_back(TokenFactory::createToken(TokenType::END_OF_FILE, "EOF"));
    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createProcedure(const std::string& name,
                                                           const std::initializer_list<std::shared_ptr<TokenStream>>& body) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::PROCEDURE, "procedure"),
        TokenFactory::createToken(TokenType::NAME, name),
        TokenFactory::createToken(TokenType::LEFT_BRACE, "{"),
    });
    const auto mergedBody = TokenFactory::mergeStreams(body);
    stream->insert(stream->end(), mergedBody->begin(), mergedBody->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_BRACE, "}"));
    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createGrouping(const std::shared_ptr<TokenStream>& expr) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
    });
    stream->insert(stream->end(), expr->begin(), expr->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));
    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createAndExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createLogical(left, TokenType::AND, right);
}

std::shared_ptr<TokenStream> TokenFactory::createOrExpr(const std::shared_ptr<TokenStream>& left,
                                                        const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createLogical(left, TokenType::OR, right);
}

std::shared_ptr<TokenStream> TokenFactory::createNotExpr(const std::shared_ptr<TokenStream>& right) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::BANG, "!"),
        TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
    });
    stream->insert(stream->end(), right->begin(), right->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));
    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createAddExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::ADD, right);
}

std::shared_ptr<TokenStream> TokenFactory::createSubtractExpr(const std::shared_ptr<TokenStream>& left,
                                                              const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::SUBTRACT, right);
}

std::shared_ptr<TokenStream> TokenFactory::createMultiplyExpr(const std::shared_ptr<TokenStream>& left,
                                                              const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::MULTIPLY, right);
}

std::shared_ptr<TokenStream> TokenFactory::createDivideExpr(const std::shared_ptr<TokenStream>& left,
                                                            const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::DIVIDE, right);
}

std::shared_ptr<TokenStream> TokenFactory::createModExpr(const std::shared_ptr<TokenStream>& left,
                                                         const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::MOD, right);
}

std::shared_ptr<TokenStream> TokenFactory::createGreaterExpr(const std::shared_ptr<TokenStream>& left,
                                                             const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::GREATER, right);
}

std::shared_ptr<TokenStream> TokenFactory::createGreaterEqualExpr(const std::shared_ptr<TokenStream>& left,
                                                                  const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::GREATER_EQUAL, right);
}

std::shared_ptr<TokenStream> TokenFactory::createLesserExpr(const std::shared_ptr<TokenStream>& left,
                                                            const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::LESSER, right);
}

std::shared_ptr<TokenStream> TokenFactory::createLesserEqualExpr(const std::shared_ptr<TokenStream>& left,
                                                                 const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::LESSER_EQUAL, right);
}

std::shared_ptr<TokenStream> TokenFactory::createEqualsExpr(const std::shared_ptr<TokenStream>& left,
                                                            const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::EQUAL_EQUAL, right);
}

std::shared_ptr<TokenStream> TokenFactory::createNotEqualsExpr(const std::shared_ptr<TokenStream>& left,
                                                               const std::shared_ptr<TokenStream>& right) {
    return TokenFactory::createBinary(left, TokenType::BANG_EQUAL, right);
}

std::shared_ptr<TokenStream> TokenFactory::createVariable(const std::string& name) {
    return TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::NAME, name),
    });
}

std::shared_ptr<TokenStream> TokenFactory::createInt(int value) {
    return TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::INTEGER, std::to_string(value)),
    });
}

std::shared_ptr<TokenStream> TokenFactory::createRead(const std::string& variable) {
    return TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::READ, "read"),
        TokenFactory::createToken(TokenType::NAME, variable),
        TokenFactory::createToken(TokenType::SEMICOLON, ";"),
    });
}

std::shared_ptr<TokenStream> TokenFactory::createPrint(const std::string& variable) {
    return TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::PRINT, "print"),
        TokenFactory::createToken(TokenType::NAME, variable),
        TokenFactory::createToken(TokenType::SEMICOLON, ";"),
    });
}

std::shared_ptr<TokenStream> TokenFactory::createCall(const std::string& procedure) {
    return TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::CALL, "call"),
        TokenFactory::createToken(TokenType::NAME, procedure),
        TokenFactory::createToken(TokenType::SEMICOLON, ";"),
    });
}

std::shared_ptr<TokenStream> TokenFactory::createWhile(const std::shared_ptr<TokenStream>& condition,
                                                       const std::initializer_list<std::shared_ptr<TokenStream>>& body) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::WHILE, "while"),
        TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
    });
    stream->insert(stream->end(), condition->begin(), condition->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));
    stream->push_back(TokenFactory::createToken(TokenType::LEFT_BRACE, "{"));
    const auto mergedBody = TokenFactory::mergeStreams(body);
    stream->insert(stream->end(), mergedBody->begin(), mergedBody->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_BRACE, "}"));
    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createIf(const std::shared_ptr<TokenStream>& condition,
                                   const std::initializer_list<std::shared_ptr<TokenStream>>& thenBranch,
                                   const std::initializer_list<std::shared_ptr<TokenStream>>& elseBranch) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::IF, "if"),
        TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
    });
    stream->insert(stream->end(), condition->begin(), condition->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));

    stream->push_back(TokenFactory::createToken(TokenType::THEN, "then"));
    stream->push_back(TokenFactory::createToken(TokenType::LEFT_BRACE, "{"));
    const auto mergedThenBranch = TokenFactory::mergeStreams(thenBranch);
    stream->insert(stream->end(), mergedThenBranch->begin(), mergedThenBranch->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_BRACE, "}"));

    stream->push_back(TokenFactory::createToken(TokenType::ELSE, "else"));
    stream->push_back(TokenFactory::createToken(TokenType::LEFT_BRACE, "{"));
    const auto mergedElseBranch = TokenFactory::mergeStreams(elseBranch);
    stream->insert(stream->end(), mergedElseBranch->begin(), mergedElseBranch->end());
    stream->push_back(TokenFactory::createToken(TokenType::RIGHT_BRACE, "}"));

    return stream;
}

std::shared_ptr<TokenStream> TokenFactory::createAssign(const std::string& variable,
                                                        const std::shared_ptr<TokenStream>& value) {
    const auto stream = TokenFactory::createTokenStream({
        TokenFactory::createToken(TokenType::NAME, variable),
        TokenFactory::createToken(TokenType::ASSIGN, "="),
    });
    stream->insert(stream->end(), value->begin(), value->end());
    stream->push_back(TokenFactory::createToken(TokenType::SEMICOLON, ";"));
    return stream;
}