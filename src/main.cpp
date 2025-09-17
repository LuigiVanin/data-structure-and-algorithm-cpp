#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
// #include "BinarySearchTree/BinarySearchTree.h"
#include <vector>
#include "Graph/Graph.h"

int main()
{
    std::cout << "Hello, World!!!" << std::endl;

    auto graph = new GraphBase<std::string>();
    auto vertex_id = graph->AddVertex("Joao");

    std::cout << "Vertex Id: " << vertex_id << "\n";

    vertex_id = graph->AddVertex("Maria");

    std::cout << "Vertex Id: " << vertex_id << "\n";

    vertex_id = graph->AddVertex("Lucia");

    std::cout << "Vertex Id: " << vertex_id << "\n";

    vertex_id = graph->AddVertex("Henrique");

    std::cout << "Vertex Id: " << vertex_id << "\n";

    // graph->AddDirectionalEdge(0, 1);
    // graph->AddDirectionalEdge(0, 3);
    // graph->AddDirectionalEdge(3, 0);
    // graph->AddDirectionalEdge(1, 3);
    // graph->AddDirectionalEdge(2, 0);
    // graph->AddDirectionalEdge(2, 1);
    // graph->AddDirectionalEdge(2, 2);
    // graph->AddDirectionalEdge(2, 3);
    graph->AddEdge(3, 0);
    graph->AddEdge(3, 1);
    graph->AddEdge(3, 2);
    graph->AddEdge(2, 2);
    graph->AddEdge(2, 0);
    graph->AddEdge(3, 3);

    // std::cout << "Teste: " << graph->edges.At(2)->At(0).id << "\n";
    // std::cout << "Teste: " << graph->GetVertexContent(3) << "\n";

    // graph->AddEdge(2, 1);

    graph->PrintGraph();

    return 0;
}
