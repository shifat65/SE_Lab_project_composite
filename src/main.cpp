#include <memory>
#include "composite.h"
#include "leaf.h"

int main() {
    // Create leaf elements
    auto leaf1 = std::make_shared<Leaf>("Leaf1");
    auto leaf2 = std::make_shared<Leaf>("Leaf2");
    auto leaf3 = std::make_shared<Leaf>("Leaf3");
    
    // Create composite elements
    auto composite1 = std::make_shared<Composite>("Composite1");
    auto composite2 = std::make_shared<Composite>("Composite2");
    
    // Build tree structure
    composite1->add(leaf1);
    composite1->add(composite2);
    composite2->add(leaf2);
    composite2->add(leaf3);
    
    // Demonstrate operations
    std::cout << "Calling operation on leaf:" << std::endl;
    leaf1->operation();
    
    std::cout << "\nCalling operation on composite1:" << std::endl;
    composite1->operation();
    
    std::cout << "\nCalling operation on composite2:" << std::endl;
    composite2->operation();
    
    return 0;
}