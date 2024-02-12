#include "Fn.h"
template<typename A>
std::vector<A> Fn::toVec(std::set<A> set) {
    return std::vector<A>(set.begin(), set.end());
}
