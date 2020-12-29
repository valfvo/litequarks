#include <iostream>
#include <string_view>

namespace LQ {

class RuleSet {
public:
    RuleSet(std::string_view classes)
    {
        std::cout << "RuleSet ctor called with " << classes << '\n';
    }

    RuleSet& x(std::string_view value)
    {
        std::cout << "x: " << value << "\n";
        return *this;
    }

    RuleSet& y(std::string_view value)
    {
        std::cout << "y: " << value << "\n";
        return *this;
    }

    RuleSet& zIndex(std::string_view value)
    {
        std::cout << "z-index: " << value << "\n";
        return *this;
    }

    RuleSet& width(std::string_view value)
    {
        std::cout << "width: " << value << "\n";
        return *this;
    }

    RuleSet& height(std::string_view value)
    {
        std::cout << "height: " << value << "\n";
        return *this;
    }
};

class Node {};

class Component;

class ComponentTree {
public:
    ComponentTree(Component* owner) : owner_(owner) {}
    ComponentTree& add(Component* child) { return *this; }

private:
    Component* owner_;
};

class Component : public Node {
public:
    Component(RuleSet ruleset)
    {
        std::cout << "Component ctor called with RuleSet\n";
    };

    ComponentTree tree() { return ComponentTree(this); }
};

class ComponentRef {
public:
    ComponentRef(Component* ptr) : ptr_(ptr)
    {
        std::cout << "ComponentRef ctor called with Component*\n";
    }

    Component* operator->() const { return ptr_; }

private:
    Component* ptr_;
};

} // namespace LQ

class MyComponent : public LQ::Component {
public:
    MyComponent(LQ::RuleSet ruleset) : Component(ruleset)
    {
        // on<MouseClickEvent>(onclick);
    }
};

int main() {
    LQ::ComponentRef c = new LQ::Component(LQ::RuleSet("my-css-like-cls"));

    c->tree()
        .add(new LQ::Component(LQ::RuleSet("my-class")
            .x("30px")
            .y("100px")
            .width("100%")
            .height("20%")))
        .add(new MyComponent(LQ::RuleSet("my-btn")));

    return EXIT_SUCCESS;
}

/**
 * offset(unit x, unit y, unit float = false)
 * {
 *   this.pos += (x, y);
 *   this.float = float;
 * }
 * 
 * c'est mon texte avec un mot {bf, offset[3px 2px]: important} dedans
 * 
 * Component c = new Component(RuleSet("my-css-like-cls"));
 * 
 * RuleSet myRules = RuleSet("my-class")
 *   .pos("30px 100px")
 *   .dim("100% 20%");
 * 
 * c.tree()
 *     .append(new Component(myRules))
 *     .append(new Button(new RuleSet()
 *         .borderRadius("5px")))
 *     .props()
 *          .onMouseClick(event -> System.out.println(event.x));
 * 
 * c.append(new Component(myRules));
 * Component child = this.firstComponentChild();
 * 
 */
