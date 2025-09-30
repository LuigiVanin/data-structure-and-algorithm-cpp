#include "Graph.h"
#include "../ArrayList/ArrayList.h"
#include "../Hashmap/Hashmap.h"
#include "../LinkedQueue/LinkedQueue.h"
#include <cmath>
#include <vector>

template <class T> GraphBase<T>::GraphBase() {
    std::cout << "Teste" << std::endl;
    // this->edges = ArrayList<ArrayList<GraphNode> *>();
    std::cout << "Teste" << this->edges.Length() << std::endl;
}

template <class T> GraphBase<T>::~GraphBase() {
    for (int i = 0; i < edges.Length(); ++i) delete this->edges.At(i);
}

template <class T> unsigned int GraphBase<T>::AddVertex(T content) {
    auto empty = new ArrayList<GraphNode>();
    this->edges.Push(empty);

    auto node_id = this->edges.Length() - 1;
    if (node_id < 0) throw std::runtime_error("Node id value is not expected");

    this->content_table.Put(node_id, content);

    return (unsigned int)node_id;
}

template <class T>
void GraphBase<T>::AddEdge(unsigned int from, unsigned int to, float weight) {
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    this->AddDirectionalEdge(from, to);

    if (from == to) return;

    this->AddDirectionalEdge(to, from);
}

template <class T>
void GraphBase<T>::AddDirectionalEdge(unsigned int from,
                                      unsigned int to,
                                      float        weight) {
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    auto connected_vertices = this->edges.At(from);

    for (int i = 0; i < connected_vertices->Length(); i++)
        if (connected_vertices->At(i).id == to)
            throw std::runtime_error("edges already connected");

    GraphNode to_node = {
        .weight = weight,
        .id     = (int)to,
    };

    this->edges.At(from)->Push(to_node);
}

template <class T> //
T GraphBase<T>::GetVertex(unsigned int vertex_id) {
    Option<T> value = this->content_table.Get(vertex_id);

    if (value.IsNone()) throw std::runtime_error("Vertex not found");

    return value.Unwrap();
}

template <class T> //
void GraphBase<T>::PrintGraph() {
    for (int i = 0; i < this->edges.Length(); i++) {
        std::cout << i << ": ";
        for (int j = 0; j < this->edges.At(i)->Length(); j++) {
            std::cout << this->edges.At(i)->At(j).id << " ";
        }
        std::cout << "\n";
    }
}

template <class T> //
std::vector<float> GraphBase<T>::Dijkstra(unsigned int src) {
    std::vector<bool>  visited(this->edges.Length(), false);
    std::vector<float> distances(this->edges.Length(), MAXFLOAT);

    distances[src] = 0;
}

template <class T>
void GraphWithDFS<T>::Dfs(unsigned int origin, std::vector<bool> &visited) {
    if (!visited[origin]) visited[origin] = true;

    ArrayList<GraphNode> *current_edge = this->edges.At(origin);

    for (int i = 0; i < current_edge->Length(); i++) {
        auto current_vertex_id = current_edge->At(i).id;
        if (!visited[current_vertex_id]) this->Dfs(current_vertex_id, visited);
    }
}

template <class T>
bool GraphWithDFS<T>::IsConnected(unsigned int origin, unsigned int target) {
    std::vector<bool> visited(this->edges.Length(), false);

    this->Dfs(origin, visited);

    return visited[target];
}

template <class T> //
int GraphWithDFS<T>::ComponentsCount() {
    int counter = 0;

    std::vector<bool> visited(this->edges.Length(), false);

    for (int i = 0; i < (int)visited.size(); i++) {
        if (!visited[i]) {
            counter++;
            this->Dfs(i, visited);
        }
    }

    return counter;
}

template <class T>
void GraphWithBFS<T>::Bfs(unsigned int origin, std::vector<bool> &visited) {
    LinkedQueue<int> queue;

    queue.Add(origin);

    while (!queue.IsEmpty()) {
        auto head = queue.Remove();

        if (!visited[head]) visited[head] = true;

        ArrayList<GraphNode> *current_edge = this->edges.At(head);

        for (int i = 0; i < current_edge->Length(); i++) {
            auto current_vertex_id = current_edge->At(i).id;

            if (!visited[current_vertex_id]) {
                queue.Add(current_vertex_id);
            }
        }
    }
}

template <class T>
inline bool GraphWithBFS<T>::IsConnected(unsigned int origin,
                                         unsigned int target) {
    std::vector<bool> visited(this->edges.Length(), false);

    this->Bfs(origin, visited);

    return visited[target];
}

template <class T> int GraphWithBFS<T>::ComponentsCount() {
    int counter = 0;

    std::vector<bool> visited(this->edges.Length(), false);

    for (int i = 0; i < (int)visited.size(); i++) {
        if (!visited[i]) {
            counter++;
            this->Bfs(i, visited);
        }
    }

    return counter;
}
