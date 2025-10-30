# Data Structures and Algorithms in C++

A comprehensive collection of data structures and algorithms implemented in modern C++ (C++23) for educational purposes and technical interviews preparation.

## 📚 Overview

This repository contains well-tested implementations of fundamental data structures and sorting algorithms, following modern C++ best practices with extensive unit tests using Catch2.

## 🎯 Features

- **Modern C++23** implementation with smart pointers and templates
- **Comprehensive test coverage** using Catch2 framework
- **Docker support** for consistent development environment
- **CMake build system** for cross-platform compatibility

## 📦 Data Structures

### Linear Data Structures
- **ArrayList** - Dynamic array with automatic resizing
- **LinkedList** - Singly linked list implementation
- **DoublyLinkedList** - Doubly linked list with bidirectional traversal
- **ArrayStack** - Stack implementation using arrays
- **LinkedQueue** - Queue implementation using linked nodes

### Non-Linear Data Structures
- **BinarySearchTree** - Self-organizing binary search tree with concepts
- **AVL** - Self-organizing binary tree with self balance methods
- **Graph** - Graph implementation with Dijkstra's shortest path algorithm
- **Hashmap** - Custom hash table implementation

### Utilities
- **Custom Error Handling** - Exception types for container operations
- **Option Type** - Optional value wrapper for safe null handling

## 🔄 Algorithms

### Sorting Algorithms
- **Bubble Sort** - Simple comparison-based sorting
- **Insertion Sort** - Efficient for small or nearly sorted datasets
- **Quick Sort** - Fast divide-and-conquer sorting (implementation in progress)

All sorting algorithms support custom comparison functions for flexible ordering.

### Graph Algorithms
- **Dijkstra's Algorithm** - Shortest path finding
- **Path Reconstruction** - Extract complete paths from Dijkstra results

## 🚀 Getting Started

### Prerequisites

- C++23 compatible compiler (GCC 12+, Clang 15+, or MSVC 2022+)
- CMake 3.21 or higher
- Catch2 v3 (for testing)

### Building from Source

```bash
# Clone the repository
git clone <repository-url>
cd data-structure-and-algorithm-cpp

# Configure and build
cmake .
make

# Run the main executable
./bin/data_structure_and_algorithm_cpp
```

### Running Tests

```bash
# Run all tests
ctest --output-on-failure

# Run specific test
ctest -R <test_name>
```

### Using the Build Script

The repository includes a convenient build script:

```bash
# Normal build and run
./run.sh

# Build with debug symbols
./run.sh debug

# Build and run tests
./run.sh test

# Build, test, and clean
./run.sh test clean
```

### Docker Support

Build and run using Docker:

```bash
# Build the Docker image
docker build -t dsa-cpp .

# Run tests in container
docker run dsa-cpp
```

## 💻 Usage Examples

### ArrayList

```cpp
#include "ArrayList/ArrayList.h"

ArrayList<int> list;
list.Push(10);
list.Push(20);
list.Insert(15, 1);  // Insert 15 at index 1
int value = list.At(0);  // Access element at index 0
list.Remove(1);  // Remove element at index 1
```

### LinkedList

```cpp
#include "LinkedList/LinkedList.h"

LinkedList<int> list;
list.Push(10);      // Add to end
list.Shift(5);      // Add to beginning
list.Insert(7, 1);  // Insert at position
list.Pop();         // Remove from end
```

### Binary Search Tree

```cpp
#include "BinarySearchTree/BinarySearchTree.h"

BinarySearchTree<int> bst;
bst.Insert(50);
bst.Insert(30);
bst.Insert(70);

if (bst.HasValue(30)) {
    auto node = bst.Search(30);
}

bst.Remove(30);
```

### Graph with Dijkstra

```cpp
#include "Graph/Graph.h"

GraphBase<std::string> graph;

uint v1 = graph.AddVertex("A");
uint v2 = graph.AddVertex("B");
uint v3 = graph.AddVertex("C");

graph.AddEdge(v1, v2, 4.0);  // A <-> B with weight 4
graph.AddEdge(v2, v3, 3.0);  // B <-> C with weight 3

auto distances = graph.Dijkstra(v1);
auto path = graph.DijkstraPath(v1, v3);
```

### Sorting

```cpp
#include "Sorting/Sorting.h"
#include "ArrayList/ArrayList.h"

ArrayList<int> list;
list.Push(5);
list.Push(2);
list.Push(8);
list.Push(1);

// Sort using default comparison
sorting::BubbleSort(&list);

// Sort with custom comparison (descending order)
auto descendingCompare = [](int a, int b) {
    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
};

sorting::InsertionSort(&list, descendingCompare);
```

## 🧪 Testing

All data structures and algorithms are thoroughly tested using the Catch2 framework. Test files are located in the `tests/` directory and mirror the structure of the source files:

- `ArrayList.test.cpp`
- `ArrayStack.test.cpp`
- `BinarySearchTree.test.cpp`
- `DoublyLinkedList.test.cpp`
- `Graph.test.cpp`
- `Hashmap.test.cpp`
- `LinkedList.test.cpp`
- `LinkedQueue.test.cpp`
- `Sorting.test.cpp`


## 📄 License

This project is available for educational purposes. See `license.md` for details.

## 🔮 Future Enhancements

- [ ] Complete QuickSort implementation
- [ ] Add Merge Sort and Heap Sort
- [ ] Implement AVL Tree (self-balancing BST)
- [ ] Add Red-Black Tree
- [ ] Implement Trie data structure
- [x] Add more graph algorithms (BFS, DFS, MST)
- [ ] More comprehensive documentation


---

**Happy Coding!** 🚀

