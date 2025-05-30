#include "iostream"
#include <memory>
#include "directory.h"
#include "file.h"

int main() {
    // Create files
    auto resume = std::make_shared<File>("resume.pdf", 2500);
    auto vacationPhoto = std::make_shared<File>("vacation.jpg", 4200);
    auto notes = std::make_shared<File>("notes.txt", 300);
    auto budget = std::make_shared<File>("budget.xlsx", 1800);
    
    // Create directories
    auto homeDir = std::make_shared<Directory>("Home");
    auto documentsDir = std::make_shared<Directory>("Documents");
    auto picturesDir = std::make_shared<Directory>("Pictures");
    auto projectsDir = std::make_shared<Directory>("Projects");
    
    // Build the file system structure
    homeDir->add(documentsDir);
    homeDir->add(picturesDir);
    homeDir->add(projectsDir);
    
    documentsDir->add(resume);
    documentsDir->add(notes);
    documentsDir->add(budget);
    
    picturesDir->add(vacationPhoto);
    
    // Display the file system
    std::cout << "File System Structure:" << std::endl;
    homeDir->display();
    
    // Show statistics
    std::cout << "\nStatistics:" << std::endl;
    std::cout << "Total size of Home: " << homeDir->getSize() << " bytes" << std::endl;
    std::cout << "Documents folder size: " << documentsDir->getSize() << " bytes" << std::endl;
    std::cout << "Number of items in Documents: " 
              << documentsDir->getChildCount() << std::endl;
    
    return 0;
}