#include "listgraph.h"

ListGraph::ListGraph()
{

}

ListGraph::~ListGraph()
{

}

void ListGraph::addVertex(int newData)
{
    if(!findVertex(newData))
    {
        listNode newNode;

        newNode.beenVisited = false;
        newNode.data = newData;

        vertexList.push_back(newNode);

        std::vector<int> newList;

        adjacencyList.push_back(newList);
    }
}

void ListGraph::addEdge(int firstValue, int secondValue)
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
        adjacencyList.at(firstIndex).push_back(secondIndex);
        adjacencyList.at(secondIndex).push_back(firstIndex);
    }
}

void ListGraph::addEdgeDirected(int firstValue, int secondValue)
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
        adjacencyList.at(firstIndex).push_back(secondIndex);
    }
}

void ListGraph::removeEdge(int firstValue, int secondValue)
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
        for(int i = 0; i < adjacencyList.at(firstIndex).size(); i++)
        {
            if(adjacencyList.at(firstIndex).at(i) == secondIndex)
            {
                adjacencyList.at(firstIndex).erase(adjacencyList.at(firstIndex).begin()+i);
            }
        }

        for(int i = 0; i < adjacencyList.at(secondIndex).size(); i++)
        {
            if(adjacencyList.at(secondIndex).at(i) == firstIndex)
            {
                adjacencyList.at(secondIndex).erase(adjacencyList.at(secondIndex).begin()+i);
            }
        }
    }
}

void ListGraph::removeVertex(int removeValue)
{
    int removeIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == removeValue)
        {
            removeIndex = i;
            break;
        }
    }

    if(removeIndex >= 0)
    {
        adjacencyList.erase(adjacencyList.begin()+removeIndex);
        for(int i = 0; i < adjacencyList.size(); i++)
        {
            for(int j = 0; j < adjacencyList.at(i).size(); j++)
            {
                if(adjacencyList.at(i).at(j) == removeIndex)
                {
                    adjacencyList.at(i).erase(adjacencyList.at(i).begin()+j);
                }
            }
        }
    }
}

void ListGraph::printDepthFirst(int startIndex)
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        vertexList.at(i).beenVisited = false;
    }

    traverseDepthFirst(startIndex,true);
}

void ListGraph::traverseDepthFirst(int vertexIndex, bool printFlag)
{
    if(printFlag)
    {
        std::cout << vertexList.at(vertexIndex).data << std::endl;
    }

    vertexList.at(vertexIndex).beenVisited = true;

    for(int i = 0; i < adjacencyList.at(vertexIndex).size(); i++)
    {
        if(vertexList.at(adjacencyList.at(vertexIndex).at(i)).beenVisited == false)
        {
            traverseDepthFirst(adjacencyList.at(vertexIndex).at(i),printFlag);
        }
    }
}

void ListGraph::printBreadthFirst(int startIndex)
{
    for(int i = 0; i < vertexList.size(); i++)
    {
        vertexList.at(i).beenVisited = false;
    }

    traverseBreadthFirst(startIndex,true,new std::vector<int>());
}

void ListGraph::traverseBreadthFirst(int vertexIndex, bool printFlag, std::vector<int> *visitList)
{
    if(printFlag)
    {
        std::cout << vertexList.at(vertexIndex).data << std::endl;
    }

    visitList->push_back(vertexIndex);
    vertexList.at(vertexIndex).beenVisited = true;

    while(visitList->size() > 0)
    {
        vertexIndex = visitList->at(0);
        visitList->erase(visitList->begin());

        for(int i = 0; i < adjacencyList.at(vertexIndex).size(); i++)
        {
            if(vertexList.at(adjacencyList.at(vertexIndex).at(i)).beenVisited == false)
            {
                if(printFlag)
                {
                    std::cout << vertexList.at(adjacencyList.at(vertexIndex).at(i)).data << std::endl;
                }

                vertexList.at(adjacencyList.at(vertexIndex).at(i)).beenVisited = true;
                visitList->push_back(adjacencyList.at(vertexIndex).at(i));
            }
        }
    }
}

bool ListGraph::findVertex(int searchData)
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
