#ifndef LEAF_H
#define LEAF_H

#include "component.h"
#include <iostream>

// Leaf class - represents end objects
class Leaf : public Component {
public:
    explicit Leaf(const std::string& name);
    void operation() const override;

private:
    std::string name_;
};

#endif // LEAF_H