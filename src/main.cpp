#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
#include "Hashmap/Hashmap.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;

    auto map = new Hashmap<std::string, int>();
    map->Put("Teste", 2);
    map->Put("Mais um teste", 4);
    map->Put("Outro teste", 12);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);

    std::cout << "Length: " << map->GetLength() << "\n";

    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);

    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 31);
    map->Put("Outro teste", 55);
    auto value = map->Get("Outro teste");
    map->Put("Outro teste", 41);

    if (value.IsNone())
    {
        std::cout << "Value not found" << std::endl;
    }
    else
    {
        std::cout << "Value: " << value.Unwrap() << std::endl;
    }

    delete map;
    return 0;
}
