#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <vector>
#include <iostream>

struct listNode
{
    int data;
    bool beenVisited;


};

class ListGraph
{
public:

    ListGraph();
    ~ListGraph();

    void addVertex(int);
    void addEdge(int, int);
    void addEdgeDirected(int, int);
    void removeEdge(int, int);
    void removeVertex(int);

    void printDepthFirst(int);
    void printBreadthFirst(int);

    bool findVertex(int);

private:

    void traverseDepthFirst(int vertexIndex, bool printFlag);
    void traverseBreadthFirst(int vertexIndex, bool printFlag, std::vector< int > *visitList);

    std::vector< std::vector<int> > adjacencyList;
    std::vector< listNode > vertexList;
};

#endif // LISTGRAPH_H
