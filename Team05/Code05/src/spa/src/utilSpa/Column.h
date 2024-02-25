#ifndef SPA_COLUMN_HPP
#define SPA_COLUMN_HPP

#include <vector>
#include <sstream>
#include "SpaTypes.h"

template <typename A>
class Column {

private:
    std::vector<A> elements;

public:
    // Constructor
    Column() {}

    bool addElement(A element) {
        elements.push_back(element);
        return true;
    }

    // Function to get all elements
    const std::vector<A>& getAllElements() const {
        return elements;
    }

    // Function to remove elements at given indices
    void removeElementbyIndices(std::vector<int> indices) {
        for (auto it = indices.rbegin(); it != indices.rend(); ++it) {
            int index = *it;
            if (index >= 0 && index < elements.size()) {
                elements.erase(elements.begin() + index);
            }
        }
    }

    // Function to get elements by indices
    std::vector<A> getElementsByIndices(std::vector<int> indices) {
        std::vector<A> result;
        for (int index : indices) {
            if (index >= 0 && index < elements.size()) {
                result.push_back(elements[index]);
            }
        }
        return result;
    }

    // Function to get element at given index
    A getElement(int index) const {
        if (index >= 0 && index < elements.size()) {
            return elements[index];
        }
        // Return a default-constructed value if index is out of range
        return A();
    }

    // Function to search indices of an element
    std::vector<int> searchIndices(A element) {
        std::vector<int> indices;
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == element) {
                indices.push_back(i);
            }
        }
        return indices;
    }

    const Str &getHeader() const {
        return header;
    }

    void setHeader(const Str &header) {
        Column::header = header;
    }

    // Function to convert all elements to strings
    std::vector<Str> convertToString() const {
        std::vector<Str> result;
        for (const A& element : elements) {
            std::ostringstream oss;
            oss << element;
            result.push_back(oss.str());
        }
        return result;
    }

    // Function to convert strings to elements of type A
    std::vector<A> convertFromString(const std::vector<Str>& strings) const {
        std::vector<A> result;
        for (const Str& str : strings) {
            std::istringstream iss(str);
            A element;
            iss >> element;
            result.push_back(element);
        }
        return result;
    }
};

#endif //SPA_COLUMN_HPP
