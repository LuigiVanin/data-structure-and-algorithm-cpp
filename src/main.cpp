#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
#include <vector>
#include "BinarySearchTree/BinarySearchTree.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;

    auto bst = new BinarySearchTree<int>();

    std::vector<int> targetValues = {};
    std::cout << "Amount: " << bst->Amount() << std::endl;

    for (int i = 0; i < 20; i++)
    {
        const int random = rand() % 100;
        targetValues.push_back(random);
        bst->Insert(random);
    }

    std::cout << "Amount: " << bst->Amount() << std::endl;

    return 0;
}
