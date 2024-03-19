//
// Created by yewme on 19/3/2024.
//

#ifndef SPA_TABLEUTILS_H
#define SPA_TABLEUTILS_H

#include "common/SpaTypes.h"
#include "catch.hpp"


class TableUtils {
public:

    static bool isPresent(const Table& vec, const Table& elements) {
        return std::all_of(elements.begin(), elements.end(), [&](const auto& element) {
            return std::find(vec.begin(), vec.end(), element) != vec.end();
        });
    }

    template <typename A>
    static Table toTable(std::vector<A> vec) {

        Table result;

        for (const auto& element : vec) {
            // Create a vector<string> to hold the current element
            std::vector<std::string> strElem;

            // Put the element into the str vector
            strElem.push_back(std::to_string(element)); // TODO: ian's CLion says to_string not found here

            // Add the vector to the result
            result.push_back(strElem);
        }

        return result;
    }

    static Table toTable(vector<std::string> vec) {

        Table result;

        for (const std::string& element : vec) {
            // Create a vector<string> to hold the current element
            std::vector<std::string> strElem;

            // Put the element into the str vector
            strElem.push_back((element));

            // Add the vector to the result
            result.push_back(strElem);
        }

        return result;
    }


};

#endif //SPA_TABLEUTILS_H
