//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_SEMANTICANALYZER_H
#define SPA_SEMANTICANALYZER_H


#include "Stmt.h"

class SemanticAnalyzer {
public:
    static void check(const Program& program);
};


#endif //SPA_SEMANTICANALYZER_H
