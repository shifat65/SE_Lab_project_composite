#include "file.h"
#include <iostream>

File::File(const std::string& name, size_t size) : name_(name), size_(size) {}

std::string File::getName() const { return name_; }

size_t File::getSize() const { return size_; }

void File::display(int indent) const {
    std::cout << std::string(indent, ' ') << "- " << name_ 
              << " (" << size_ << " bytes)" << std::endl;
}