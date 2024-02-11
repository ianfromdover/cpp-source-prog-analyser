//
// Created by Alex on 7/2/2024.
//

#include <regex>
#include "HandlerChain.h"
#include "utilSpa/StringUtils.h"
#include "qps/Exceptions/SyntaxErrorException.h"

std::vector<std::shared_ptr<QueryComponent>> HandlerChain::handle(std::string str) {
    std::cout << "handler chain received " << str <<std::endl;
    char delimitter = ';';
    std::vector<std::string> splitStr = StringUtils::splitString(str, delimitter);
    std::vector<std::string> toHandlers;
    std::vector<std::shared_ptr<QueryComponent>> parsedComponents;


    for (std::string s : splitStr){
        if (s.empty()) throw std::runtime_error("empty clause");
        std::vector<std::string> split = tryConvert(s);
        if (split.size() > 0){
            for (const std::string& clauses : split){
                toHandlers.push_back(clauses);
            }
        } else {
            toHandlers.push_back(s);
        }
    }

    for (std::string s : toHandlers){
        std::cout << "processing " << s <<std::endl;
        std::shared_ptr<QueryComponent> component = handlerChain->handle(s);
        parsedComponents.push_back(component);
    }

    return parsedComponents;
}


std::vector<std::string> HandlerChain::tryConvert(std::string str) {
    std::regex suchThatRegex(R"(Select\s+[a-zA-Z][a-zA-Z0-9]*\s+.*?(such\s+that\s+(:?Parent|Parent\*)\s*\(.*?\)))");
    std::regex selectRegex(R"(Select\s+[a-zA-Z][a-zA-Z0-9]*)");

    std::string selectCl, suchThatCl;

    std::sregex_iterator iterator(str.begin(), str.end(), selectRegex);
    std::smatch matches;
    std::string entity;

    std::vector<std::string> res;

    if (std::regex_search(str, matches, selectRegex)) {
        //check for select clause first
        if (matches[0].matched) {
            res.push_back(matches[0]);
        }

        if (std::regex_search(str, matches, suchThatRegex)) {
            //check for such that clause
            if (matches[1].matched) {
                res.push_back(matches[1]);
            }
        }
    }

    if (res.empty()) return res;

    for (std::string cl : res){
        size_t pos = str.find(cl);
        if (pos != std::string::npos) {
            str.erase(pos, cl.length());
        }
    }

    if (std::all_of(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); })){
        return res;
    } else {
        throw SyntaxErrorException(str.c_str());
    }

}
