//
// Created by Alex Teo on 4/4/2024.
//

#ifndef SPA_WITHCLAUSE_H
#define SPA_WITHCLAUSE_H

#include "Clause.h"
#include "qps/exceptions/QPSException.h"
#include "qps/tokenizer/QPSToken.h"
#include <memory>

class WithClause : public Clause {
public:
  QPSToken &getFirstArg(){
    if (firstArg != nullptr) {
      return *firstArg;
    }
    throw QPSException("First argument is not set");
  };
  QPSToken &getSecondArg(){
    if (secondArg != nullptr) {
      return *secondArg;
    }
    throw QPSException("Second argument is not set");
  }

  WithClause(QPSToken &t1, QPSToken &t2, QPSTokenType::QPSTypeInfo type1, QPSTokenType::QPSTypeInfo type2) : Clause(ClauseType::WITH) {
    firstArg = std::make_shared<QPSToken>(t1);
    secondArg = std::make_shared<QPSToken>(t2);
    firstArgType = type1;
    secondArgType = type2;
  }

  QPSTokenType::QPSTypeInfo getFirstArgType(){
    return firstArgType; // return ATTR_REF/INTEGER/QUOTED_IDENT
  }
  QPSTokenType::QPSTypeInfo getSecondArgType(){
    return secondArgType; // return ATTR_REF/INTEGER/QUOTED_IDENT
  }

  QPSTokenType::QPSTypeInfo getFirstArgAttribute() {
    if (!firstArgAttribute){
      throw QPSException("Second argument attribute is not set");
    }
    return firstArgAttribute;
  }
  QPSTokenType::QPSTypeInfo getSecondArgAttribute(){
    if (!secondArgAttribute){
      throw QPSException("Second argument attribute is not set");
    }
      return secondArgAttribute;
  }
  void setFirstArgAttribute(QPSTokenType::QPSTypeInfo &type){
    firstArgAttribute = type;
  }
  void setSecondArgAttribute(QPSTokenType::QPSTypeInfo &type){
    secondArgAttribute = type;
  }

  // Examples:
  /**
   * with a.stmt# = 1
   * getFirstArg() = QPSType::SYNONYM,{"a"}
   * getSecondArg() = QPSType::INTEGER,{"1"}
   * getFirstArgType() = QPSType::ATTR_REF
   * getSecondArgType() = QPSType::INTEGER
   * getFirstArgAttribute() = QPSType::WITHSTMT
   * getSecondArgAttribute() = THROW EXCEPTION
   *
   * with "a" = 1
   * getFirstArg() = QPSType::QUOTED_IDENT,{"a"}
   * getSecondArg() = QPSType::INTEGER,{"1"}
   * getFirstArgType() = QPSType::QUOTED_IDENT
   * getSecondArgType() = QPSType::INTEGER
   * getFirstArgAttribute() = THROW EXCEPTION
   * getSecondArgAttribute() = THROW EXCEPTION
   *
   * * with c.value = v.varName
   * getFirstArg() = QPSType::SYNONYM,{"c"}
   * getFirstArg() = QPSType::SYNONYM,{"v"}
   * getFirstArgType() = QPSType::ATTR_REF
   * getSecondArgType() = QPSType::ATTR_REF
   * getFirstArgAttribute() = QPSType::WITHVALUE
   * getSecondArgAttribute() = QPSType::WITHVARNAME
   */

private:
  std::shared_ptr<QPSToken> firstArg;
  std::shared_ptr<QPSToken> secondArg;

  QPSTokenType::QPSTypeInfo firstArgType;
  QPSTokenType::QPSTypeInfo secondArgType;
  QPSTokenType::QPSTypeInfo firstArgAttribute;
  QPSTokenType::QPSTypeInfo secondArgAttribute;
};

#endif // SPA_WITHCLAUSE_H
