#include "composite.h"
#include <algorithm> // Add this include for std::remove

Composite::Composite(const std::string& name) : name_(name) {}

void Composite::operation() const {
    std::cout << "Composite " << name_ << " operation:" << std::endl;
    for (const auto& child : children_) {
        child->operation();
    }
}

void Composite::add(std::shared_ptr<Component> component) {
    children_.push_back(component);
}

void Composite::remove(std::shared_ptr<Component> component) {
    // Correct implementation using erase-remove idiom
    children_.erase(
        std::remove(children_.begin(), children_.end(), component),
        children_.end()
    );
}

std::shared_ptr<Component> Composite::getChild(int index) const {
    if (index < 0 || index >= children_.size()) {
        return nullptr;
    }
    return children_[index];
}