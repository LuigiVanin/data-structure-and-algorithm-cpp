#include <iostream>
// #include "ArrayList/ArrayList.h"
#include "LinkedList/LinkedList.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    auto linked_list = new LinkedList<int>();

    linked_list->Push(55);

    linked_list->Push(15);
    linked_list->Push(25);
    linked_list->Push(45);
    linked_list->Push(15);
    linked_list->Push(15);
    linked_list->Push(15);
    linked_list->Push(1000);
    linked_list->Shift(1500);
    linked_list->Insert(2000, 2);

    linked_list->Print();

    return 0;
}
