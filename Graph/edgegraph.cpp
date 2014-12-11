#include "edgegraph.h"

EdgeGraph::EdgeGraph()
{

}

EdgeGraph::~EdgeGraph()
{

}

void EdgeGraph::addVertex(int newData)
{
    if(findVertex(newData) < 0)
    {
        vertex newVertex;
        newVertex.data = newData;
        newVertex.beenVisited = false;
        vertices.push_back(newVertex);
    }
}

void EdgeGraph::addEdge(int firstValue, int secondValue, int weight)
{
    int firstIndex = findVertex(firstValue);
    int secondIndex = findVertex(secondValue);

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        edge newEdge;

        newEdge.startIndex = firstIndex;
        newEdge.endIndex = secondIndex;
        newEdge.directed = false;
        newEdge.weight = weight;

        edges.push_back(newEdge);
    }
}

void EdgeGraph::addEdgeDirected(int firstValue, int secondValue, int weight)
{
    int firstIndex = findVertex(firstValue);
    int secondIndex = findVertex(secondValue);

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        edge newEdge;

        newEdge.startIndex = firstIndex;
        newEdge.endIndex = secondIndex;
        newEdge.directed = true;
        newEdge.weight = weight;

        edges.push_back(newEdge);
    }
}

void EdgeGraph::removeEdge(int firstValue, int secondValue)
{
    int firstIndex = findVertex(firstValue);
    int secondIndex = findVertex(secondValue);

    if(firstIndex >= 0 && secondIndex >= 0)
    {
        for(int i = 0; i < edges.size(); i++)
        {
            if((edges.at(i).startIndex == firstIndex && edges.at(i).endIndex == secondIndex)
               || (edges.at(i).startIndex == secondIndex && edges.at(i).endIndex == firstIndex))
            {
                edges.erase(edges.begin()+i);
                break;
            }
        }
    }
}

void EdgeGraph::removeVertex(int removeData)
{
    int removeIndex = findVertex(removeData);

    if(removeIndex >= 0)
    {
        for(int i = 0; i < edges.size(); i++)
        {
            if(edges.at(i).startIndex == removeIndex || edges.at(i).endIndex == removeIndex)
            {
                edges.erase(edges.begin()+i);
                i--;
            }
        }

        vertices.erase(vertices.begin()+removeIndex);
    }
}

int EdgeGraph::findVertex(int searchData)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices.at(i).data == searchData)
        {
            return i;
        }
    }

    return -1;
}
