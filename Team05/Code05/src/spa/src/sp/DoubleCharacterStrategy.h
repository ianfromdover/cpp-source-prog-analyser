//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_DOUBLECHARACTERSTRATEGY_H
#define SPA_DOUBLECHARACTERSTRATEGY_H
#include "TokenStrategy.h"

class DoubleCharacterStrategy: public TokenStrategy {
public:
    DoubleCharacterStrategy() = default;
    bool tokenize(char character, std::stringstream& stream, std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens,
                  bool& prevTokenIsKeyword) override;
};

#endif //SPA_DOUBLECHARACTERSTRATEGY_H
