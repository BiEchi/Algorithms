//
//  Graph.cpp
//  Workspace
//
//  Created by Jack's Macbook Pro on 2021/5/1.
//

#include "Graph.hpp"

/// Constructor of class Graph
/// @param vertexNumber the number of vertices in the graph
Graph::Graph(int vertexNumber)
{
    this->vertexNumber = vertexNumber; // link on link 链上链
    arrayOfAdjacencyLists = new list<int>[vertexNumber];
}

/// Perform DFS recursively to print SCC
/// @param vertexID the ID of the vertex
/// @param visited the array showing whether this vertex has been visited
void Graph::DFSUtil(int vertexID, bool* visited)
{
    // mark and print the visited vertex
    visited[vertexID] = true;
    cout << vertexID << " ";
    
    // recurse for all the vertices adjacent to this vertex
    for (auto i = arrayOfAdjacencyLists[vertexID].begin();
         i != arrayOfAdjacencyLists[vertexID].end(); i++)
        if (!visited[*i]) // must only detect unvisited vertices
            DFSUtil(*i, visited);
    
    return;
}

/// get the transpose of the original graph
Graph Graph::getTranspose()
{
    Graph transposedGraph(vertexNumber);
    for (int vertexID = 0; vertexID < vertexNumber; vertexID++) {
        list<int>::iterator i;
        for (i = arrayOfAdjacencyLists[vertexID].begin();
             i != arrayOfAdjacencyLists[vertexID].end(); i++)
            transposedGraph.arrayOfAdjacencyLists[*i].push_back(vertexID);
    }
    
    // return the entity with the object announced in the memory
    return transposedGraph;
}

/// add one edge into the graph
/// @param vertex1ID the vertex ID you want to add the edge on
/// @param vertex2ID the vertex ID you want to add the edge to
void Graph::addEdge(int vertex1ID, int vertex2ID)
{
    arrayOfAdjacencyLists[vertex1ID].push_back(vertex2ID);
    
    return;
}

/// fill vertices in stack according to their finishing times
/// @param vertexID the ID of the vertex
/// @param visited the array to mark whether the vertex is already visited
/// @param Stack record the finishing times of each vertex
void Graph::fillOrder(int vertexID, bool *visited, stack<int> &Stack)
{
    visited[vertexID] = true;
    
    list<int>::iterator i;
    for (i = arrayOfAdjacencyLists[vertexID].begin();
         i != arrayOfAdjacencyLists[vertexID].end(); i++)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);
    // post-order recursion 后序递归
    Stack.push(vertexID);
    
    return;
}
