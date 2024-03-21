//
// Created by Alex on 8/2/2024.
//

#include "StringUtils.h"
#include <iostream>
#include <regex>
#include <sstream>

std::vector<std::string> StringUtils::splitString(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::size_t start = 0;
    std::size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start));

    return result;
}

void StringUtils::printStringVector(const std::vector<std::string> &stringVector) {
    std::cout << formatWithSquareBrackets(stringVector) << std::endl;
}

std::string StringUtils::formatWithSquareBrackets(const std::vector<std::string>& strings) {
    std::ostringstream oss;
    oss << "["; // Start with opening square bracket

    for (size_t i = 0; i < strings.size(); ++i) {
        oss << strings[i]; // Append the current string

        // Append a comma and space if it's not the last string
        if (i < strings.size() - 1) {
            oss << " , ";
        }
    }

    oss << "]"; // End with closing square bracket

    return oss.str();
}


void StringUtils::trimStart(std::string& str) {
    // Find the first non-whitespace character
    size_t start = str.find_first_not_of(" \t\n\r");

    // If the string is all whitespace, return an empty string
    if (start == std::string::npos) {
        str = "";
    }

    // Return the substring starting from the first non-whitespace character
    str = str.substr(start);
}

void StringUtils::trimTrailing(std::string& str) {
    // Find the index of the last non-whitespace character
    size_t end = str.find_last_not_of(" \t\n\r");
    if (end == std::string::npos) {
        // If the string is all whitespace, return an empty string
        str = "";
    }

    // Return the substring from the beginning to the last non-whitespace character
    str = str.substr(0, end + 1);
}

void StringUtils::removePrefix(std::string& str, const std::string& prefix) {
    // Check if the string starts with the prefix
    if (str.compare(0, prefix.length(), prefix) == 0) {
        // If it does, erase the prefix from the string
        str = str.substr(prefix.length());
    }

}

void StringUtils::trimAll(std::string &str) {
    trimStart(str);
    trimTrailing(str);
}

std::string& StringUtils::stripCharacters(std::string& str, const std::string& chars) {
    // Find the first character position after excluding leading characters
    std::size_t first = str.find_first_not_of(chars);
    if (first == std::string::npos) {
        // If there are no characters other than the ones to strip, return an empty string
        return str = "";
    }

    // Find the position of the last character not matching the strip characters
    std::size_t last = str.find_last_not_of(chars);

    // Erase the leading and trailing characters
    str = str.substr(first, (last - first + 1));

    return str;
}
std::string &StringUtils::formatAsRegex(std::string &str) {
  // add \b to the start and end of the string to match word boundaries
  str = "\\b" + str + "\\b";
  // replace + with \+ to match the + character
  str = std::regex_replace(str, std::regex("\\+"), "\\+");
  return str;
}
