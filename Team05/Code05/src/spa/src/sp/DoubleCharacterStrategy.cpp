#include "DoubleCharacterStrategy.h"

bool DoubleCharacterStrategy::tokenize(char character, std::stringstream& stream, TokenList& tokens, bool& prevTokenIsKeyword) {
    TokenType::TypeInfo type;
    std::string lexeme(1, character);
    bool doubleCharacter = false;

    // Check if next character forms a double character token
    switch(character) {
        case '=':
            doubleCharacter = stream.peek() == '=';
            type = doubleCharacter ? TokenType::EQUAL_EQUAL : TokenType::ASSIGN;
            break;
        case '>':
            doubleCharacter = stream.peek() == '=';
            type = doubleCharacter ? TokenType::GREATER_EQUAL : TokenType::GREATER;
            break;
        case '!':
            doubleCharacter = stream.peek() == '=';
            type = doubleCharacter ? TokenType::BANG_EQUAL : TokenType::BANG;
            break;
        case '<':
            doubleCharacter = stream.peek() == '=';
            type = doubleCharacter ? TokenType::LESSER_EQUAL : TokenType::LESSER;
            break;
        case '|':
            doubleCharacter = stream.peek() == '|';
            type = doubleCharacter ? TokenType::OR : TokenType::UNKNOWN; // Assuming OR only valid as double char
            break;
        case '&':
            doubleCharacter = stream.peek() == '&';
            type = doubleCharacter ? TokenType::AND : TokenType::UNKNOWN; // Assuming AND only valid as double char
            break;
        default:
            return false; // No single or double character token recognized
    }

    if (doubleCharacter) {
        lexeme += static_cast<char>(stream.get()); // Append the second character to lexeme
    }

    tokens.addToken(type, lexeme);
    prevTokenIsKeyword = false; // Reset keyword flag for all tokens handled here
    return true;
}