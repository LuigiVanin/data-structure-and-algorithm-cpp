#include <iostream>
// #include "ArrayList/ArrayList.h"
#include "LinkedList/LinkedList.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    auto linked_list = new LinkedList<int>();

    linked_list->Push(55);
    linked_list->Print();

    return 0;
}
