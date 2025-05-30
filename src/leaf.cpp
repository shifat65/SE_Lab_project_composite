#include "leaf.h"

Leaf::Leaf(const std::string& name) : name_(name) {}

void Leaf::operation() const {
    std::cout << "Leaf " << name_ << " operation" << std::endl;
}