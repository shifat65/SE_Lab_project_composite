#include "component.h"

// Default implementations for Component methods
void Component::add(std::shared_ptr<Component> component) {
    throw std::runtime_error("Unsupported operation: add()");
}

void Component::remove(std::shared_ptr<Component> component) {
    throw std::runtime_error("Unsupported operation: remove()");
}

std::shared_ptr<Component> Component::getChild(int index) const {
    throw std::runtime_error("Unsupported operation: getChild()");
}