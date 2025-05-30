#include <gtest/gtest.h>
#include <memory>
#include "directory.h"
#include "file.h"

class FileSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        file1 = std::make_shared<File>("test1.txt", 100);
        file2 = std::make_shared<File>("test2.txt", 200);
        dir1 = std::make_shared<Directory>("TestDir");
    }

    std::shared_ptr<File> file1;
    std::shared_ptr<File> file2;
    std::shared_ptr<Directory> dir1;
};

TEST_F(FileSystemTest, FileProperties) {
    EXPECT_EQ(file1->getName(), "test1.txt");
    EXPECT_EQ(file1->getSize(), 100);
}

TEST_F(FileSystemTest, DirectoryAddAndSize) {
    dir1->add(file1);
    dir1->add(file2);
    
    EXPECT_EQ(dir1->getSize(), 300);
    EXPECT_EQ(dir1->getChild(0), file1);
}

TEST_F(FileSystemTest, DirectoryRemove) {
    dir1->add(file1);
    dir1->remove(file1);
    
    EXPECT_EQ(dir1->getSize(), 0);
    EXPECT_EQ(dir1->getChild(0), nullptr);
}

TEST_F(FileSystemTest, NestedDirectories) {
    auto subDir = std::make_shared<Directory>("SubDir");
    subDir->add(file1);
    dir1->add(subDir);
    
    EXPECT_EQ(dir1->getSize(), 100);
    EXPECT_EQ(subDir->getSize(), 100);
}

TEST_F(FileSystemTest, FileCannotAddChildren) {
    EXPECT_THROW(file1->add(file2), std::runtime_error);
    EXPECT_THROW(file1->getChild(0), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}