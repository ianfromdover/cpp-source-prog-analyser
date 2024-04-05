//
// Created by Alex Teo on 4/5/2024.
//

#ifndef SPA_WITHATTRIBUTERULE_H
#define SPA_WITHATTRIBUTERULE_H

#include "Rule.h"

class WithAttributeRule : public Rule {
  std::string validate(IntermediateQuery &) override;
};

#endif // SPA_WITHATTRIBUTERULE_H
