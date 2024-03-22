//
// Created by tohzh on 8/2/2024.
//

#include "QueryEnums.h"

static const char *ENUM_RETURN_TYPE[9] ={
        "Statement",
        "Read",
        "Print",
        "Assign",
        "Call",
        "If",
        "While",
        "Integer",
        "EntityRefWildcard"
};

static const char *ENUM_STATEMENT_REF[3] = {
        "ExpressionReference",
        "EntityReference",
        "StatementReference"
};

static const char *ENUM_CONSTRAINT_CLASS[2] = {
        "Relationship",
        "Pattern"
};

static const char *ENUM_CONSTRAINT_TYPE[8] = {
        "Follows",
        "FollowsT",
        "Parent",
        "ParentT",
        "UsesS",
        "UsesP",
        "ModifiesS",
        "ModifiesP",
};

static const char *ENUM_VALIDATION_RULE[6] = {
        "SingleDeclarationRule",
        "NoDeclarationRule",
        "SynAssignDeclarationRule",
        "WildcardArgumentRule",
        "RelationshipArgumentRule",
        "PatternArgumentRule"
};
