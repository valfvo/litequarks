#include "litequarks.hpp"

int main()
{
    LQ::Component* c = new LQ::Component(LQ::RuleSet("my-class"));
    delete c;

    return 0;
}
