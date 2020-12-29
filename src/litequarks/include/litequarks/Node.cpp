#include "Node.hpp"

namespace LQ {

Node* Node::insertBefore(Node* node, Node* child)
{
    if (child == node || child->previousSibling() == node)
        return node;

    if (child) {
        insertBeforeBase(*node, *child);
    } else {
        appendChildBase(*node);
    }

    return node;
}

Node* Node::removeChild(Node* child)
{
    removeChildBase(*child);

    return child;
}

void Node::remove()
{
    if (parentNode())
        parentNode()->removeChild(this);
}

void Node::insertBeforeBase(Node& node, Node& child)
{
    Node* previous = child.previousSibling();

    child.setPreviousSibling(&node);

    if (previous) {
        previous->setNextSibling(&node);
    } else {
        setFirstChild(&node);
    }

    node.setParentNode(this);
    node.setPreviousSibling(previous);
    node.setNextSibling(&child);
}

void Node::appendChildBase(Node& child)
{
    child.setParentNode(this);

    if (lastChild_) {
        child.setPreviousSibling(lastChild_);
        lastChild_->setNextSibling(&child);
    } else {
        setFirstChild(&child);
    }

    setLastChild(&child);
}

void Node::removeChildBase(Node& child)
{
    Node* previousChild = child.previousSibling();
    Node* nextChild = child.nextSibling();

    if (nextChild)
        nextChild->setPreviousSibling(previousChild);
    if (previousChild)
        previousChild->setNextSibling(nextChild);

    if (firstChild_ == &child)
        firstChild_ = nextChild;
    if (lastChild_ == &child)
        lastChild_ = previousChild;

    child.setParentNode(nullptr);
    child.setPreviousSibling(nullptr);
    child.setNextSibling(nullptr);
}

} // namespace LQ
