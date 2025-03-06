#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
#include "BinarySearchTree/BinarySearchTree.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;

    auto bst = new BinarySearchTree<int>();

    std::cout << "End worlds" << std::endl;

    bst->Insert(10);
    bst->Insert(5);
    bst->Insert(15);
    bst->Insert(3);
    bst->Insert(7);
    bst->Insert(12);
    bst->Insert(17);

    auto root = bst->GetRoot();

        return 0;
}
