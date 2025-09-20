#include "Graph.h"
#include "../Hashmap/Hashmap.h"
#include "../LinkedQueue/LinkedQueue.h"
#include "../ArrayList/ArrayList.h"

template <class T>
GraphBase<T>::GraphBase()
{
    std::cout << "Teste" << std::endl;
    // this->edges = ArrayList<ArrayList<GraphNode> *>();
    std::cout << "Teste" << this->edges.Length() << std::endl;
}

template <class T>
GraphBase<T>::~GraphBase()
{
    for (int i = 0; i < edges.Length(); ++i)
        delete this->edges.At(i);

}

template <class T>
unsigned int GraphBase<T>::AddVertex(T content)
{
    auto empty = new ArrayList<GraphNode>();
    this->edges.Push(empty);

    auto node_id = this->edges.Length() - 1;
    if (node_id < 0)
        throw std::runtime_error("Node id value is not expected");

    this->content_table.Put(node_id, content);

    return (unsigned int)node_id;
}

template <class T>
void GraphBase<T>::AddEdge(unsigned int from, unsigned int to, float weight)
{
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    this->AddDirectionalEdge(from, to);

    if (from == to)
        return;

    this->AddDirectionalEdge(to, from);
}

template <class T>
void GraphBase<T>::AddDirectionalEdge(unsigned int from, unsigned int to, float weight)
{
    if (from >= this->edges.Length() || to >= this->edges.Length())
        throw std::runtime_error("edges not found");

    auto connected_vertices = this->edges.At(from);

    for (int i = 0; i < connected_vertices->Length(); i++)
        if (connected_vertices->At(i).id == to)
            throw std::runtime_error("edges already connected");

    GraphNode to_node = {
        .weight = weight,
        .id = (int)to,
    };

    this->edges.At(from)->Push(to_node);
}

template <class T>
T GraphBase<T>::GetVertexContent(unsigned int vertex_id)
{
    Option<T> value = this->content_table.Get(vertex_id);

    if (value.IsNone())
        throw std::runtime_error("Vertex not found");

    return value.Unwrap();
}

template <class T>
void GraphBase<T>::PrintGraph()
{
    auto t = this->edges.At(0);

    for (int i = 0; i < this->edges.Length(); i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < this->edges.At(i)->Length(); j++)
        {
            std::cout << this->edges.At(i)->At(j).id << " ";
        }
        std::cout << "\n";
    }
}

template <class T>
bool GraphWithDFS<T>::IsConnected(unsigned int origin, unsigned int target)
{
    return false;
}

template <class T>
inline bool GraphWithBFS<T>::IsConnected(unsigned int origin, unsigned int target)
{
    ArrayList<bool> visited;
    LinkedQueue<int> queue;

    queue.Add(origin);
    return false;
}

// #endif // GRAPH_CPP_INCLUDED
