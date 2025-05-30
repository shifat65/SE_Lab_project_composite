#ifndef FILE_SYSTEM_COMPONENT_H
#define FILE_SYSTEM_COMPONENT_H

#include <string>
#include <vector>
#include <memory>

class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;
    virtual std::string getName() const = 0;
    virtual size_t getSize() const = 0;
    virtual void display(int indent = 0) const = 0;
    
    // For composite operations
    virtual void add(std::shared_ptr<FileSystemComponent> component);
    virtual void remove(std::shared_ptr<FileSystemComponent> component);
    virtual std::shared_ptr<FileSystemComponent> getChild(int index) const;
};

#endif