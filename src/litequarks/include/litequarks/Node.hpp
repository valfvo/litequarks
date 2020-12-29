#pragma once

namespace LQ {

class Node {
public:
    virtual ~Node();

    Node* parentNode() const { return parentNode_; }
    Node* firstChild() const { return firstChild_; }
    Node* lastChild() const { return lastChild_; }
    Node* previousSibling() const { return previousSibling_; }
    Node* nextSibling() const { return nextSibling_; }

    Node* insertBefore(Node* node, Node* child);
    Node* appendChild(Node* node) { return insertBefore(node, nullptr); }
    Node* removeChild(Node* child);

    void remove();

    void setParentNode(Node* parent) { parentNode_ = parent; }
    void setFirstChild(Node* child) { firstChild_ = child; }
    void setLastChild(Node* child) { lastChild_ = child; }
    void setPreviousSibling(Node* previous) { previousSibling_ = previous; }
    void setNextSibling(Node* next) { nextSibling_ = next; }

protected:
    Node();

private:
    void insertBeforeBase(Node& node, Node& child);
    void appendChildBase(Node& child);
    void removeChildBase(Node& child);

    Node* parentNode_;
    Node* firstChild_;
    Node* lastChild_;
    Node* previousSibling_;
    Node* nextSibling_;
};

} // namespace LQ
