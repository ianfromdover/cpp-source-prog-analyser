//
// Created by Alex on 17/2/2024.
//

#include <map>
#include "Demo.h"
#include "qps/tokenizer/Tokenizer.h"
#include "Parser.h"

namespace qps {
    void Demo::demonstrate() {

        // Run TestParser::scratch pad or just call Demo() in some unit test. Following code exist inside constructor.

        std::string source = "stmt s;" // Declaration Clause 1 : map<STMT,"s">
                             "stmt s1; " // Declaration Clause 2 : map<STMT,"s1">
                             "Select s " // Select Clause : "s"
                             "such that Parent(1, s) " // Relationship Clause : PARENT, STMT_REF, INTEGER="1", STMT_REF, SYNONYM="s"
                             "pattern s(_, _\"x+y\"_)"; // Pattern Clause : PATTERN, SYNONYM="s", ENT_REF, WILDCARD, EXPR_WILDCARD="\"x+y\""
                             // (NOTE: wildcard character is not present. can differentiate <'"' expr'"'=EXPR> vs <'_' '"' expr '"' '_'=EXPR_WILDCARD>)

        std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();             //ignore
        std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();                       //ignore
        Tokenizer tokenizer(source, strategies, tokens);                                   //ignore
        tokenizer.tokenize();                                                                    //ignore
        Parser parser(*tokens);                                                               //ignore

        std::shared_ptr<IntermediateQuery> intermediateQuery = parser.parse();                   // Will receive this shared pointer
        intermediateQuery->processDeclarations(); // called by validator, ignore

        // Returns a map <synonym=STRING, type=TYPEINFO> of all declared synonyms for easier search, guaranteed declaration synonyms are unique
        std::map<std::string, QPSTokenType::QPSTypeInfo> synonymTypeMap = intermediateQuery->getSynonymTypeMap();

        // Returns a SelectClause
        SelectClause selectClause = *intermediateQuery->getSelectClause();
            // Returns the selected synonym
            std::string selectedSynonym = selectClause.getAllSelect()[0]; // Can assume only 1 element, vector is for A-SPA

        // Returns RelationshipClause
        RelationshipClause relationshipClause = *intermediateQuery->getRelationshipClause();
            QPSTokenType::QPSTypeInfo relationshipType = relationshipClause.getRelationshipType(); // Returns the relationship type {PARENT, FOLLOWS, MODIFIES, USES, etc.}
            QPSTokenType::QPSTypeInfo referenceType1 = relationshipClause.getFirstReferenceType(); // {ENT_REF,STMT_REF}
            QPSTokenType::QPSTypeInfo tokenType1 = relationshipClause.getFirstArgType(); // {INTEGER,SYNONYM,WILLCARD}
            QPSToken token1 = relationshipClause.getFirstArg(); // Returns the token, can also find token type{INTEGER,SYNONYM,WILLCARD} from token.getType()
            // Same for second argument

        // Returns PatternClause
        PatternClause patternClause = *intermediateQuery->getPatternClause();
            std::string patternSynonym = patternClause.getPatternSynonym(); // Returns the synonym, can use this to search declaration map for synonym type
            QPSTokenType::QPSTypeInfo argType1 = patternClause.getFirstArgType(); // Returns the argument type {SYNONYM, WILDCARD, QUOTED_IDENT} REFER(grammar): pattern-cl : entRef : synonym | '_' | '"' IDENT '"'
            std::string argValue1 = patternClause.getFirstArgValue(); // Returns the first argument value. First arg is only ENT_REF, can use this to get value.
            QPSTokenType::QPSTypeInfo argType2 = patternClause.getSecondArgType(); // Returns the argument type {EXPR, EXPR_WILDCARD, WILDCARD} REFER(grammar): expression-spec :  '"' expr'"' | '_' '"' expr '"' '_' | '_'
            std::string argValue2 = patternClause.getSecondArgValue(); // Returns the argument value. NOTE: EXPR_WILDCARD type.getstring will not return wildcard in the string. can check for token type to differentiate.

    }
}