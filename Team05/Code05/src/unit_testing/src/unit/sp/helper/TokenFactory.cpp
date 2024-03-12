//
// Created by Chua Bing Quan on 26/2/24.
//
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "sp/tokenizer/token/Token.h"

using TokenStream = std::shared_ptr<std::vector<std::shared_ptr<Token>>>;

class TokenFactory {
private:
    static std::string opToString(TokenType op) {
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

    static TokenStream createLogical(const TokenStream& left, TokenType op, const TokenStream& right) {
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

    static TokenStream createBinary(const TokenStream& left, TokenType op, const TokenStream& right) {
        const auto stream = TokenFactory::createTokenStream({});
        stream->insert(stream->end(), left->begin(), left->end());
        stream->push_back(TokenFactory::createToken(op, TokenFactory::opToString(op)));
        stream->insert(stream->end(), right->begin(), right->end());
        return stream;
    }

public:
    static std::shared_ptr<Token> createToken(TokenType type, const std::string& lexeme) {
        return std::make_shared<Token>(type, lexeme);
    }

    static TokenStream createTokenStream(const std::initializer_list<std::shared_ptr<Token>>& tokens) {
        return std::make_shared<std::vector<std::shared_ptr<Token>>>(tokens);
    }

    // Top-level creators
    static TokenStream mergeStreams(const std::initializer_list<TokenStream>& streams) {
        const auto merged = TokenFactory::createTokenStream({});
        for (const auto& stream : streams) {
            merged->insert(merged->end(), stream->begin(), stream->end());
        }
        return merged;
    }

    static TokenStream createProgram(const std::initializer_list<TokenStream>& procedures) {
        const auto stream = TokenFactory::mergeStreams(procedures);
        stream->push_back(TokenFactory::createToken(TokenType::END_OF_FILE, "EOF"));
        return stream;
    }

    static TokenStream createProcedure(const std::string& name, const std::initializer_list<TokenStream>& body) {
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

    // Expression creators
    static TokenStream createGrouping(const TokenStream& expr) {
        const auto stream = TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
        });
        stream->insert(stream->end(), expr->begin(), expr->end());
        stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));
        return stream;
    }

    static TokenStream createAndExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createLogical(left, TokenType::AND, right);
    }

    static TokenStream createOrExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createLogical(left, TokenType::OR, right);
    }

    static TokenStream createNotExpr(const TokenStream& right) {
        const auto stream = TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::BANG, "!"),
            TokenFactory::createToken(TokenType::LEFT_PAREN, "("),
        });
        stream->insert(stream->end(), right->begin(), right->end());
        stream->push_back(TokenFactory::createToken(TokenType::RIGHT_PAREN, ")"));
        return stream;
    }

    static TokenStream createAddExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::ADD, right);
    }

    static TokenStream createSubtractExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::SUBTRACT, right);
    }

    static TokenStream createMultiplyExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::MULTIPLY, right);
    }

    static TokenStream createDivideExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::DIVIDE, right);
    }

    static TokenStream createModExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::MOD, right);
    }

    static TokenStream createGreaterExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::GREATER, right);
    }

    static TokenStream createGreaterEqualExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::GREATER_EQUAL, right);
    }

    static TokenStream createLesserExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::LESSER, right);
    }

    static TokenStream createLesserEqualExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::LESSER_EQUAL, right);
    }

    static TokenStream createEqualsExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::EQUAL_EQUAL, right);
    }

    static TokenStream createNotEqualsExpr(const TokenStream& left, const TokenStream& right) {
        return TokenFactory::createBinary(left, TokenType::BANG_EQUAL, right);
    }

    static TokenStream createVariable(const std::string& name) {
        return TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::NAME, name),
        });
    }

    static TokenStream createInt(int value) {
        return TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::INTEGER, std::to_string(value)),
        });
    }

    // Statement creators
    static TokenStream createRead(const std::string& variable) {
        return TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::READ, "read"),
            TokenFactory::createToken(TokenType::NAME, variable),
            TokenFactory::createToken(TokenType::SEMICOLON, ";"),
        });
    }

    static TokenStream createPrint(const std::string& variable) {
        return TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::PRINT, "print"),
            TokenFactory::createToken(TokenType::NAME, variable),
            TokenFactory::createToken(TokenType::SEMICOLON, ";"),
        });
    }

    static TokenStream createCall(const std::string& procedure) {
        return TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::CALL, "call"),
            TokenFactory::createToken(TokenType::NAME, procedure),
            TokenFactory::createToken(TokenType::SEMICOLON, ";"),
        });
    }

    static TokenStream createWhile(const TokenStream& condition, const std::initializer_list<TokenStream>& body) {
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

    static TokenStream createIf(const TokenStream& condition, const std::initializer_list<TokenStream>& thenBranch, const std::initializer_list<TokenStream>& elseBranch) {
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

    static TokenStream createAssign(const std::string& variable, const TokenStream& value) {
        const auto stream = TokenFactory::createTokenStream({
            TokenFactory::createToken(TokenType::NAME, variable),
            TokenFactory::createToken(TokenType::ASSIGN, "="),
        });
        stream->insert(stream->end(), value->begin(), value->end());
        stream->push_back(TokenFactory::createToken(TokenType::SEMICOLON, ";"));
        return stream;
    }
};