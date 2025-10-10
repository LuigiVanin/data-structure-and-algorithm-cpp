#include "Graph.h"
#include "../ArrayList/ArrayList.h"
#include "../Hashmap/Hashmap.h"
#include "../LinkedQueue/LinkedQueue.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

template <class T> GraphBase<T>::GraphBase() {
    std::cout << "Teste" << std::endl;
    // this->edges = ArrayList<ArrayList<GraphNode> *>();
    std::cout << "Teste" << this->edges.Length() << std::endl;
}

template <class T> GraphBase<T>::~GraphBase() {
    for (int i = 0; i < edges.Length(); ++i) delete this->edges.At(i);
}

template <class T> uint GraphBase<T>::AddVertex(T content) {
    auto empty = new ArrayList<GraphNode>();
    this->edges.Push(empty);

    auto node_id = this->edges.Length() - 1;
    if (node_id < 0) throw std::runtime_error("Node id value is not expected");

    this->content_table.Put(node_id, content);

    return (uint)node_id;
}

template <class T>
void GraphBase<T>::AddEdge(uint from, uint to, float weight) {
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    this->AddDirectionalEdge(from, to, weight);

    if (from == to) return;

    this->AddDirectionalEdge(to, from, weight);
}

template <class T>
void GraphBase<T>::AddDirectionalEdge(uint from, uint to, float weight) {
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    auto connected_vertices = this->edges.At(from);

    for (int i = 0; i < connected_vertices->Length(); i++)
        if (connected_vertices->At(i).id == to)
            throw std::runtime_error("edges already connected");

    GraphNode to_node = {
        .weight = weight,
        .id     = to,
    };

    this->edges.At(from)->Push(to_node);
}

template <class T> //
T GraphBase<T>::GetVertex(uint vertex_id) {
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
std::vector<float> GraphBase<T>::Dijkstra(uint src) {
    if (src >= this->edges.Length()) {
        throw std::runtime_error("Invalid source or target vertex");
    }

    std::vector<bool>  visited(this->edges.Length(), false);
    std::vector<float> distances(this->edges.Length(), MAXFLOAT);

    distances[src] = 0;

    for (int _ = 0; _ < this->edges.Length(); _++) {

        float min_dist   = MAXFLOAT;
        int   current_id = -1;

        for (int j = 0; j < this->edges.Length(); j++)
            if (!visited[j] && (distances[j] < min_dist)) {
                min_dist   = distances[j];
                current_id = j;
            }

        if (current_id == -1) break;

        visited[current_id] = true;
        auto current_node   = this->edges.At(current_id);

        for (int j = 0; j < current_node->Length(); j++) {
            GraphNode neighbor_node = current_node->At(j);
            auto      weight        = neighbor_node.weight;
            auto      acc_distance  = distances[current_id] + weight;

            if (acc_distance < distances[neighbor_node.id]) {
                distances[neighbor_node.id] = acc_distance;
            }
        }
    }

    return distances;
}

template <class T> //
std::vector<uint> GraphBase<T>::DijkstraPath(uint src, uint target) {
    if (src >= this->edges.Length() || target >= this->edges.Length()) {
        throw std::runtime_error("Invalid source or target vertex");
    }

    std::vector<bool>  visited(this->edges.Length(), false);
    std::vector<float> distances(this->edges.Length(), MAXFLOAT);
    std::vector<int>   predecessors(this->edges.Length(), -1);

    distances[src] = 0;

    for (int _ = 0; _ < this->edges.Length(); _++) {

        float min_dist   = MAXFLOAT;
        int   current_id = -1;

        // This section tries to  find the minimun disrtance vertex between the
        // unvisited neighbor vertices
        for (int j = 0; j < this->edges.Length(); j++)
            if (!visited[j] && (distances[j] < min_dist)) {
                min_dist   = distances[j];
                current_id = j;
            }

        if (current_id == -1) break;

        visited[current_id] = true;
        auto current_node   = this->edges.At(current_id);

        for (int j = 0; j < current_node->Length(); j++) {
            GraphNode neighbor_node = current_node->At(j);
            auto      weight        = neighbor_node.weight;
            auto      acc_distance  = distances[current_id] + weight;

            if (acc_distance < distances[neighbor_node.id]) {
                distances[neighbor_node.id]    = acc_distance;
                predecessors[neighbor_node.id] = current_id;
            }
        }
    }

    std::vector<uint> path;
    int               current = predecessors[target];

    if (current != -1) path.push_back(target);

    while (current != -1) {
        path.push_back(current);
        current = predecessors[current];
    }

    std::reverse(path.begin(), path.end());

    return path;
}

template <class T>
void GraphWithDFS<T>::Dfs(uint origin, std::vector<bool> &visited) {
    if (!visited[origin]) visited[origin] = true;

    ArrayList<GraphNode> *current_edge = this->edges.At(origin);

    for (int i = 0; i < current_edge->Length(); i++) {
        auto current_vertex_id = current_edge->At(i).id;
        if (!visited[current_vertex_id]) this->Dfs(current_vertex_id, visited);
    }
}

template <class T> bool GraphWithDFS<T>::IsConnected(uint origin, uint target) {
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
void GraphWithBFS<T>::Bfs(uint origin, std::vector<bool> &visited) {
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
inline bool GraphWithBFS<T>::IsConnected(uint origin, uint target) {
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
