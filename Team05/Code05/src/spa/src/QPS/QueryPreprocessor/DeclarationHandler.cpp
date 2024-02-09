//
// Created by Alex on 8/2/2024.
//

#include "DeclarationHandler.h"
#include "Utils/Utils.h"
#include <regex>
#include <vector>


void DeclarationHandler::handle(std::string& str) {
    std::cout << "Declaration handler: " << str << std::endl;

    processEntity(str);
    //std::string regexString = "(variable|statement)\\s+([a-zA-Z][a-zA-Z0-9,]*)";
    //std::string regexString = R"((stmt|read|print|call|while|if|assign|variable|constant|procedure)\s+(\w+)(?:\s*,\s*(\w+))*\s*;)"
    std::regex pattern(R"((variable)\s+(\w+)(?:\s*,\s*(\w+))*\s*;)");
    std::regex entityPattern(R"(\s*?(stmt)\s+([a-zA-Z0-9\,]*)\s*?;)");
    //(([a-zA-Z][a-zA-Z0-9]*)+?)(?:,\s*|;)
    //\s*?(stmt)\s+([a-zA-Z0-9\,]*)\s*?;

//    std::sregex_iterator iterator(str.begin(), str.end(), pattern);
//    std::sregex_iterator end;
//
//    std::vector<std::string> synList;
//
//    std::smatch matches;
//    if (std::regex_search(str, matches, pattern)) {
//
//        if (matches[1].matched) {
//            entityType = matches[1];
//        }
//
//        if (matches[2].matched) {
//            synonyms = matches[2];
//            std::vector<std::string> tempList = Utils::splitString(synonyms,',');
//            for (std::string s : tempList){
//                if (!s.empty()){
//                    synList.push_back(s);
//                } else {
//                    //TODO: Need to throw, invalid syntax, here means 2 commas in sequence
//                }
//            }
//        }
//
//        std::cout << "Entity Type: " << entityType << std::endl;
//        std::cout << "Synonyms: " ;
//        Utils::printStringVector(synList);
//    } else {
//        std::cout << "Declaration Handler unable to process" << std::endl;
//        nextHandler->handle(str);
//    }
}

void DeclarationHandler::processEntity(std::string& s) {
    std::regex entityPattern(R"(^(variable)\s+([a-zA-Z][a-zA-Z0-9]*)(?:,\s*([a-zA-Z][a-zA-Z0-9]*))*$)");

    std::sregex_iterator iterator(s.begin(), s.end(), entityPattern);
    std::sregex_iterator end;

    std::smatch matches;
    std::string entity;
    if (std::regex_search(s, matches, entityPattern)) {
        if (matches[1].matched) {
            entity = matches[1];
        }

    }

    Utils::trimAll(s);
    Utils::removePrefix(s, entity);
    Utils::trimAll(s);

    std::vector<std::string> synList = Utils::splitString(s, ',');
    for (std::string syn : synList){
        synonyms.push_back(syn);
    }


}

void DeclarationHandler::processSynonyms(std::string) {

}


