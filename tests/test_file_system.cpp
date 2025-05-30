#include <gtest/gtest.h>
#include <memory>
#include "directory.h"
#include "file.h"

class FileSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        file1 = std::make_shared<File>("report.doc", 1200);
        file2 = std::make_shared<File>("presentation.ppt", 3500);
        rootDir = std::make_shared<Directory>("Root");
    }

    std::shared_ptr<File> file1;
    std::shared_ptr<File> file2;
    std::shared_ptr<Directory> rootDir;
};

// Component tests
TEST_F(FileSystemTest, FileCreation) {
    EXPECT_EQ(file1->getName(), "report.doc");
    EXPECT_EQ(file1->getSize(), 1200);
    
    testing::internal::CaptureStdout();
    file1->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "- report.doc (1200 bytes)\n");
}

TEST_F(FileSystemTest, DirectoryCreation) {
    EXPECT_EQ(rootDir->getName(), "Root");
    EXPECT_EQ(rootDir->getSize(), 0);
    EXPECT_EQ(rootDir->getChildCount(), 0);
}

// Directory Operations Tests
TEST_F(FileSystemTest, AddSingleFile) {
    rootDir->add(file1);
    EXPECT_EQ(rootDir->getChildCount(), 1);
    EXPECT_EQ(rootDir->getSize(), 1200);
    EXPECT_EQ(rootDir->getChild(0), file1);
}

TEST_F(FileSystemTest, AddMultipleFiles) {
    rootDir->add(file1);
    rootDir->add(file2);
    EXPECT_EQ(rootDir->getChildCount(), 2);
    EXPECT_EQ(rootDir->getSize(), 4700);
}

TEST_F(FileSystemTest, RemoveFile) {
    rootDir->add(file1);
    rootDir->remove(file1);
    EXPECT_EQ(rootDir->getChildCount(), 0);
    EXPECT_EQ(rootDir->getSize(), 0);
}

TEST_F(FileSystemTest, RemoveNonexistentFile) {
    rootDir->add(file1);
    rootDir->remove(file2); // Not added
    EXPECT_EQ(rootDir->getChildCount(), 1); // Should remain unchanged
}

// Edge Case Tests
TEST_F(FileSystemTest, GetInvalidChildIndex) {
    rootDir->add(file1);
    EXPECT_EQ(rootDir->getChild(-1), nullptr); // Negative index
    EXPECT_EQ(rootDir->getChild(1), nullptr); // Out of bounds
}

TEST_F(FileSystemTest, EmptyDirectoryOperations) {
    EXPECT_EQ(rootDir->getChild(0), nullptr);
    testing::internal::CaptureStdout();
    rootDir->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "+ Root (dir, 0 bytes)\n");
}

//Nested Structure Tests

TEST_F(FileSystemTest, NestedDirectories) {
    auto subDir = std::make_shared<Directory>("Subfolder");
    subDir->add(file1);
    rootDir->add(subDir);
    
    EXPECT_EQ(rootDir->getChildCount(), 1);
    EXPECT_EQ(rootDir->getSize(), 1200);
    EXPECT_EQ(subDir->getSize(), 1200);
}

TEST_F(FileSystemTest, DeeplyNestedStructure) {
    auto dir1 = std::make_shared<Directory>("Level1");
    auto dir2 = std::make_shared<Directory>("Level2");
    auto dir3 = std::make_shared<Directory>("Level3");
    
    dir3->add(file1);
    dir2->add(dir3);
    dir1->add(dir2);
    rootDir->add(dir1);
    
    EXPECT_EQ(rootDir->getSize(), 1200);
    EXPECT_EQ(dir1->getSize(), 1200);
    EXPECT_EQ(dir2->getSize(), 1200);
    EXPECT_EQ(dir3->getSize(), 1200);
}
// Invalud Operation Tests
TEST_F(FileSystemTest, InvalidOperationsOnFiles) {
    EXPECT_THROW(file1->add(file2), std::runtime_error);
    EXPECT_THROW(file1->remove(file2), std::runtime_error);
    EXPECT_THROW(file1->getChild(0), std::runtime_error);
}
// Display formatting tests
TEST_F(FileSystemTest, DisplayFormatting) {
    auto subDir = std::make_shared<Directory>("Sub");
    subDir->add(file1);
    rootDir->add(subDir);
    rootDir->add(file2);
    
    testing::internal::CaptureStdout();
    rootDir->display();
    std::string output = testing::internal::GetCapturedStdout();
    
    std::string expected = 
        "+ Root (dir, 4700 bytes)\n"
        "  + Sub (dir, 1200 bytes)\n"
        "    - report.doc (1200 bytes)\n"
        "  - presentation.ppt (3500 bytes)\n";
    
    EXPECT_EQ(output, expected);
}
//Stress Tests
TEST_F(FileSystemTest, LargeNumberOfFiles) {
    const int NUM_FILES = 1000;
    for (int i = 0; i < NUM_FILES; i++) {
        auto file = std::make_shared<File>("file" + std::to_string(i), i);
        rootDir->add(file);
    }
    EXPECT_EQ(rootDir->getChildCount(), NUM_FILES);
    EXPECT_EQ(rootDir->getSize(), NUM_FILES * (NUM_FILES - 1) / 2); // Sum of 0..999
}

TEST_F(FileSystemTest, DeepDirectoryTree) {
    std::shared_ptr<Directory> current = rootDir;
    const int DEPTH = 50;
    
    for (int i = 0; i < DEPTH; i++) {
        auto newDir = std::make_shared<Directory>("Level" + std::to_string(i));
        current->add(newDir);
        current = newDir;
    }
    
    current->add(file1);
    EXPECT_EQ(rootDir->getSize(), 1200);
    EXPECT_EQ(rootDir->getChildCount(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}