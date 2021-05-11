//
//  GraphStructure.hpp
//  Workspace
//
//  Created by Jack's Macbook Pro on 2021/5/11.
//

#ifndef GraphStructure_hpp
#define GraphStructure_hpp

#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int destinationVertex;
    int flow;
    int capacity;
    int indexOfReverseEdgeInAdjacencyList;
};

class ResidualGraph
{
private:
    int numberOfVertex;
    int* levelOfNode;
    vector<Edge>* adjacencyList;
public:
    ResidualGraph(int numberOfVertex)
    {
        adjacencyList = new vector<Edge>[numberOfVertex];
        this->numberOfVertex = numberOfVertex;
        levelOfNode = new int[numberOfVertex];
    }
    
    void addEdge(int u, int v, int capaticy)
    {
        Edge a{v, 0, capaticy, (int)adjacencyList[v].size()}; // forward edge
        Edge b{u, 0, 0, (int)adjacencyList[u].size()}; // back edge
        adjacencyList[u].push_back(a);
        adjacencyList[v].push_back(b); // reverse edge
    }
    
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicsAlgorithm(int s, int t);
};

#endif /* GraphStructure_hpp */
