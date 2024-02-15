//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_CONSTRAINTARGUMENT_H
#define SPA_CONSTRAINTARGUMENT_H

#include <string>

class ConstraintArgument {
public:
    virtual std::string getReferenceType() = 0;
    virtual std::string getEntityType() = 0;
    virtual std::string getArgumentValue() = 0;
};


#endif //SPA_CONSTRAINTARGUMENT_H
