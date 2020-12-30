#pragma once

#include <string_view>

namespace LQ {

class RuleSet {
public:
    RuleSet() {}
    RuleSet(std::string_view classList) {}
    virtual ~RuleSet() {};
};

} // namespace LQ
