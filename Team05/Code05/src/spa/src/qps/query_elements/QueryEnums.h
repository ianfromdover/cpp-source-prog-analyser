//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_QUERYENUMS_H
#define SPA_QUERYENUMS_H

#include <unordered_map>
#include <string>

enum enumReturnType {
    Statement,
    Read,
    Print,
    Assign,
    Call,
    If,
    While,
    Integer,
    WildCard
};

enum enumReferenceType {
    ExpressionReference,
    EntityReference,
    StatementReference
};

enum enumConstraintClass {
    Relationship,
    Pattern
};

enum enumConstraintType {
    Follows,
    FollowsT,
    Parent,
    ParentT,
    UsesS,
    UsesP,
    ModifiesS,
    ModifiesP
};

enum enumValidationRule {
    SingleDeclarationRule,
    NoDeclarationRule,
    SynAssignDeclarationRule,
    WildcardArgumentRule,
    RelationshipArgumentRule,
    PatternArgumentRule
};

class QueryEnums {
public:
    static const char *ENUM_RETURN_TYPE[9];
    static const char *ENUM_REF_TYPE[3];
    static const char *ENUM_CONSTRAINT_CLASS[2];
    static const char *ENUM_CONSTRAINT_TYPE[8];
    static const char *ENUM_VALIDATION_RULE[6];
};


#endif //SPA_QUERYENUMS_H
