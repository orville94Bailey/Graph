#include "matrixgraph.h"
#include "listgraph.h"
#include <iostream>
#include <string>

int main()
{
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
    test.addVertex(11);
    test.addVertex(12);
    test.addEdge(1,2,1);
    test.addEdge(1,3,1);
    test.addEdge(2,4,1);
    test.addEdge(2,5,1);
    test.addEdge(3,6,1);
    test.addEdge(3,7,1);
    test.addEdge(2,8,1);
    test.addEdge(3,9,1);
    test.addEdge(4,10,1);
    test.addEdge(4,11,1);
    test.addEdge(4,12,1);

    test.printBreadthFirst(0);

    std::cout << std::endl;

    //test.printMatrix();

    test.removeEdge(2,4);

    std::cout << std::endl;

    //test.printMatrix();

    std::cout << std::endl;

    test.printDepthFirst(0);

    return 0;
}
