#pragma once

#include "Node.hpp"
#include "RuleSet.hpp"

namespace LQ {

class Component : public Node {
public:
    Component(const RuleSet& ruleset) {}
    ~Component() override {}

    void box();
};

} // namespace LQ
