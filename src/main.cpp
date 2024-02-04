#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
#include "DoublyLinkedList/DoublyLinkedList.h"
#include "ArrayStack/ArrayStack.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;
    auto stack = new ArrayStack<int>();
    stack->Push(12);
    stack->Push(78);
    auto top = stack->Top();
    std::cout << top << std::endl;

    stack->Pop();

    top = stack->Top();
    std::cout << top << std::endl;

    delete stack;

    return 0;
}
