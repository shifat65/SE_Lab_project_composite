#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <vector>
#include <memory>

// Abstract base class
class Component {
public:
    virtual ~Component() = default;
    virtual void operation() const = 0;
    virtual void add(std::shared_ptr<Component> component);
    virtual void remove(std::shared_ptr<Component> component);
    virtual std::shared_ptr<Component> getChild(int index) const;
};

#endif // COMPONENT_H