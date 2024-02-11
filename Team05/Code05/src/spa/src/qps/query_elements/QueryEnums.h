//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_QUERYENUMS_H
#define SPA_QUERYENUMS_H

#include <unordered_map>
#include <string>

enum enumReturnType {
    Statement_enum,
    Read_enum,
    Print_enum,
    Assign_enum,
    Call_enum,
    If_enum,
    While_enum,
    Integer_enum,
    WildCard_enum
};

enum enumReferenceType {
    ExpressionReference_enum,
    EntityReference_enum,
    StatementReference_enum
};

enum enumConstraintClass {
    Relationship_enum,
    Pattern_enum
};

enum enumConstraintType {
    Follows_enum,
    FollowsT_enum,
    Parent_enum,
    ParentT_enum,
    UsesS_enum,
    UsesP_enum,
    ModifiesS_enum,
    ModifiesP_enum,
};

enum enumValidationRule {
    SingleDeclarationRule_enum,
    NoDeclarationRule_enum,
    SynAssignDeclarationRule_enum,
    WildcardArgumentRule_enum,
    RelationshipArgumentRule_enum,
    PatternArgumentRule_enum
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
