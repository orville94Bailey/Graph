#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

struct matrixNode
{
    bool beenVisited;
    int data;
};

class MatrixGraph
{
public:

    MatrixGraph();
    ~MatrixGraph();

    void addVertex(int);
    void addEdge(int, int);
    void addEdgeDirected(int, int);
    void removeEdge(int, int);
    void removeVertex(int);

    void printDepthFirst(int);
    void printBreadthFirst(int);

    bool findVertex(int);

    void printMatrix();

private:

    void traverseDepthFirst(int vertexIndex, bool printFlag);
    void traverseBreadthFirst(int vertexIndex, bool printFlag, std::vector< int > *visitList);

    std::vector< std::vector< bool > > adjacencyMatrix;
    std::vector< matrixNode > vertexList;
};

#endif // GRAPH_H
