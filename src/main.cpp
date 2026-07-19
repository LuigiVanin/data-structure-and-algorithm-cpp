#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
// #include "BinarySearchTree/BinarySearchTree.h"
// #include "Graph/Graph.h"
// #include <vector>
// #include "Sorting/Sorting.h"

#include "AvlTree/AvlTree.h"

int main() {

    // auto list = new ArrayList<int>();
    auto tree = new AvlTree<int>();

    auto depth = tree->Depth();

    std::cout << depth << std::endl;

    // list->Push(15);
    // list->Push(100);
    // list->Push(120);
    // list->Push(15);
    // list->Push(1);
    // list->Push(19);

    // list->Print();
    // sorting::BubbleSort(list);
    // sorting::QuickSort(list);
    // sorting::SelectionSort(list);
    // list->Print();

    return 0;
}
