#ifndef GRAPH_H
#define GRAPH_H

#pragma once

#include "../ArrayList/ArrayList.h"
#include "../Hashmap/Hashmap.h"

struct GraphNode
{
    float weight;
    int id;
};

template <class T>
class GraphBase
{
private:
    unsigned int amount = 0;

public:
    ArrayList<ArrayList<GraphNode> *> edges;
    Hashmap<int, T> content_table;
    GraphBase();
    ~GraphBase();

    unsigned int AddVertex(T content);
    void AddDirectionalEdge(unsigned int from, unsigned int to, float = 1.0); // from -> to

    void AddEdge(unsigned int from, unsigned int to, float weight = 1); // from -> to
    // to -> from

    T GetVertexContent(unsigned int vertex_id);

    void PrintGraph();
};

class IGraph
{
public:
    virtual bool IsConnected(unsigned int origin, unsigned int target) = 0;
};

template <class T>
class GraphWithBFS : public GraphBase<T>, public IGraph
{
public:
    bool IsConnected(unsigned int origin, unsigned int target) override;
};

template <class T>
class GraphWithDFS : GraphBase<T>, IGraph
{
public:
    bool IsConnected(unsigned int origin, unsigned int target) override;
};

#include "Graph.cpp"
#endif
