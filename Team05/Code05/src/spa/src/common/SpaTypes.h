#pragma once
#define SPA_TYPES_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// for QPS to check the constraint's arg type
#define TYPE_STATEMENT "Statement"
#define TYPE_READ "Read"
#define TYPE_PRINT "Print"
#define TYPE_ASSIGN "Assign"
#define TYPE_CALL "Call"
#define TYPE_IF "If"
#define TYPE_WHILE "While"
#define TYPE_INTEGER "Integer"
#define TYPE_WILDCARD "EntityRefWildcard"
#define TYPE_PROCEDURE "Procedure"
#define TYPE_VARIABLE "Variable"
#define TYPE_CONSTANT "Constant"
#define TYPE_EXPRESSION "Expression"
#define TYPE_EXPRESSION_W_WILDCARD "ExpressionWithWildcard"
#define TYPE_QUOTED_IDENT "QuotedIdentity"
#define TYPE_VAR_WITH "VarWith"
#define TYPE_LITERAL_WITH "IntWith"

#define RETURN_INT_RESULT "IntResult"
#define RETURN_STR_RESULT "StrResult"
#define RETURN_BOOL_RESULT "BoolResult"

#define REFERENCE_TYPE_EXPRESSION "ExpressionReference"
#define REFERENCE_TYPE_ENTITY "EntityReference"
#define REFERENCE_TYPE_STATEMENT "StatementReference"
#define REFERENCE_TYPE_WITH "WithReference"

#define CONSTRAINT_CLASS_RELATIONSHIP "Relationship"
#define CONSTRAINT_CLASS_PATTERN "Pattern"
#define CONSTRAINT_CLASS_WITH "With"

#define CONSTRAINT_TYPE_FOLLOWS "Follows"
#define CONSTRAINT_TYPE_FOLLOWST "FollowsT"
#define CONSTRAINT_TYPE_PARENT "Parent"
#define CONSTRAINT_TYPE_PARENTT "ParentT"
#define CONSTRAINT_TYPE_USESS "UsesS"
#define CONSTRAINT_TYPE_USESP "UsesP"
#define CONSTRAINT_TYPE_MODIFIESS "ModifiesS"
#define CONSTRAINT_TYPE_MODIFIESP "ModifiesP"
#define CONSTRAINT_TYPE_CALLS "Calls"
#define CONSTRAINT_TYPE_CALLST "CallsT"
#define CONSTRAINT_TYPE_WITH "With"
#define CONSTRAINT_TYPE_PATTERN_IF "PatternIf"
#define CONSTRAINT_TYPE_PATTERN_ASSIGN "PatternAssign"
#define CONSTRAINT_TYPE_PATTERN_WHILE "PatternWhile"
#define CONSTRAINT_TYPE_NEXT "Next"
#define CONSTRAINT_TYPE_NEXTT "NextT"
#define CONSTRAINT_TYPE_AFFECTS "Affects"

// Used for hashing
#define CONSTRAINT_TYPE_PATTERN_ASGN "PatternAsgn"
#define CONSTRAINT_TYPE_PATTERN_IF "PatternIf"
#define CONSTRAINT_TYPE_PATTERN_WHILE "PatternWhile"

#define VALIDATION_RULE_SINGLE_DECLARATION "SingleDeclarationRule"
#define VALIDATION_RULE_NO_DECLARATION "NoDeclarationRule"
#define VALIDATION_RULE_SYN_ASSIGN_DECLARATION "SynAssignDeclarationRule"
#define VALIDATION_RULE_WILDCARD_ARGUMENT "WildcardArgumentRule"
#define VALIDATION_RULE_RELATIONSHIP_ARGUMENT "RelationshipArgumentRule"
#define VALIDATION_RULE_PATTERN_ARGUMENT "PatternArgumentRule"
#define VALIDATION_RULE_WITH_ATTRIBUTE "WithAttributeRule"

// headers for getRelationshipTables
#define HEADER_ASSIGNLHS "ASSIGNLHS"
#define HEADER_ASSIGNRHS "ASSIGNRHS"
#define HEADER_IFPATTERN "IF_PATTERN"
#define HEADER_WHILEPATTERN "WHILEPATLHS"
#define HEADER_CALLSLHS "CallsLHS"
#define HEADER_CALLSRHS "CallsRHS"
#define HEADER_CALLSTLHS "CallsTLHS"
#define HEADER_CALLSTRHS "CallsTRHS"
#define HEADER_FOLLOWSLHS "FollowsLHS"
#define HEADER_FOLLOWSRHS "FollowsRHS"
#define HEADER_FOLLOWSTLHS "FollowsTLHS"
#define HEADER_FOLLOWSTRHS "FollowsTRHS"
#define HEADER_MODIFIESTLHS "ModifiesPLHS"
#define HEADER_MODIFIESTRHS "ModifiesPRHS"
#define HEADER_MODIFIESSLHS "ModifiesSLHS"
#define HEADER_MODIFIESSRHS "ModifiesSRHS"
#define HEADER_PARENTLHS "PARENTLHS"
#define HEADER_PARENTRHS "PARENTRHS"
#define HEADER_PARENTTLHS "PARENTTLHS"
#define HEADER_PARENTTRHS "PARENTTRHS"
#define HEADER_USESPLHS "UsesPLHS"
#define HEADER_USESPRHS "UsesPRHS"
#define HEADER_USESSLHS "UsesSLHS"
#define HEADER_USESSRHS "UsesSRHS"
#define HEADER_AFFECTSLHS "AffectsLHS"
#define HEADER_AFFECTSRHS "AffectsRHS"
#define HEADER_NEXTLHS "NextLHS"
#define HEADER_NEXTRHS "NextRHS"
#define HEADER_NEXTTLHS "NextTLHS"
#define HEADER_NEXTTRHS "NextTRHS"

#define HASH_OFFSET 0x9e3779b9

//headers for getEntityTable
#define HEADER_ENT_CONSTANTLHS "CONSTANTLHS"
#define HEADER_ENT_ASSIGNRHS "ASSIGNRHS"
#define HEADER_ENT_CALLRHS "CALLRHS"
#define HEADER_ENT_IFRHS "IFRHS"
#define HEADER_ENT_PRINTRHS "PRINTRHS"
#define HEADER_ENT_READRHS "READRHS"
#define HEADER_ENT_WHILEVAR "WhileVar"
#define HEADER_ENT_WITHVAR "VariableWith"
#define HEADER_ENT_WITH_TOMERGE "*TOMERGE*" // special character is used so that it will not clash with possible syn names.

// error message
#define ERROR_INVALID_QUERY "Invalid QPS Query"

#define LNNO "line_number"
#define PROC "procedure"
//#define STMT "stmt" (used in Team05/Code05/src/spa/src/qps/QueryPreprocessor/QueryBuilder.cpp)
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
using StmtNo = int;      // in the SIMPLE source program
using Str = std::string; // to neaten code
using VarName = Str;
using ProcName = Str;
using ConstVal = int;
using Table = std::vector<std::vector<Str>>;