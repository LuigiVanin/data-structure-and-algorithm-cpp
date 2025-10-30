#ifndef GRAPH_H
#define GRAPH_H

#include <sys/types.h>
#pragma once

#include "../ArrayList/ArrayList.h"
#include "../Hashmap/Hashmap.h"
#include <vector>

struct GraphNode {
    float weight;
    uint  id;
};

template <class T>
class GraphBase {
        private:
    uint amount = 0;

        public:
    ArrayList<ArrayList<GraphNode> *> edges;
    Hashmap<int, T>                   content_table;

    GraphBase();
    ~GraphBase();

    uint AddVertex(T content);
    void AddDirectionalEdge(uint from, uint to,
                            float = 1.0); // from -> to

    void AddEdge(uint from, uint to,
                 float weight = 1); // from -> to
    // to -> from

    T GetVertex(uint vertex_id);

    std::vector<float> Dijkstra(uint src);
    std::vector<uint>  DijkstraPath(uint src, uint target);

    void PrintGraph();
};

class IGraph {
        public:
    virtual ~IGraph()                                  = default;
    virtual bool IsConnected(uint origin, uint target) = 0;
    virtual int  ComponentsCount()                     = 0;
};

template <class T>
class GraphWithBFS : public GraphBase<T>, public IGraph {
        public:
    void Bfs(uint origin, std::vector<bool> &visited);

    bool IsConnected(uint origin, uint target) override;
    int  ComponentsCount() override;
};

template <class T>
class GraphWithDFS : public GraphBase<T>, public IGraph {
        public:
    void Dfs(uint origin, std::vector<bool> &visited);

    bool IsConnected(uint origin, uint target) override;
    int  ComponentsCount() override;
};

#include "Graph.cpp"
#endif
