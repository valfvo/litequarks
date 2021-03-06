#pragma once

#include "LQDeclaration.hpp"
#include <list>

class LQuark {
public:
    LQuark();
    virtual ~LQuark();
    // accessors
    LQuark* parent() const;
    LQuark* firstChild() const;
    LQuark* lastChild() const;
    LQuark* nthChild(LQindex nth) const;
    LQuark* prevSibling() const;
    LQuark* nextSibling() const;
    LQuark const* nthSibling(LQindex nth) const;
    LQsize  childrenCount() const;

    void setNextSibling(LQuark* nextSibling);

    // LQGreenCharge
    LQuark& appendChild(LQuark* child);
    LQuark& appendChild(LQuark& child);
    LQuark& insertChild(LQindex index, LQuark& child);
    LQuark& insertChildBefore(LQuark& newChild, LQuark& child);
    LQuark& insertChildAfter(LQuark& newChild, LQuark& child);

    // LQRedCharge
    LQuark& detach();
    LQuark& removeChild(LQuark& child);
    LQuark& removeChild(LQindex index);
    LQuark& removeFirstChild();
    LQuark& removeLastChild();
    LQuark& removeChildren(LQuark& newParent);

    // LQYellowCharge
    LQuark& swapWith(LQuark& quark);
    LQuark& swapChildren(LQuark& first, LQuark& second);
    LQuark& swapChildren(LQindex first, LQindex second);

protected:
    LQuark* m_parent;
    LQuark* m_prevSibling;
    LQuark* m_nextSibling;
    LQuark* m_firstChild;
    LQuark* m_lastChild;
    LQsize  m_childrenCount;

    friend class LQSurface;
};

// #define DEFINE_ATTRIBUTE_EVENT_LISTENER(attribute) \
//         EventListener* on##attribute() { return getAttributeEventListener(eventNames().attribute##Event); } \
//         void setOn##attribute(PassRefPtr<EventListener> listener) { setAttributeEventListener(eventNames().attribute##Event, listener); } \

// DEFINE_ATTRIBUTE_EVENT_LISTENER(abort)

// EventListener* onabort() {
//     return getAttributeEventListener(eventNames().abortEvent);
// }

// void setOnabort(PassRefPtr<EventListener> listener) {
//     setAttributeEventListener(eventNames().abortEvent, listener);
// }
