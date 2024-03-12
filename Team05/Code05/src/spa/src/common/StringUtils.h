//
// Created by Alex on 8/2/2024.
//

#ifndef SPA_STRINGUTILS_H
#define SPA_STRINGUTILS_H

#include <string>
#include <vector>

class StringUtils {
public:
    static std::vector<std::string> splitString(const std::string& str, char delimiter);
    static void printStringVector(const std::vector<std::string>& stringVector);
    static std::string formatWithSquareBrackets(const std::vector<std::string>& strings);
    static void trimStart(std::string& str);
    static void trimTrailing(std::string& str);
    static void trimAll(std::string& str);
    static void removePrefix(std::string& str, const std::string& prefix);
    static std::string& stripCharacters(std::string& str, const std::string& chars);
};


#endif //SPA_STRINGUTILS_H
