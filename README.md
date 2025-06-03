# File_System

A C++ implementation of the Composite Design Pattern representing a hierarchical file system. This project was developed as part of the CSE 3206 (Software Engineering Sessional) coursework and includes unit tests using Google Test (GTest).

---

## Project Structure

```

FileSystemComposite
├── include
│   ├── file_system_component.h   # Abstract base class
│   ├── file.h                    # Leaf class (File)
│   └── directory.h               # Composite class (Directory)
├── src
│   ├── file_system_component.cpp
│   ├── file.cpp
│   ├── directory.cpp
│   └── main.cpp                  # Demo program
├── tests
│   └── test_file_system.cpp    # Unit tests
|   └── CMakeLists.txt   
├── googletest                   # Google Test framework
├── CMakeLists.txt
└── README.md

````

---

## **Design Pattern Used**

**Composite Pattern** – This pattern allows you to compose objects into tree structures and work with them as if they were individual objects.

- `FileSystemComponent` – Abstract base class
- `File` – Leaf class that cannot contain children
- `Directory` – Composite class that can hold `File` and other `Directory` objects

---
## **File Description**

### Header Files
1. **`file_system_component.h`**  
   - Base abstract class defining the common interface for all file system elements
   - Declares core operations (`getName()`, `getSize()`, `display()`) and default implementations for child management

2. **`file.h`** (Leaf)  
   - Represents individual files in the system  
   - Implements file-specific behavior (name, size)  
   - Cannot have children (throws exceptions for add/remove operations)

3. **`directory.h`** (Composite)  
   - Represents folders that can contain files or other directories  
   - Manages a collection of child components  
   - Implements recursive size calculation and hierarchical display
   - Provide composite operations (`add()`, `remove()`, `getChildCount()`)

---

### Source Files
4. **`file_system_component.cpp`**  
   - Provides default implementations that throw exceptions for leaf nodes  
   - Ensures leaf components (Files) can't accidentally modify children

5. **`file.cpp`**  
   - Implements concrete file operations  
   - Returns fixed size and name  
   - Simple display formatting for files

6. **`directory.cpp`**  
   - Handles recursive operations:  
     - `getSize()`: Sums sizes of all children  
     - `display()`: Shows tree structure with indentation  
   - Manages child components via
     - `add()`: Add new file or folder
     - `remove()`: Remove any file or folder
     - `getChild()`: Returns the Childs
     - `getChildCount()`: Returns total child count

7. **`main.cpp`**  
   - Demo program that:  
     1. Creates a sample file system hierarchy  
     2. Shows recursive display functionality  
     3. Calculates total directory sizes  

---

### Test File
8. **`test_file_system.cpp`**  
   - Unit tests verifying:  
     - File properties (name/size)  
     - Directory operations (add/remove/getChildCount)  
     - Nested structure handling  
     - Error cases (e.g., adding children to files)  
   - Uses Google Test framework

---

### Key Relationships
- **`FileSystemComponent`** ← (inherited by) → **`File`** (leaf) and **`Directory`** (composite)
- **`Directory`** contains a collection of **`FileSystemComponent`** pointers (enabling recursive structures)
- All components share the same interface (`display()`, `getSize()`), enabling uniform treatment
---
## **Build and Run**

### Prerequisites

- CMake ≥ 3.10
- C++17 compiler
- Git

### Steps

```bash
git clone https://github.com/shifat65/SE_Lab_project_composite.git
cd FileSystemComposite
rm -rf build
mkdir build && cd build
cmake ..
make
````

### Run Demo

```bash
./file_system_demo
```

### Run Tests

```bash
./tests/file_system_tests
```

---

## Sample Output

```
File System Structure:
+ Home (dir, 8800 bytes)
  + Documents (dir, 4600 bytes)
    - resume.pdf (2500 bytes)
    - notes.txt (300 bytes)
    - budget.xlsx (1800 bytes)
  + Pictures (dir, 4200 bytes)
    - vacation.jpg (4200 bytes)
  + Projects (dir, 0 bytes)

Statistics:
Total size of Home: 8800 bytes
Documents folder size: 4600 bytes
Number of items in Documents: 3
```

---

## **Tests**

The project includes 14 unit tests covering:
   * File and directory creation
   * Size calculations
   * Nesting validation
   * Display formatting
   * Edge case handling
---

### Independent Paths Covered
1. File Operations Path
   * File creation and properties
   * File display formatting
   * Invalid operations on files

2. Directory Operations Path
   * Empty directory operations
   * Single file operations
   * Multiple file operations
   * File removal cases

3. Nested Structure Path
   * Shallow nesting
   * Deep nesting
   * Mixed files and directories

4. Error Handling Path
   * Invalid indices
   * Operations on wrong types
   * Nonexistent removal

5. Display Formatting Path
   * Empty display
   * Simple display
   * Complex hierarchical display

6. Stress Test Path
   * Large number of files
   * Deep directory structures
   * Memory management

