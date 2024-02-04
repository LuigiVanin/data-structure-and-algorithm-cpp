#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
#include "LinkedQueue/LinkedQueue.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;

    auto queue = new LinkedQueue<int>();
    queue->Add(12);
    queue->Add(1345);
    queue->Add(111);
    queue->Add(49);

    std::cout << queue->Peek() << std::endl;

    queue->Remove();

    std::cout << queue->Peek() << std::endl;

    return 0;
}
