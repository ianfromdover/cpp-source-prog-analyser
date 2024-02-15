//
// Created by Alex on 15/2/2024.
//

#include <map>
#include "MultiCharacterStrategy.h"

namespace qps {
    bool MultiCharacterStrategy::tokenize(char character, std::stringstream &stream, TokenList &tokens,
                                          bool &declarationStarted) {
        if (std::isalpha(character)) {
            std::string name = character + readWhile(stream, [](char ch) { return std::isalnum(ch); });
            if (declarationStarted) {
                if (tokens.getTokens().back()->getType().getInfo() == TokenType::SELECT) {
                    declarationStarted = false;
                }
                tokens.addToken(TokenType::IDENTIFIER, name);
            } else if (expectSynonymNext(name, tokens, declarationStarted)) {
                declarationStarted = true;
            }
        } else if (std::isdigit(character)) {
            std::string integer = character + readWhile(stream, [](char ch) { return std::isdigit(ch); });
            tokens.addToken(TokenType::INTEGER, integer);
        } else if (character != ' ' && character != '\n') {
            //Do nothing
        }
        return true;
    }

    bool
    MultiCharacterStrategy::expectSynonymNext(const std::string &name, TokenList &tokens, bool &declarationStarted) {
        static const std::map<std::string, TokenType::TypeInfo> declarationKeywords = {
                {"stmt",    TokenType::STMT},
                {"Select",  TokenType::SELECT},
                {"that",    TokenType::THAT},
                {"Parent",  TokenType::PARENT},
                {"Pattern", TokenType::PATTERN}
        };

        auto it = declarationKeywords.find(name);
        if (it != declarationKeywords.end()) {
            if (it->second == TokenType::THAT) {
                if (tokens.getTokens().back()->getLexeme() == "such") {
                    Token t = *tokens.getTokens().back();
                    tokens.getTokens().pop_back();
                    tokens.addToken(TokenType::SUCH, t.getLexeme());
                    tokens.addToken(TokenType::THAT, name);
                } else {
                    tokens.addToken(TokenType::IDENTIFIER, name);
                }
                return false;
            }
            tokens.addToken(it->second, name);
            return true;
        } else {
            tokens.addToken(TokenType::IDENTIFIER, name);
            return false;
        }
    }

    std::string
    MultiCharacterStrategy::readWhile(std::stringstream &stream, const std::function<bool(char)> &condition) {
        std::string result;
        char nextChar = static_cast<char>(stream.peek());
        while (condition(nextChar)) {
            result += static_cast<char>(stream.get());
            nextChar = static_cast<char>(stream.peek());
        }
        return result;
    }
}
