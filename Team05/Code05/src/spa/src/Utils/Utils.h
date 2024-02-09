//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_UTILS_H
#define SPA_UTILS_H

#include <string>
#include <vector>

class Utils {
public:
    static std::vector<std::string> splitString(const std::string& str, char delimiter);
    static void printStringVector(const std::vector<std::string>& stringVector);
    static void trimStart(std::string& str);
    static void trimTrailing(std::string& str);
    static void trimAll(std::string& str);
    static void removePrefix(std::string& str, const std::string& prefix);
};


#endif //SPA_UTILS_H
