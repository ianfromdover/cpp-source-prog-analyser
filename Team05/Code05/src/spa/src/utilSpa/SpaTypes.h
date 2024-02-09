#pragma once
#define SPA_TYPES_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// for QPS to check the constraint's arg type
#define LNNO "line_number"
#define PROC "procedure"
#define STMT "stmt"
#define ASGN "assign"
#define READ "stmt"
#define CALL "stmt"
#define PRINT "stmt"
#define WHILE "while"
#define IF "if"

#define CNST "constant"
#define INT "integer"
#define SYN "synonym"
#define VAR "variable"
#define WILD "wildcard"
#define EXP "expression" // for exact pattern
#define PEXP "partial_expression" // for partial pattern

using namespace std;

// To make code more meaningful
typedef int StmtNo;      // in the SIMPLE source program
typedef int VarId;       // for PKB quick comparison in set
typedef int ProcId;      // for PKB quick comparison in set
typedef int Cnst;
typedef std::string Str; // to neaten code
