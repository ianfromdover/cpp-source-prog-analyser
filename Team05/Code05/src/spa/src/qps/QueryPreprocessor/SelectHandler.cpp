//
// Created by Alex on 8/2/2024.
//

#include <regex>
#include "SelectHandler.h"
#include "SelectComponent.h"
#include "qps/Exceptions/SyntaxErrorException.h"

std::shared_ptr<QueryComponent> SelectHandler::handle(std::string& str) {
    std::regex regexPattern(R"(^\s*Select\s+([a-zA-Z][a-zA-Z0-9]*)$)");

    std::sregex_iterator iterator(str.begin(), str.end(), regexPattern);
    std::sregex_iterator end;
    std::smatch matches;
    if (std::regex_search(str, matches, regexPattern)) {
//        std::cout << "Handled by Select Handler: " << str << std::endl;
        if (matches[1].matched) {
            component->setSynonym(matches[1]);
            return component;
        }

        else throw std::runtime_error("BUG::SelectHandler matching regex but not matching required groups");
    } else {
        if (nextHandler) return nextHandler->handle(str);
        else throw SyntaxErrorException(str.c_str());
    }
}
