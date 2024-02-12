//
// Created by Chua Bing Quan on 12/2/24.
//

#include "Stmt.h"

int Stmt::getStmtNo() {
    return this->stmtNo;
}

std::unique_ptr<StmtList> While::getBody() {

}

std::unique_ptr<StmtList> If::getThenBranch() {

}

std::unique_ptr<StmtList> If::getElseBranch() {

}