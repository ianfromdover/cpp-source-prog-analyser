//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SYNTAXERROREXCEPTION_H
#define SPA_SYNTAXERROREXCEPTION_H

#include <exception>
#include "../../utilSpa/base_exception/BaseException.h"

class SyntaxErrorException : public BaseException {
public:
    SyntaxErrorException(Str message) : BaseException(message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};
#endif //SPA_SYNTAXERROREXCEPTION_H
