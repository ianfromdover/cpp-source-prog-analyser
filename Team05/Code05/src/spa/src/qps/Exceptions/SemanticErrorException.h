//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SEMANTICERROREXCEPTION_H
#define SPA_SEMANTICERROREXCEPTION_H

#include <exception>
#include "../../utilSpa/base_exception/BaseException.h"

class SemanticErrorException : public BaseException {
public:
    SemanticErrorException(const std::string& message) : BaseException("Semantic Error: " + message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};
#endif //SPA_SEMANTICERROREXCEPTION_H
