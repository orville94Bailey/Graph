#ifndef EDGEGRAPH_H
#define EDGEGRAPH_H

#include <vector>
#include <iostream>

struct vertex
{
    int data;
    bool beenVisited;
};

struct edge
{
    int startIndex;
    int endIndex;
    int weight;
    bool directed;
};

class EdgeGraph
{
public:

    EdgeGraph();
    ~EdgeGraph();

    void addVertex(int newData);
    void addEdge(int firstValue, int secondValue, int weight);
    void addEdgeDirected(int firstValue, int secondValue, int weight);
    void removeEdge(int firstValue, int secondValue);
    void removeVertex(int removeData);

    int findVertex(int searchData);

    //These methods return a vector containing a sequence of indexes which detail a path from
    //the vertex containing startValue to the vertex containing endValue
    std::vector<int> findDijkstraPath(int startValue, int endValue);
    std::vector<int> findPrimPath(int startValue, int endValue);
    std::vector<int> findKruskalPath(int startValue, int endValue);

private:

    std::vector<edge> edges;
    std::vector<vertex> vertices;
};

#endif // EDGEGRAPH_H

