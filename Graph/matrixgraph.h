#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct node
{
    bool beenVisited;
    int id;
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

private:

    std::vector< std::vector< node > > vertexMatrix;
};

#endif // GRAPH_H
