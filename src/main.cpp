#include <iostream>
#include "ArrayList/ArrayList.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    auto list = new ArrayList<int>();

    list->Print();
    list->Push(1);
    list->Push(2);
    list->Push(3);
    list->Push(4);
    list->Push(5);
    list->Push(6);
    list->Push(7);

    list->Print();
    list->Push(8);
    list->Push(9);
    list->Push(10);
    list->Push(11);
    list->Push(12);
    list->Push(13);
    list->Push(14);
    list->Print();

    list->Push(15);
    list->Push(16);
    list->Push(17);
    list->Push(18);
    list->Push(19);
    list->Push(20);
    list->Push(21);

    list->Print();

    list->Insert(1000, 2);
    list->Print();
    list->Insert(1000, 0);
    list->Print();

    list->Insert(1000, list->length);

    list->Print();

    return 0;
}
