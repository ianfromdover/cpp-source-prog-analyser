//
// Created by Chua Bing Quan on 5/3/24.
//

#include "ExprFormatter.h"
#include "../../tokenizer/Scanner.h"
#include "../../parser/Parser.h"
#include "../../exception/FormatterException.h"

std::string ExprFormatter::format(const std::string& exprStr) {
    if (exprStr.find(';') != string::npos) {
        throw InvalidExprString();
    }
    const auto source = "procedure main {"s + " expr = " + exprStr + "; }";
    try {
        const auto ast = Parser(Scanner(source).scanTokens()).parse();
        const auto stmt = ast->at(0)->getBody()->at(0);
        return dynamic_cast<Assign&>(*stmt).getValue()->toString();
    } catch (BaseException& _) {
        throw InvalidExprString();
    }
}