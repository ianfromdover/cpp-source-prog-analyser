//
// Created by Alex on 15/2/2024.
//

#include <map>
#include "QPSMultiCharacterStrategy.h"
#include "qps/exceptions/QPSTokenizeException.h"


bool QPSMultiCharacterStrategy::tokenize(char character, std::stringstream &stream, QPSTokenList &tokens,
                                         bool &declarationStarted) {
    if (std::isalpha(character)) {
        std::string name = character + readWhile(stream, [](char ch) { return std::isalnum(ch); });
        if (starAllowed(name) && '*' == static_cast<char>(stream.peek())){
            name += static_cast<char>(stream.get());
        }
        if (declarationStarted) {
            if (tokens.getTokens().back()->getType().getInfo() == QPSTokenType::SELECT) {
                declarationStarted = false;
                if (name == "BOOLEAN") {
                    tokens.addToken(QPSTokenType::BOOLEAN, name);
                    return true;
                }
            }
            tokens.addToken(QPSTokenType::IDENTIFIER, name);
        } else if (expectSynonymNext(name, tokens)) {
            declarationStarted = true;
        }
    } else if (std::isdigit(character)) {
        if (character == '0' && std::isalnum(stream.peek())) {
            throw QPSTokenizeException("Invalid Integer with leading zero");
        }
        std::string integer = character + readWhile(stream, [](char ch) { return std::isdigit(ch); });
        tokens.addToken(QPSTokenType::INTEGER, integer);
    } else if (character != ' ' && character != '\n') {
        //Do nothing
    }
    return true;
}

bool QPSMultiCharacterStrategy::expectSynonymNext(const std::string &name, QPSTokenList &tokens) {
    static const std::map<std::string, QPSTokenType::QPSTypeInfo> declarationKeywords = {
            // Design entities
            {"stmt",      QPSTokenType::STMT1},
            {"read",      QPSTokenType::READ},
            {"print",     QPSTokenType::PRINT},
            {"while",     QPSTokenType::WHILE},
            {"if",        QPSTokenType::IF},
            {"call",      QPSTokenType::CALL},
            {"assign",    QPSTokenType::ASSIGN},
            {"variable",  QPSTokenType::VARIABLE},
            {"constant",  QPSTokenType::CONSTANT},
            {"procedure", QPSTokenType::PROCEDURE},

            // Relations
            {"Follows",   QPSTokenType::FOLLOWS},
            {"Follows*",  QPSTokenType::FOLLOWS_T},
            {"Parent",    QPSTokenType::PARENT},
            {"Parent*",   QPSTokenType::PARENT_T},
            {"Modifies", QPSTokenType::MODIFIES},
            {"Uses", QPSTokenType::USES},
            {"Calls", QPSTokenType::CALLS},
            {"Calls*",    QPSTokenType::CALLS_T},
            {"Next",    QPSTokenType::NEXT},
            {"Next*",    QPSTokenType::NEXT_T},
            {"Affects",    QPSTokenType::AFFECTS},

            {"Select",    QPSTokenType::SELECT},
            {"that",      QPSTokenType::THAT},
            {"pattern",   QPSTokenType::PATTERN},
            {"and",   QPSTokenType::AND},
    };

    auto it = declarationKeywords.find(name);
    if (it != declarationKeywords.end()) {
        if (it->second == QPSTokenType::THAT) {
            if (!tokens.getTokens().empty() && tokens.getTokens().back()->getLexeme() == "such") {
                QPSToken t = *tokens.getTokens().back();
                tokens.getTokens().pop_back();
                tokens.addToken(QPSTokenType::SUCH, t.getLexeme());
                tokens.addToken(QPSTokenType::THAT, name);
            } else {
                tokens.addToken(QPSTokenType::IDENTIFIER, name);
            }
            return false;
        }
        if (it->second == QPSTokenType::AND) {
          if (!tokens.getTokens().empty() &&
              tokens.getTokens().back()->getType().getInfo() ==
                  QPSTokenType::RIGHT_PAREN) {
            tokens.addToken(it->second, name);
          } else {
            tokens.addToken(QPSTokenType::IDENTIFIER, name);
          }
          return false;
        }
        if (it->second == QPSTokenType::BOOLEAN) {
          if (!tokens.getTokens().empty() && tokens.getTokens().back()->getType().getInfo() == QPSTokenType::SELECT) {
            QPSToken t = *tokens.getTokens().back();
            tokens.getTokens().pop_back();
            tokens.addToken(QPSTokenType::SUCH, t.getLexeme());
            tokens.addToken(QPSTokenType::THAT, name);
          } else {
            tokens.addToken(QPSTokenType::IDENTIFIER, name);
          }
        }
        tokens.addToken(it->second, name);
        return true;
    } else {
        tokens.addToken(QPSTokenType::IDENTIFIER, name);
        return false;
    }
}

std::string
QPSMultiCharacterStrategy::readWhile(std::stringstream &stream, const std::function<bool(char)> &condition) {
    std::string result;
    char nextChar = static_cast<char>(stream.peek());
    while (condition(nextChar)) {
        result += static_cast<char>(stream.get());
        nextChar = static_cast<char>(stream.peek());
    }
    return result;
}

bool QPSMultiCharacterStrategy::starAllowed(const std::string& name) {
    static const std::map<std::string, QPSTokenType::QPSTypeInfo> declarationKeywords = {
            // Design entities
            {"Parent",      QPSTokenType::PARENT},
            {"Follows",      QPSTokenType::FOLLOWS},
            {"Calls",      QPSTokenType::CALLS},
            {"Next", QPSTokenType::NEXT}};

    return declarationKeywords.find(name) != declarationKeywords.end();
}
