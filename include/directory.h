#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "file_system_component.h"
#include <vector>

class Directory : public FileSystemComponent {
public:
    Directory(const std::string& name);
    std::string getName() const override;
    size_t getSize() const override;
    void display(int indent = 0) const override;
    
    // Composite operations
    void add(std::shared_ptr<FileSystemComponent> component) override;
    void remove(std::shared_ptr<FileSystemComponent> component) override;
    std::shared_ptr<FileSystemComponent> getChild(int index) const override;
    size_t getChildCount() const;
    
private:
    std::string name_;
    std::vector<std::shared_ptr<FileSystemComponent>> children_;
};

#endif