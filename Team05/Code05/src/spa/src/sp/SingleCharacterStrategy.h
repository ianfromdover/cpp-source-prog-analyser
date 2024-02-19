//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_SINGLECHARACTERSTRATEGY_H
#define SPA_SINGLECHARACTERSTRATEGY_H

#include "TokenStrategy.h"

class SingleCharacterStrategy: public TokenStrategy {
public:
    SingleCharacterStrategy() = default;
    bool tokenize(char character, std::stringstream& stream, std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens, bool& prevTokenIsKeyword) override;
};



#endif //SPA_SINGLECHARACTERSTRATEGY_H
