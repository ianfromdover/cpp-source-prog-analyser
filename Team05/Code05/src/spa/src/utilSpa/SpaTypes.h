#pragma once
#define SPA_TYPES_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// for QPS to check the constraint's arg type
#define RETURN_TYPE_STATEMENT "Statement"
#define RETURN_TYPE_READ "Read"
#define RETURN_TYPE_PRINT "Print"
#define RETURN_TYPE_ASSIGN "Assign"
#define RETURN_TYPE_CALL "Call"
#define RETURN_TYPE_IF "If"
#define RETURN_TYPE_WHILE "While"
#define RETURN_TYPE_INTEGER "Integer"
#define RETURN_TYPE_WILDCARD "WildCard"
#define RETURN_TYPE_PROCEDURE "Procedure"
#define RETURN_TYPE_VARIABLE "Variable"
#define RETURN_TYPE_CONSTANT "Constant"
#define RETURN_TYPE_EXPRESSION "ExpressionSpec"

#define REFERENCE_TYPE_EXPRESSION "ExpressionReference"
#define REFERENCE_TYPE_ENTITY "EntityReference"
#define REFERENCE_TYPE_STATEMENT "StatementReference"
#define REFERENCE_TYPE_WILDCARD "WildCard"

#define CONSTRAINT_CLASS_RELATIONSHIP "Relationship"
#define CONSTRAINT_CLASS_PATTERN "Pattern"

#define CONSTRAINT_TYPE_FOLLOWS "Follows"
#define CONSTRAINT_TYPE_FOLLOWST "FollowsT"
#define CONSTRAINT_TYPE_PARENT "Parent"
#define CONSTRAINT_TYPE_PARENTT "ParentT"
#define CONSTRAINT_TYPE_USESS "UsesS"
#define CONSTRAINT_TYPE_USESP "UsesP"
#define CONSTRAINT_TYPE_MODIFIESS "ModifiesS"
#define CONSTRAINT_TYPE_MODIFIESP "ModifiesP"

#define VALIDATION_RULE_SINGLE_DECLARATION "SingleDeclarationRule"
#define VALIDATION_RULE_NO_DECLARATION "NoDeclarationRule"
#define VALIDATION_RULE_SYN_ASSIGN_DECLARATION "SynAssignDeclarationRule"
#define VALIDATION_RULE_WILDCARD_ARGUMENT "WildcardArgumentRule"
#define VALIDATION_RULE_RELATIONSHIP_ARGUMENT "RelationshipArgumentRule"
#define VALIDATION_RULE_PATTERN_ARGUMENT "PatternArgumentRule"


#define LNNO "line_number"
#define PROC "procedure"
#define STMT "stmt"
//#define ASGN "assign"
//#define READ "read"
//#define CALL "call"
//#define PRINT "print"
//#define WHILE "while"
//#define IF "if"

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
