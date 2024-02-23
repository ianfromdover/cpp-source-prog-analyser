#include "DoubleCharacterStrategy.h"

bool DoubleCharacterStrategy::tokenize(char character, std::stringstream& stream, std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens,
                                       bool& prevTokenIsKeyword) {
    TokenType type;
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
            if (type == TokenType::UNKNOWN) {
                throw TokenException("Invalid Token Type");
            }
            break;
        case '&':
            doubleCharacter = stream.peek() == '&';
            type = doubleCharacter ? TokenType::AND : TokenType::UNKNOWN; // Assuming AND only valid as double char
            if (type == TokenType::UNKNOWN) {
                throw TokenException("Invalid Token Type");
            }
            break;
        default:
            return false; // No single or double character token recognized
    }

    if (doubleCharacter) {
        lexeme += static_cast<char>(stream.get()); // Append the second character to lexeme
    }

    this->addToken(type, lexeme, tokens);
    prevTokenIsKeyword = false; // Reset keyword flag for all tokens handled here
    return true;
}