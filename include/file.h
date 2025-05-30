#ifndef FILE_H
#define FILE_H

#include "file_system_component.h"

class File : public FileSystemComponent {
public:
    File(const std::string& name, size_t size);
    std::string getName() const override;
    size_t getSize() const override;
    void display(int indent = 0) const override;

private:
    std::string name_;
    size_t size_;
};

#endif // FILE_H