#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include <vector>
#include <memory>
#include <iostream>

// Composite class - represents components with children
class Composite : public Component {
public:
    explicit Composite(const std::string& name);
    void operation() const override;
    void add(std::shared_ptr<Component> component) override;
    void remove(std::shared_ptr<Component> component) override;
    std::shared_ptr<Component> getChild(int index) const override;

private:
    std::string name_;
    std::vector<std::shared_ptr<Component>> children_;
};

#endif // COMPOSITE_H