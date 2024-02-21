//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_FORMATTABLE_H
#define SPA_FORMATTABLE_H

#include <string>
#include <vector>

class Formattable {
public:
    virtual std::vector<std::string> format() = 0;
    std::string toString();
};



#endif //SPA_FORMATTABLE_H
