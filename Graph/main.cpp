#include "matrixgraph.h"
#include "listgraph.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    MatrixGraph test;
    test.addVertex(1);
    test.addVertex(2);
    test.addVertex(3);
    test.addVertex(4);
    test.addVertex(5);
    test.addVertex(6);
    test.addVertex(7);
    test.addVertex(8);
    test.addVertex(9);
    test.addVertex(10);

    test.addEdge(1,2,rand() % 20);
    test.addEdge(1,3,rand() % 20);
    test.addEdge(1,4,rand() % 20);
    test.addEdge(2,5,rand() % 20);
    test.addEdge(3,7,rand() % 20);
    test.addEdge(4,5,rand() % 20);
    test.addEdge(7,6,rand() % 20);
    test.addEdge(5,6,rand() % 20);
    test.addEdge(5,8,rand() % 20);
    test.addEdge(6,8,rand() % 20);
    test.addEdge(6,10,rand() % 20);
    test.addEdge(6,9,rand() % 20);
    test.addEdge(9,10,rand() % 20);
    test.addEdge(8,10,rand() % 20);

    std::cout << "Breadth first: " << std::endl;
    test.printBreadthFirst(0);

    std::cout << std::endl;

    std::cout << "Depth first:" << std::endl;
    test.printDepthFirst(0);

    std::cout << std::endl;
    std::vector<int> dijkstraPath = test.findDijkstraPath(8,2);

    std::cout << "Dijkstra path from " << 8 << " to " << 2 << ":" << std::endl;
    for(int i = 0; i < dijkstraPath.size(); i++)
    {
        std::cout << dijkstraPath.at(i) << std::endl;
    }

    return 0;
}
