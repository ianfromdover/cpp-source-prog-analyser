//
// Created by Alex on 8/2/2024.
//

#include "DeclarationHandler.h"
#include "Utils/Utils.h"
#include "DeclarationComponent.h"
#include "qps/query_elements/StatementEntity.h"
#include <regex>
#include <vector>


std::shared_ptr<QueryComponent> DeclarationHandler::handle(std::string& str) {


    std::regex entityPattern(R"(^(stmt)\s+([a-zA-Z][a-zA-Z0-9]*)(?:,\s*([a-zA-Z][a-zA-Z0-9]*))*$)");

    std::sregex_iterator iterator(str.begin(), str.end(), entityPattern);
    std::sregex_iterator end;
    std::smatch matches;
    std::string entity;
    if (std::regex_search(str, matches, entityPattern)) {
        std::cout << "Handled by Declaration Handler: " << str << std::endl;
        if (matches[1].matched) {
            Utils::trimAll(str);
            Utils::removePrefix(str, matches[1]);
            Utils::trimAll(str);

            std::vector<std::string> synList = Utils::splitString(str, ',');
            for (const std::string& syn : synList){
                synonyms.push_back(syn);
            }

            return component;
        }

        else throw std::runtime_error("BUG::SelectHandler matching regex but not matching required groups");

    } else {
        if (nextHandler) return nextHandler->handle(str);
        else throw std::runtime_error("no handlers able to process! " + str);
    }
}
