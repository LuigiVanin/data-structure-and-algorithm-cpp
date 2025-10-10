#include <iostream>
// #include "ArrayList/ArrayList.h"
// #include "LinkedList/LinkedList.h"
// #include "DoublyLinkedList/DoublyLinkedList.h"
// #include "ArrayStack/ArrayStack.h"
// #include "LinkedQueue/LinkedQueue.h"
// #include "Hashmap/Hashmap.h"
// #include "BinarySearchTree/BinarySearchTree.h"
#include "Graph/Graph.h"
#include <vector>

void updateArray(std::vector<bool> &arr, int index) {
    arr[index] = true;
}

int main() {
    std::cout << "Hello, World!!!" << std::endl;

    // auto graph = new GraphWithDFS<std::string>();
    // auto vertex_id = graph->AddVertex("Joao");

    // std::cout << "Vertex Id: " << vertex_id << "\n";

    // vertex_id = graph->AddVertex("Maria");

    // std::cout << "Vertex Id: " << vertex_id << "\n";

    // vertex_id = graph->AddVertex("Lucia");

    // std::cout << "Vertex Id: " << vertex_id << "\n";

    // vertex_id = graph->AddVertex("Henrique");

    // std::cout << "Vertex Id: " << vertex_id << "\n";

    // vertex_id = graph->AddVertex("Mario");

    // vertex_id = graph->AddVertex("Joao");

    // vertex_id = graph->AddVertex("Pablo");

    // // graph->AddDirectionalEdge(0, 1);
    // // graph->AddDirectionalEdge(0, 3);
    // // graph->AddDirectionalEdge(3, 0);
    // // graph->AddDirectionalEdge(1, 3);
    // // graph->AddDirectionalEdge(2, 0);
    // // graph->AddDirectionalEdge(2, 1);
    // // graph->AddDirectionalEdge(2, 2);
    // // graph->AddDirectionalEdge(2, 3);
    // // graph->AddEdge(3, 0);
    // graph->AddEdge(3, 1);
    // graph->AddEdge(3, 2);
    // graph->AddEdge(2, 2);
    // graph->AddEdge(2, 0);
    // graph->AddEdge(3, 3);
    // graph->AddEdge(4, 5);
    // // graph->AddEdge(4, 6);
    // // graph->AddEdge(3, 5);

    // // std::cout << "Teste: " << graph->edges.At(2)->At(0).id << "\n";
    // // std::cout << "Teste: " << graph->GetVertexContent(3) << "\n";

    // // graph->AddEdge(2, 1);

    // graph->PrintGraph();
    // std::vector<bool> visited(graph->edges.Length(), false);
    // graph->Dfs(0, visited);

    // for (const bool &item : visited) {
    //     std::cout << "" << item << ", ";
    // }

    // auto result = graph->IsConnected(6, 1);

    // std::cout << "Resultado: " << result << "\n";

    // auto count = graph->ComponentsCount();
    // std::cout << "Counter: " << count << "\n";

    // auto distances = graph->Dijkstra(0);

    // std::cout << "Dikjstra: " << "\n";

    // for (const auto &d : distances) {
    //     std::cout << d << "\n";
    // }

    // auto path = graph->DijkstraPath(0, 1);
    // std::cout << "Dikjstra: " << path.size() << "\n";

    // for (const auto &v : path) {
    //     std::cout << v << "\n";
    // }

    auto graph = new GraphWithDFS<int>();
    graph->AddVertex(0);
    graph->AddVertex(1);
    graph->AddVertex(2);
    graph->AddVertex(3);
    graph->AddVertex(4);
    graph->AddVertex(5);
    graph->AddVertex(7);

    graph->AddDirectionalEdge(0, 1, 2);
    graph->AddDirectionalEdge(0, 2, 1);
    graph->AddDirectionalEdge(0, 4, 10);

    graph->AddDirectionalEdge(1, 5, 1);

    graph->AddDirectionalEdge(2, 3, 6);
    graph->AddDirectionalEdge(2, 4, 4);

    graph->AddDirectionalEdge(4, 3, 1);

    graph->AddDirectionalEdge(5, 4, 1);

    graph->PrintGraph();

    std::cout << "Count: " << graph->ComponentsCount() << "\n";
    // Should be 2

    auto distances = graph->Dijkstra(0);
    // should be [0, 2, 1, 5, 4, 3, FLOAT_MAX]

    std::cout << "\nDikjstra: " << "\n";

    for (const auto &d : distances) {
        std::cout << d << ", ";
    }

    auto path = graph->DijkstraPath(0, 4);

    std::cout << "\nDikjstra: " << path.size() << "\n";
    // should be [0 1 5 4]

    for (const auto &v : path) {
        std::cout << v << "\n";
    }

    return 0;
}
