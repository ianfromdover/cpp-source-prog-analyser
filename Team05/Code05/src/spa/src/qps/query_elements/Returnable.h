//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_RETURNABLE_H
#define SPA_RETURNABLE_H
#include <string>

class Returnable {
public:
    virtual std::string getReturnType() = 0;
    virtual std::string toString() = 0;
};


#endif //SPA_RETURNABLE_H
