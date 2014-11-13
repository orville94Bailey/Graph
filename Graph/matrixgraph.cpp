#include "matrixgraph.h"

MatrixGraph::MatrixGraph()
{

}

MatrixGraph::~MatrixGraph()
{

}

void MatrixGraph::addVertex(int newData)
{
    if(!findVertex(newData))
    {
        matrixNode newNode;
        newNode.data = newData;
        newNode.beenVisited = false;

        vertexList.push_back(newNode);

        std::vector< bool > newRow;

        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            adjacencyMatrix.at(i).push_back(false);
            newRow.push_back(false);
        }

        newRow.push_back(false);

        adjacencyMatrix.push_back(newRow);
    }
}

void MatrixGraph::addEdge(int firstValue, int secondValue)
{
    int firstIndex = -1;
    int secondIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == firstValue)
        {
            firstIndex = i;
        }
        else if(vertexList.at(i).data == secondValue)
        {
            secondIndex = i;
        }
    }

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        adjacencyMatrix.at(firstIndex).at(secondIndex) = true;
        adjacencyMatrix.at(secondIndex).at(firstIndex) = true;
    }
}

void MatrixGraph::addEdgeDirected(int firstValue, int secondValue)
{
    int firstIndex = -1;
    int secondIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == firstValue)
        {
            firstIndex = i;
        }
        else if(vertexList.at(i).data == secondValue)
        {
            secondIndex = i;
        }
    }

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        adjacencyMatrix.at(firstIndex).at(secondIndex) = true;
    }
}

void MatrixGraph::removeEdge(int firstValue, int secondValue)
{
    int firstIndex = -1;
    int secondIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == firstValue)
        {
            firstIndex = i;
        }
        else if(vertexList.at(i).data == secondValue)
        {
            secondIndex = i;
        }
    }

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        adjacencyMatrix.at(firstIndex).at(secondIndex) = false;
        adjacencyMatrix.at(secondIndex).at(firstIndex) = false;
    }
}

void MatrixGraph::removeVertex(int removeData)
{
    int removeIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == removeData)
        {
            removeIndex = i;
        }
    }

    vertexList.erase(vertexList.begin()+removeIndex);

    if(removeIndex >= 0)
    {
        adjacencyMatrix.erase(adjacencyMatrix.begin()+removeIndex);
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            adjacencyMatrix.at(i).erase(adjacencyMatrix.at(i).begin()+removeIndex);
        }
    }
}

void MatrixGraph::printDepthFirst(int startIndex)
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        vertexList.at(i).beenVisited = false;
    }

    traverseDepthFirst(startIndex,true);
}

void MatrixGraph::traverseDepthFirst(int vertexIndex, bool printFlag)
{
    if(printFlag)
    {
        std::cout << vertexList.at(vertexIndex).data << std::endl;
    }

    vertexList.at(vertexIndex).beenVisited = true;

    for(int i = 0; i < adjacencyMatrix.at(vertexIndex).size(); i++)
    {
        if(adjacencyMatrix.at(vertexIndex).at(i) == true && vertexList.at(i).beenVisited == false)
        {
            traverseDepthFirst(i,printFlag);
        }
    }
}

void MatrixGraph::printBreadthFirst(int startIndex)
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        vertexList.at(i).beenVisited = false;
    }

    traverseBreadthFirst(startIndex,true,new std::vector<int>());
}

void MatrixGraph::traverseBreadthFirst(int vertexIndex, bool printFlag, std::vector<int> *visitList)
{
    if(printFlag)
    {
        std::cout << vertexList.at(vertexIndex).data << std::endl;
    }

    vertexList.at(vertexIndex).beenVisited = true;
    visitList->push_back(vertexIndex);

    while(visitList->size() > 0)
    {
        vertexIndex = visitList->at(0);
        visitList->erase(visitList->begin());

        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            if(adjacencyMatrix.at(vertexIndex).at(i) == true && vertexList.at(i).beenVisited == false)
            {
                if(printFlag)
                {
                    std::cout << vertexList.at(i).data << std::endl;
                }

                vertexList.at(i).beenVisited = true;
                visitList->push_back(i);
            }
        }
    }
}

bool MatrixGraph::findVertex(int searchData)
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == searchData)
        {
            return true;
        }
    }
    return false;
}

void MatrixGraph::printMatrix()
{
    for(int i = 0; i < adjacencyMatrix.size();i++)
    {
        for(int j = 0; j < adjacencyMatrix.at(i).size(); j++)
        {
            std::cout << adjacencyMatrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}
