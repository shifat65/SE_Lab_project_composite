#include "directory.h"
#include "iostream"
#include <algorithm>

Directory::Directory(const std::string& name) : name_(name) {}

std::string Directory::getName() const { return name_; }

size_t Directory::getSize() const {
    size_t totalSize = 0;
    for (const auto& child : children_) {
        totalSize += child->getSize();
    }
    return totalSize;
}

void Directory::display(int indent) const {
    std::cout << std::string(indent, ' ') << "+ " << name_ 
              << " (dir, " << getSize() << " bytes)" << std::endl;
    for (const auto& child : children_) {
        child->display(indent + 2);
    }
}

void Directory::add(std::shared_ptr<FileSystemComponent> component) {
    children_.push_back(component);
}

void Directory::remove(std::shared_ptr<FileSystemComponent> component) {
    children_.erase(std::remove(children_.begin(), children_.end(), component), 
                  children_.end());
}

std::shared_ptr<FileSystemComponent> Directory::getChild(int index) const {
    if (index < 0 || index >= children_.size()) {
        return nullptr;
    }
    return children_[index];
}