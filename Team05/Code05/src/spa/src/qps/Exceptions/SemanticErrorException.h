//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SEMANTICERROREXCEPTION_H
#define SPA_SEMANTICERROREXCEPTION_H

#include <exception>

class SemanticErrorException : public std::exception {
public:
    SemanticErrorException(const char* message) : msg(message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};
#endif //SPA_SEMANTICERROREXCEPTION_H
