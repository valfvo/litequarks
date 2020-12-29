#pragma once

namespace LQ {

class Node {
    // accessors
    /*
     * {
     *     NodeRef a = node.firstChild();
     *     a.remove();
     * }
     * ComponentRef a = node.firstComponentChild();
     * 
     * Component* = new Component
     * 
     * tree()
     *   .add(new LQ::Component(new LQ::ClassList("small-button")))
     */
    Node* parent() const;
    Node* firstChild() const;
    Node* lastChild() const;
    // Node* nthChild(LQindex nth) const;
    Node* previousSibling() const;
    Node* nextSibling() const;
    // Node const* nthSibling(LQindex nth) const;
    // LQsize  childrenCount() const;

    void setNextSibling(Node* nextSibling);

    Node& appendChild(Node* child);
    Node& appendChild(Node& child);
    // Node& insertChild(LQindex index, Node& child);
    Node& insertChildBefore(Node& newChild, Node& child);
    Node& insertChildAfter(Node& newChild, Node& child);

    Node& detach();
    Node& removeChild(Node& child);
    // Node& removeChild(LQindex index);
    Node& removeFirstChild();
    Node& removeLastChild();
    Node& removeChildren(Node& newParent);

    Node& swapWith(Node& quark);
    Node& swapChildren(Node& first, Node& second);
    // Node& swapChildren(LQindex first, LQindex second);

protected:
    Node();
    virtual ~Node();

    Node* m_parent;
    Node* m_prevSibling;
    Node* m_nextSibling;
    Node* m_firstChild;
    Node* m_lastChild;
    // LQsize  m_childrenCount;
};

} // namespace LQ
