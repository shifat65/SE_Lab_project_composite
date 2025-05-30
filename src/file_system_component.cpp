#include "file_system_component.h"
#include "iostream"

void FileSystemComponent::add(std::shared_ptr<FileSystemComponent> component) {
    throw std::runtime_error("Unsupported operation: add()");
}

void FileSystemComponent::remove(std::shared_ptr<FileSystemComponent> component) {
    throw std::runtime_error("Unsupported operation: remove()");
}

std::shared_ptr<FileSystemComponent> FileSystemComponent::getChild(int index) const {
    throw std::runtime_error("Unsupported operation: getChild()");
}