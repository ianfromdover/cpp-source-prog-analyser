//
// Created by yewme on 15/2/2024.
//

#ifndef SPA_BASEEXCEPTION_H
#define SPA_BASEEXCEPTION_H

#include <exception>

class BaseException : public std::exception {
public:
    BaseException(Str message) : msg(message.c_str()) {}

    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};


#endif //SPA_BASEEXCEPTION_H
