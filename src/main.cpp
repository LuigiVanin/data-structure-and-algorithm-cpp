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

    std::cout << "Amount: " << bst->Amount() << std::endl;
    std::cout << "Root: " << root->GetValue() << std::endl;
    std::cout << "Root left: " << root->left->right->GetValue() << std::endl;

    auto value = bst->Search(200);

    if (value == nullptr)
    {
        std::cout << "Founded shit: " << "missing value" << std::endl;
    }
    else
        std::cout << "Founded shit: " << value->GetValue() << std::endl;

    auto hasValue = bst->HasValue(200);

    std::cout << "Has Value: " << hasValue << std::endl;

    bst->Clear();

    std::cout << "Amount: " << bst->Amount() << std::endl;

    bst->Insert(10);
    bst->Insert(5);
    bst->Insert(15);

    std::cout << "Amount: " << bst->Amount() << std::endl;

    return 0;
}
