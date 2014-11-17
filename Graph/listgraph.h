#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <vector>
#include <iostream>

struct listNode
{
    int data;
    bool beenVisited;
};

struct listEdge
{
    int endIndex;
    int weight;
};

class ListGraph
{
public:

    ListGraph();
    ~ListGraph();

    void addVertex(int newData);
    void addEdge(int firstValue, int secondValue, int weight);
    void addEdgeDirected(int firstValue, int secondValue, int weight);
    void removeEdge(int firstValue, int secondValue);
    void removeVertex(int removeData);

    void printDepthFirst(int startIndex);
    void printBreadthFirst(int startIndex);

    bool findVertex(int searchData);

    //These methods return a vector containing a sequence of indexes which detail a path from
    //the vertex containing startValue to the vertex containing endValue
    std::vector<int> findDijkstraPath(int startValue, int endValue);
    std::vector<int> findPrimPath(int startValue, int endValue);
    std::vector<int> findKruskalPath(int startValue, int endValue);

private:

    void traverseDepthFirst(int vertexIndex, bool printFlag);
    void traverseBreadthFirst(int vertexIndex, bool printFlag, std::vector< int > *visitList);

    std::vector< std::vector<listEdge> > adjacencyList;
    std::vector< listNode > vertexList;
};

#endif // LISTGRAPH_H
