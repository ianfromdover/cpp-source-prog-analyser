#include "UsesSTable.h"

// ai-gen start (copilot, 0, e)
// prompt: used copilot

bool UsesSTable::addProc(ProcName proc, VarName name) {
    return procNameMap.insert(proc, name);
}

vector<VarName> UsesSTable::getVarFromProc(ProcName proc) {
    return procNameMap.getValues(proc);
}

vector<ProcName> UsesSTable::getProcFromVar(VarName name) {
    return procNameMap.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllProc() {
    return procNameMap.getAllForStrStr();
}

bool UsesSTable::addPrint(StmtNo sNum, VarName name) {
    return printMap.insert(sNum, name);
}

vector<VarName> UsesSTable::getPrintedVar(StmtNo sNum) {
    return printMap.getValues(sNum);
}

vector<StmtNo> UsesSTable::getPrintStmtNo(VarName name) {
    return printMap.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllPrint() {
    return printMap.getAllForAStr();
}

bool UsesSTable::addAsgn(StmtNo sNum, VarName name) {
    return asgnMap.insert(sNum, name);
}

vector<VarName> UsesSTable::getAsgnVar(StmtNo sNum) {
    return asgnMap.getValues(sNum);
}

vector<StmtNo> UsesSTable::getAsgnStmtNo(VarName name) {
    return asgnMap.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllAsgn() {
    return asgnMap.getAllForAStr();
}

bool UsesSTable::addCall(StmtNo sNum, VarName name) {
    return callMap.insert(sNum, name);
}

vector<VarName> UsesSTable::getCallVar(StmtNo sNum) {
    return callMap.getValues(sNum);
}

vector<StmtNo> UsesSTable::getCallStmtNo(VarName name) {
    return callMap.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllCall() {
    return callMap.getAllForAStr();
}

bool UsesSTable::addIfWhileContainer(StmtNo sNum, VarName name) {
    return ifWhileContainerMap.insert(sNum, name);
}

vector<VarName> UsesSTable::getIfWhileContainerVar(StmtNo sNum) {
    return ifWhileContainerMap.getValues(sNum);
}

vector<StmtNo> UsesSTable::getIfWhileContainerStmtNo(VarName name) {
    return ifWhileContainerMap.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllWhiles() {
    return ifWhileContainerMap.getAllForAStr();
}

// ai-gen end
