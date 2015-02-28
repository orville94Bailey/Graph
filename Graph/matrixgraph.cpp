#include "matrixgraph.h"

MatrixGraph::MatrixGraph()
{
    currentNode.data=0;
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

        std::vector< int > newRow;

        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            adjacencyMatrix.at(i).push_back(0);
            newRow.push_back(0);
        }

        newRow.push_back(0);

        adjacencyMatrix.push_back(newRow);
    }
}

void MatrixGraph::addEdge(int firstValue, int secondValue, int weight)
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
        adjacencyMatrix.at(firstIndex).at(secondIndex) = weight;
        adjacencyMatrix.at(secondIndex).at(firstIndex) = weight;
    }
}

void MatrixGraph::addEdgeDirected(int firstValue, int secondValue, int weight)
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
        adjacencyMatrix.at(firstIndex).at(secondIndex) = weight;
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
        adjacencyMatrix.at(firstIndex).at(secondIndex) = 0;
        adjacencyMatrix.at(secondIndex).at(firstIndex) = 0;
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
        if(adjacencyMatrix.at(vertexIndex).at(i) >= 1 && vertexList.at(i).beenVisited == false)
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
            if(adjacencyMatrix.at(vertexIndex).at(i) >= 0 && vertexList.at(i).beenVisited == false)
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

std::vector<int> MatrixGraph::findDijkstraPath(int startValue, int endValue)
{
    int startIndex = -1;
    int endIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == startValue)
        {
            startIndex = i;
        }
        else if(vertexList.at(i).data == endValue)
        {
            endIndex = i;
        }
    }

    if(startIndex >= 0 && endIndex >= 0)
    {
        std::vector<int> prevIndexes;
        std::vector<int> currentWeights;

        for(int i = 0; i < vertexList.size(); i++)
        {
            vertexList.at(i).beenVisited = false;
            prevIndexes.push_back(-1);
            currentWeights.push_back(-1);
        }

        std::vector<int> connectedIndexes;
        connectedIndexes.push_back(startIndex);
        vertexList.at(startIndex).beenVisited = true;

        while(true)
        {
            unsigned int smallestWeight = -1;
            int smallestIndex = -1;
            int smallStartIndex = -1;

            for(int i = 0; i < connectedIndexes.size(); i++)
            {
                for(int j = 0; j < adjacencyMatrix.size(); j++)
                {
                    int checkWeight = adjacencyMatrix.at(connectedIndexes.at(i)).at(j);

                    if(checkWeight > 0 && checkWeight <= smallestWeight && vertexList.at(j).beenVisited == false)
                    {
                        smallestWeight = checkWeight;
                        smallestIndex = j;
                        smallStartIndex = connectedIndexes.at(i);
                    }
                }
            }

            if(smallestIndex == -1)
            {
                std::vector<int> path;
                path.push_back(-1);

                return path;
            }

            prevIndexes.at(smallestIndex) = smallStartIndex;
            connectedIndexes.push_back(smallestIndex);
            currentWeights.at(smallestIndex) = currentWeights.at(smallStartIndex) + smallestWeight;
            vertexList.at(smallestIndex).beenVisited = true;

            if(smallestIndex == endIndex)
            {
                std::vector<int> path;
                path.push_back(vertexList.at(endIndex).data);

                int prevIndex = prevIndexes.at(endIndex);
                while(prevIndex != startIndex)
                {
                    path.insert(path.begin(),vertexList.at(prevIndex).data);
                    prevIndex = prevIndexes.at(prevIndex);
                }

                path.insert(path.begin(),vertexList.at(startIndex).data);
                return path;
            }
        }
    }
}

std::vector<int> MatrixGraph::findPrimPath(int startValue, int endValue)
{
    int startIndex = -1;
    int endIndex = -1;

    for(int i = 0; i < vertexList.size(); i++)
    {
        if(vertexList.at(i).data == startValue)
        {
            startIndex = i;
        }
        else if(vertexList.at(i).data == endValue)
        {
            endIndex = i;
        }
    }

    if(startIndex >= 0 && endIndex >= 0)
    {
        for(int i = 0; i < vertexList.size(); i++)
        {
            vertexList.at(i).beenVisited = false;
        }

        std::vector<std::vector<int> > connectedPairs;
        std::vector<int> pairVector;
        pairVector.push_back(0);

        unsigned int smallestWeight = -1;
        int smallestIndex = -1;
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            int checkWeight = adjacencyMatrix.at(0).at(i);
            if(checkWeight <= smallestWeight && checkWeight > 0)
            {
                smallestWeight = checkWeight;
                smallestIndex = i;
            }
        }

        if(smallestIndex == -1)
        {
            std::vector<int> path;
            path.push_back(-1);
            return path;
        }

        pairVector.push_back(smallestIndex);

        connectedPairs.push_back(pairVector);
        vertexList.at(0).beenVisited = true;
        vertexList.at(smallestIndex).beenVisited = true;

        //Build a minimum weight spanning tree
        while(true)
        {
            smallestWeight = -1;
            smallestIndex = -1;
            int smallStartIndex = -1;

            for(int i = 0; i < connectedPairs.size(); i++)
            {
                for(int j = 0; j < adjacencyMatrix.size(); j++)
                {
                    int checkWeight = adjacencyMatrix.at(connectedPairs.at(i).at(0)).at(j);
                    if(checkWeight <= smallestWeight && checkWeight > 0 && vertexList.at(j).beenVisited == false)
                    {
                        smallestWeight = checkWeight;
                        smallestIndex = j;
                        smallStartIndex = connectedPairs.at(i).at(0);
                    }

                    checkWeight = adjacencyMatrix.at(connectedPairs.at(i).at(1)).at(j);
                    if(checkWeight <= smallestWeight && checkWeight > 0 && vertexList.at(j).beenVisited == false)
                    {
                        smallestWeight = checkWeight;
                        smallestIndex = j;
                        smallStartIndex = connectedPairs.at(i).at(1);
                    }
                }
            }

            if(smallestIndex != -1)
            {
                std::cout << connectedPairs.size() << std::endl;
                pairVector.clear();
                pairVector.push_back(smallStartIndex);
                pairVector.push_back(smallestIndex);

                connectedPairs.push_back(pairVector);
                vertexList.at(smallestIndex).beenVisited = true;
            }
            else
            {
                break;
            }
        }

        for(int i = 0; i < connectedPairs.size(); i++)
        {
            std::cout << connectedPairs.at(i).at(0) << "," << connectedPairs.at(i).at(1) << std::endl;
        }

        //Find the path from start to end
        std::vector<int> pathStack;
        pathStack.push_back(startIndex);

        while(true)
        {
            bool foundVertex = false;
            for(int i = 0; i < connectedPairs.size(); i++)
            {
                if(pathStack.at(pathStack.size()-1) == connectedPairs.at(i).at(0))
                {
                    if(pathStack.size() > 1)
                    {
                        if(connectedPairs.at(i).at(1) != pathStack.at(pathStack.size()-2))
                        {
                            pathStack.push_back(connectedPairs.at(i).at(1));
                            foundVertex = true;
                            break;
                        }
                    }
                    else
                    {
                        pathStack.push_back(connectedPairs.at(i).at(1));
                        foundVertex = true;
                        break;
                    }
                }

                if(pathStack.at(pathStack.size()-1) == connectedPairs.at(i).at(1))
                {
                    if(pathStack.size() > 1)
                    {
                        if(connectedPairs.at(i).at(0) != pathStack.at(pathStack.size()-2))
                        {
                            pathStack.push_back(connectedPairs.at(i).at(0));
                            foundVertex = true;
                            break;
                        }
                    }
                    else
                    {
                        pathStack.push_back(connectedPairs.at(i).at(0));
                        foundVertex = true;
                        break;
                    }
                }
            }

            if(!foundVertex)
            {
                pathStack.pop_back();
            }

            if(pathStack.at(pathStack.size()-1) == endIndex)
            {
                break;
            }
        }

        std::vector<int> path;
        while(pathStack.size() > 0)
        {
            path.insert(path.begin(),vertexList.at(pathStack.at(pathStack.size()-1)).data);
            pathStack.pop_back();
        }

        return path;
    }
}

//added by orville94bailey in order to construct a DFA checker

void MatrixGraph::transverseInput(matrixNode transversal_start_vertex, char input)
{

}

int MatrixGraph::getCurrentState()
{
    return currentNode.data;
}
