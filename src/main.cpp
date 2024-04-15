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

    map->Get("Não tem nada");
    auto value = map->Get("Outro teste");

    if (value.IsSome())
    {
        std::cout << "Value found: " << value.Unwrap() << "\n";
    }

    delete map;
    return 0;
}
