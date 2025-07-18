#ifndef GRAPH_H
#define GRAPH_H

#pragma once

#include "../ArrayList/ArrayList.h"
#include "../Hashmap/Hashmap.h"

template <class T>
class GraphBase
{
private:
    unsigned int amount = 0;
    ArrayList<ArrayList<int>> verteces;
    Hashmap<int, T> content_table;

public:
    GraphBase();
    ~GraphBase();

    unsigned int AddVertex(T content);
    void AddDirectionalEdge(unsigned int from, unsigned int to, int weight = 1); // from -> to

    void AddEdge(unsigned int from, unsigned int to, int weight = 1); // from -> to
                                                                      // to -> from

    T GetVertexContent(unsigned int vertex_id);
};

class IGraph
{
public:
    virtual bool IsConnected(unsigned int origin, unsigned int target) {}
};

template <class T>
class GraphWithBFS : GraphBase<T>, IGraph
{
};

template <class T>
class GraphWithDFS : GraphBase<T>, IGraph
{
};

#include "Graph.cpp"
#endif