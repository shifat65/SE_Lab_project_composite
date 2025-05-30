#include <gtest/gtest.h>
#include <memory>
#include "composite.h"
#include "leaf.h"

class CompositeTest : public ::testing::Test {
protected:
    void SetUp() override {
        leaf1 = std::make_shared<Leaf>("Leaf1");
        leaf2 = std::make_shared<Leaf>("Leaf2");
        composite1 = std::make_shared<Composite>("Composite1");
        composite2 = std::make_shared<Composite>("Composite2");
    }

    std::shared_ptr<Leaf> leaf1;
    std::shared_ptr<Leaf> leaf2;
    std::shared_ptr<Composite> composite1;
    std::shared_ptr<Composite> composite2;
};

TEST_F(CompositeTest, LeafOperation) {
    testing::internal::CaptureStdout();
    leaf1->operation();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Leaf Leaf1 operation\n");
}

TEST_F(CompositeTest, CompositeOperationWithNoChildren) {
    testing::internal::CaptureStdout();
    composite1->operation();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Composite Composite1 operation:\n");
}

TEST_F(CompositeTest, CompositeOperationWithChildren) {
    composite1->add(leaf1);
    composite1->add(leaf2);
    
    testing::internal::CaptureStdout();
    composite1->operation();
    std::string output = testing::internal::GetCapturedStdout();
    
    std::string expected = 
        "Composite Composite1 operation:\n"
        "Leaf Leaf1 operation\n"
        "Leaf Leaf2 operation\n";
    
    EXPECT_EQ(output, expected);
}

TEST_F(CompositeTest, NestedCompositeOperation) {
    composite1->add(leaf1);
    composite1->add(composite2);
    composite2->add(leaf2);
    
    testing::internal::CaptureStdout();
    composite1->operation();
    std::string output = testing::internal::GetCapturedStdout();
    
    std::string expected = 
        "Composite Composite1 operation:\n"
        "Leaf Leaf1 operation\n"
        "Composite Composite2 operation:\n"
        "Leaf Leaf2 operation\n";
    
    EXPECT_EQ(output, expected);
}

TEST_F(CompositeTest, AddAndRemoveComponents) {
    composite1->add(leaf1);
    EXPECT_EQ(composite1->getChild(0), leaf1);
    
    composite1->remove(leaf1);
    EXPECT_EQ(composite1->getChild(0), nullptr);
}

TEST_F(CompositeTest, LeafCannotAddOrRemove) {
    EXPECT_THROW(leaf1->add(leaf2), std::runtime_error);
    EXPECT_THROW(leaf1->remove(leaf2), std::runtime_error);
    EXPECT_THROW(leaf1->getChild(0), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}