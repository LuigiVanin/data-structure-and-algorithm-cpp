#include "ArrayList/ArrayList.h"
#include <iostream>
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
// #include "BinarySearchTree/BinarySearchTree.h"
// #include "Graph/Graph.h"
// #include <vector>
#include "Sorting/Sorting.h"

int main() {

    auto list = new ArrayList<int>();

    list->Push(15);
    list->Push(19);
    list->Push(120);
    list->Push(15);
    list->Push(1);
    list->Push(1000);

    list->Print();
    sorting::BubbleSort(list);
    list->Print();

    return 0;
}
