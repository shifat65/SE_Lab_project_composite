#include <memory>
#include "iostream"
#include "directory.h"
#include "file.h"

int main() {
    // Create files
    auto file1 = std::make_shared<File>("document.txt", 1500);
    auto file2 = std::make_shared<File>("image.jpg", 3500);
    auto file3 = std::make_shared<File>("notes.txt", 500);
    
    // Create directories
    auto rootDir = std::make_shared<Directory>("Root");
    auto documentsDir = std::make_shared<Directory>("Documents");
    auto imagesDir = std::make_shared<Directory>("Images");
    
    // Build the file system structure
    rootDir->add(documentsDir);
    rootDir->add(imagesDir);
    documentsDir->add(file1);
    documentsDir->add(file3);
    imagesDir->add(file2);
    
    // Display the file system
    std::cout << "File System Structure:" << std::endl;
    rootDir->display();
    
    // Show total size
    std::cout << "\nTotal size of root: " << rootDir->getSize() << " bytes" << std::endl;
    
    return 0;
}