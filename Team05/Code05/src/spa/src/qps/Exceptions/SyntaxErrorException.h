//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SYNTAXERROREXCEPTION_H
#define SPA_SYNTAXERROREXCEPTION_H

#include <exception>

class SyntaxErrorException : public std::exception {
public:
    SyntaxErrorException(const char* message) : msg(message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};
#endif //SPA_SYNTAXERROREXCEPTION_H
